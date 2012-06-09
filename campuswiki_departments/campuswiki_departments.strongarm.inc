<?php
/**
 * @file
 * campuswiki_departments.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function campuswiki_departments_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_term_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_term_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_campus_audience_pattern';
  $strongarm->value = '[term:name]';
  $export['pathauto_taxonomy_term_campus_audience_pattern'] = $strongarm;

  return $export;
}
