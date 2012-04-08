<?php
/**
 * @file
 * campuswiki_departments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_departments_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "spaces" && $api == "spaces") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
