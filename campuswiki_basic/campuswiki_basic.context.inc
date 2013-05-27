<?php
/**
 * @file
 * campuswiki_basic.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_basic_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'campuswiki_basic-cw_features_menu' => array(
          'module' => 'campuswiki_basic',
          'delta' => 'cw_features_menu',
          'region' => 'user_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide_context'] = $context;

  return $export;
}
