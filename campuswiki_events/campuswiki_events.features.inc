<?php
/**
 * @file
 * campuswiki_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_events_ctools_plugin_api() {
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
function campuswiki_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function campuswiki_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An occasion that people can attend'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'rsvp' => array(
      'name' => t('RSVP'),
      'base' => 'node_content',
      'description' => t('A response to an event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
