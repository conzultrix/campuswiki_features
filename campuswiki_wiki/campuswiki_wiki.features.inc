<?php
/**
 * @file
 * campuswiki_wiki.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_wiki_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function campuswiki_wiki_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function campuswiki_wiki_node_info() {
  $items = array(
    'wiki' => array(
      'name' => t('Wiki page'),
      'base' => 'node_content',
      'description' => t('A collaborative page that any authenticated user may edit and view changes. A Wiki page can be used for project report and research documentation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
