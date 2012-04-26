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
  $items['codesniff'] = array(
    'description' => 'Describey describey what.',
    'arguments' => array(
      'path' => 'Path to sniff.',
    ),
    'examples' => array(
      'drush codesniff .' => 'Run codesniffer in current dir.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}
