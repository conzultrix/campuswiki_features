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
  $context->tag = 'campuswiki';
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
        'campuswiki_basic-cw_main_menu' => array(
          'module' => 'campuswiki_basic',
          'delta' => 'cw_main_menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('campuswiki');
  $export['sitewide_context'] = $context;

  return $export;
}
