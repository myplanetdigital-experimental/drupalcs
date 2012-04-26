Drupal Code Sniffer
===================

Drupal Code Sniffer (drupalcs) is a coding standard validation tool for Drupal
and contributed modules/themes.

Requirements
------------
* PEAR [(Installation)][install-pear]
* PHP_CodeSniffer [(Installation)][install-phpcs]

Installation
------------
* Install required components.
* Symlink the drupalcs directory into the standards folder for PHP_CodeSniffer.
  The code for that looks like this:

  ```
  $ sudo ln -sv /path/to/drupalcs/Drupal $(pear config-get php_dir)/PHP/CodeSniffer/Standards 
  ```

Usage
-----
In a shell, run:

    $ phpcs --standard=Drupal --extensions=php,module,inc,install,test,profile,theme /path/to/drupal_module

Code Editor Tools
-----------------
Drupal Code Sniffer can be used with various editors.

### Editors:
* [eclipse](http://drupal.org/node/1420004)
* [Komodo](http://drupal.org/node/1419996)
* [Netbeans](http://drupal.org/node/1420008)
* [Sublime](Text: http://drupal.org/node/1419996)
* [vim](http://drupal.org/node/1419996)

Attention
---------
**This is still a draft!!**

Please cross-check with the official Drupal documentation:
* [General Coding Standards][gen-coding-stds]
* [Object-Oriented Coding Standard][oop-coding-stds]

[Coder module][coder-module] is currently the most authoritative source.

### Known Issues
* Documentation Tags just barely supported
* There are many missing/disabled sniffs

   [install-pear]:    http://pear.php.net/manual/en/installation.php
   [install-phpcs]:   http://pear.php.net/package/PHP_CodeSniffer
   [gen-coding-stds]: http://drupal.org/coding-standards
   [oop-coding-stds]: http://drupal.org/node/608152
   [coder-module]:    http://drupal.org/project/coder
