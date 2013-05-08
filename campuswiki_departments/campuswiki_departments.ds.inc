<?php
/**
 * @file
 * campuswiki_departments.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function campuswiki_departments_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|campus_audience|term_teaser';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'campus_audience';
  $ds_fieldsetting->view_mode = 'term_teaser';
  $ds_fieldsetting->settings = array(
    'audience_formatted_text' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|campus_audience|term_teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function campuswiki_departments_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'audience_formatted_text';
  $ds_field->label = 'Audience formatted text';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->properties = array();
  $export['audience_formatted_text'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function campuswiki_departments_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|campus_audience|term_teaser';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'campus_audience';
  $ds_layout->view_mode = 'term_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_audience_image',
        1 => 'audience_formatted_text',
      ),
    ),
    'fields' => array(
      'field_audience_image' => 'ds_content',
      'audience_formatted_text' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|campus_audience|term_teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function campuswiki_departments_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'term_teaser';
  $ds_view_mode->label = 'Term teaser';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['term_teaser'] = $ds_view_mode;

  return $export;
}
