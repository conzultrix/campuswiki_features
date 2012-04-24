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
  $strongarm->name = 'pathauto_taxonomy_term_campus_audience_pattern';
  $strongarm->value = '[term:name]';
  $export['pathauto_taxonomy_term_campus_audience_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_preset_taxonomy';
  $strongarm->value = 'campuswiki_departments_basic';
  $export['spaces_preset_taxonomy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_taxonomy_machine_name';
  $strongarm->value = 'campus_audience';
  $export['spaces_taxonomy_machine_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'space_type';
  $strongarm->value = 'og';
  $export['space_type'] = $strongarm;

  return $export;
}
