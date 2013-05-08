<?php
/**
 * @file
 * campuswiki_groups.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function campuswiki_groups_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|small_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'small_teaser';
  $ds_fieldsetting->settings = array(
    'group_content_view' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|group|small_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'group_content_view' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|group|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function campuswiki_groups_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'group_content_view';
  $ds_field->label = 'Group content view';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['group_content_view'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function campuswiki_groups_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|small_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'small_teaser';
  $ds_layout->layout = 'ds_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'group_content_view',
      ),
      'left' => array(
        0 => 'field_group_photo',
      ),
    ),
    'fields' => array(
      'title' => 'middle',
      'group_content_view' => 'right',
      'field_group_photo' => 'left',
      'body' => 'middle',
    ),
    'classes' => array(),
  );
  $export['node|group|small_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_group_photo',
      ),
      'middle' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'group_content_view',
      ),
    ),
    'fields' => array(
      'field_group_photo' => 'left',
      'title' => 'middle',
      'body' => 'middle',
      'group_content_view' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|group|teaser'] = $ds_layout;

  return $export;
}
