<?php

/**
 * @file
 * Drush wrapper around the PHP_CodeSniffer's Drupal Standard.
 */

require 'vendor/autoload.php';

/**
 * Implementation of hook_drush_command().
 */
function drupalcs_drush_command() {
  $items['code-sniff'] = array(
    'description' => 'Describey describey what.',
    'arguments' => array(
      'path' => 'Path to run CodeSniffer on.',
    ),
    'examples' => array(
      'drush code-sniff .' => 'Run codesniffer in current directory.',
    ),
    'aliases' => array('sniff', 'cs', 'lint'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Drush CodeSniff; Invokes the phpcs command for the Drupal Standard.
 */
function drush_drupalcs_code_sniff($path = '.') {
  $sniff = new PHP_CodeSniffer ();
  $drupal_extensions = array(
    'php',
    'module',
    'inc',
    'install',
    'test',
    'profile',
    'theme',
  );
  $sniff->setAllowedFileExtensions($drupal_extensions);
  $sniff->populateCustomRules(dirname(__FILE__) . '/Drupal/ruleset.xml');
  print_r ($sniff->getInstalledStandards());
  #print_r ($sniff->getSniffFiles(dirname(__FILE__) . '/Drupal'));
  $sniff->process('/mnt/www/html/condel/profiles/condel/modules/custom', 'PEAR');
  print_r($sniff->getSniffs());
  print_r ($sniff->getIgnorePatterns());
  print_r($sniff->getFilesErrors());
  if ($sniff->isInstalledStandard('Drupal')) {
    drush_print('Drupal Standard was found.');
  } else {
    drush_print('Nots found.');
  }
}
