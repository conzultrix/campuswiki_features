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
  $ds_fieldsetting->id = 'node|event|alternate_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'alternate_teaser';
  $ds_fieldsetting->settings = array(
    'attendee_count' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attendee_images' => array(
      'weight' => '3',
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
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|alternate_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|showcase';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'showcase';
  $ds_fieldsetting->settings = array(
    'attendee_count' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attendee_images' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_formatted_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rsvp_button' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|showcase'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|square';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'square';
  $ds_fieldsetting->settings = array(
    'attendee_count' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attendee_images' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_calendar_day' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'venue_formatted_text' => array(
      'weight' => '3',
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
    'node_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => 'div',
        'class' => 'read-more-button',
      ),
    ),
  );
  $export['node|event|square'] = $ds_fieldsetting;

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
  $ds_field->field = 'cw_event_image';
  $ds_field->label = 'CW Event Image';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['cw_event_image'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_calendar_day';
  $ds_field->label = 'Event calendar day';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['event_calendar_day'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_formatted_info';
  $ds_field->label = 'Event Formatted Info';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['event_formatted_info'] = $ds_field;

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

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'rsvp_button';
  $ds_field->label = 'RSVP button';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['rsvp_button'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'venue_formatted_text';
  $ds_field->label = 'Venue formatted text';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['venue_formatted_text'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function campuswiki_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|alternate_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'alternate_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_event_date',
        2 => 'attendee_count',
        3 => 'attendee_images',
        4 => 'field_event_rating',
        5 => 'body',
        6 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_event_date' => 'ds_content',
      'attendee_count' => 'ds_content',
      'attendee_images' => 'ds_content',
      'field_event_rating' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event|alternate_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|showcase';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'showcase';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'event_formatted_info',
        1 => 'attendee_count',
        2 => 'attendee_images',
        3 => 'rsvp_button',
      ),
    ),
    'fields' => array(
      'event_formatted_info' => 'ds_content',
      'attendee_count' => 'ds_content',
      'attendee_images' => 'ds_content',
      'rsvp_button' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event|showcase'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|square';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'square';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'event_calendar_day',
        2 => 'field_event_date',
        3 => 'venue_formatted_text',
        4 => 'body',
        5 => 'attendee_images',
        6 => 'attendee_count',
        7 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'event_calendar_day' => 'ds_content',
      'field_event_date' => 'ds_content',
      'venue_formatted_text' => 'ds_content',
      'body' => 'ds_content',
      'attendee_images' => 'ds_content',
      'attendee_count' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event|square'] = $ds_layout;

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

/**
 * Implements hook_ds_view_modes_info().
 */
function campuswiki_events_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'alternate_teaser';
  $ds_view_mode->label = 'Alternate teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['alternate_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'showcase';
  $ds_view_mode->label = 'Showcase';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['showcase'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'small_teaser';
  $ds_view_mode->label = 'small teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['small_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'square';
  $ds_view_mode->label = 'Square';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['square'] = $ds_view_mode;

  return $export;
}
