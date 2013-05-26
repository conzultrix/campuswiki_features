<?php
/**
 * @file
 * campuswiki_gallery.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function campuswiki_gallery_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|album|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'album';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'album_info' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|album|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|album|user_gallery';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'album';
  $ds_fieldsetting->view_mode = 'user_gallery';
  $ds_fieldsetting->settings = array(
    'album_info' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|album|user_gallery'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function campuswiki_gallery_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'album_info';
  $ds_field->label = 'Album info';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['album_info'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function campuswiki_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|album|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'album';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'photo_gallery_entity_view_photo_gallery_cover',
        1 => 'album_info',
      ),
    ),
    'fields' => array(
      'photo_gallery_entity_view_photo_gallery_cover' => 'ds_content',
      'album_info' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|album|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|album|user_gallery';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'album';
  $ds_layout->view_mode = 'user_gallery';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'photo_gallery_entity_view_1',
        1 => 'album_info',
      ),
    ),
    'fields' => array(
      'photo_gallery_entity_view_1' => 'ds_content',
      'album_info' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|album|user_gallery'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function campuswiki_gallery_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_gallery';
  $ds_view_mode->label = 'User gallery';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['user_gallery'] = $ds_view_mode;

  return $export;
}
