<?php

/**
 * @file
 * Drush wrapper around the PHP_CodeSniffer's Drupal Standard.
 */

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
      'drush code-sniff /path/to/sniff' => 'Run codesniffer in current directory.',
    ),
    'aliases' => array('sniff', 'cs', 'lint'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Drush CodeSniff; Invokes the phpcs command for the Drupal Standard.
 */
function drush_drupalcs_code_sniff($path = '') {
  $cmd = 'php ' . dirname(__FILE__) . '/vendor/squizlabs/PHP_CodeSniffer/scripts/phpcs ';
  $cmd .= '--standard=' . dirname(__FILE__) . '/Drupal ';
  $cmd .= '--extensions=php,module,inc,install,test,profile,theme ';
  $cmd .= $path;
  drush_shell_exec_interactive($cmd);
}
