<?php
/**
 * @file
 * campuswiki_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function campuswiki_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'attendee_count' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attendee_images' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comment_count' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rsvp_badge' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|event|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function campuswiki_events_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'attendee_count';
  $ds_field->label = 'Attendee count';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['attendee_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'attendee_images';
  $ds_field->label = 'Attendee images';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['attendee_images'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'comment_count';
  $ds_field->label = 'Comment count';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['comment_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rsvp_badge';
  $ds_field->label = 'RSVP badge';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['rsvp_badge'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function campuswiki_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'field_venue',
        1 => 'field_event_address',
        2 => 'attendee_images',
        3 => 'body',
        4 => 'node_link',
      ),
      'right' => array(
        0 => 'field_event_date',
        1 => 'rsvp_badge',
        2 => 'attendee_count',
        3 => 'comment_count',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_venue' => 'left',
      'field_event_address' => 'left',
      'attendee_images' => 'left',
      'body' => 'left',
      'node_link' => 'left',
      'field_event_date' => 'right',
      'rsvp_badge' => 'right',
      'attendee_count' => 'right',
      'comment_count' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|event|teaser'] = $ds_layout;

  return $export;
}
