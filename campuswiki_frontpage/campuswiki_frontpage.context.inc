<?php
/**
 * @file
 * campuswiki_frontpage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_frontpage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage_context';
  $context->description = '';
  $context->tag = 'frontpage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cw_latest_wiki_update-block' => array(
          'module' => 'views',
          'delta' => 'cw_latest_wiki_update-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'campuswiki_events-frontpage_event' => array(
          'module' => 'campuswiki_events',
          'delta' => 'frontpage_event',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'views-photo_gallery-block_1' => array(
          'module' => 'views',
          'delta' => 'photo_gallery-block_1',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'views-cw_activity_stream-block_1' => array(
          'module' => 'views',
          'delta' => 'cw_activity_stream-block_1',
          'region' => 'postscript_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('frontpage');
  $export['frontpage_context'] = $context;

  return $export;
}
