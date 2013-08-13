<?php
/**
 * @file
 * campuswiki_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campuswiki_gallery_ctools_plugin_api() {
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
function campuswiki_gallery_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function campuswiki_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: photo.
  $styles['photo'] = array(
    'name' => 'photo',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '560',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'photo',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function campuswiki_gallery_node_info() {
  $items = array(
    'album' => array(
      'name' => t('Photo gallery'),
      'base' => 'node_content',
      'description' => t('A collection of photographs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'photo' => array(
      'name' => t('Photo'),
      'base' => 'node_content',
      'description' => t('A picture or image you want to share'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
