<?php
/**
 * @file
 * campuswiki_panels.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function campuswiki_panels_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'three_regions_top_left_right';
  $layout->admin_title = 'Three regions top left right';
  $layout->admin_description = '';
  $layout->category = 'CampusWiki';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'post-content',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '66.58774152842834',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'post-content-left',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '33.41225847157166',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'post-content-right',
      ),
    ),
  );
  $export['three_regions_top_left_right'] = $layout;

  return $export;
}
