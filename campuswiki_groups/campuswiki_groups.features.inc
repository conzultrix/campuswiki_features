<?php
/**
 * @file
 * campuswiki_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function campuswiki_groups_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A group for members to coordinate, collaborate and share ideas. It can be public or private'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
  );
  return $items;
}
