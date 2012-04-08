<?php
/**
 * @file
 * campuswiki_departments.spaces.inc
 */

/**
 * Implements hook_spaces_presets().
 */
function campuswiki_departments_spaces_presets() {
  $export = array();

  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'campuswiki_departments_basic';
  $spaces_presets->title = 'Departments basic config';
  $spaces_presets->description = 'Basic defaults for Departments and Faculties';
  $spaces_presets->space_type = 'taxonomy';
  $spaces_presets->value = '';

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic defaults for Departments and Faculties');
  t('Departments basic config');
  $export['campuswiki_departments_basic'] = $spaces_presets;

  return $export;
}
