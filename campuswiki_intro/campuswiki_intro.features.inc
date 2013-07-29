<?php
/**
 * @file
 * campuswiki_intro.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_intro_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function campuswiki_intro_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function campuswiki_intro_node_info() {
  $items = array(
    'intro' => array(
      'name' => t('Intro'),
      'base' => 'node_content',
      'description' => t('Promotional content for CampusWiki'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
