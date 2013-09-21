<?php
/**
 * @file
 * campuswiki_groups.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_groups_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_context';
  $context->description = '';
  $context->tag = 'group';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'album' => 'album',
        'event' => 'event',
        'group' => 'group',
        'photo' => 'photo',
        'wiki' => 'wiki',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'campuswiki_groups-group_info' => array(
          'module' => 'campuswiki_groups',
          'delta' => 'group_info',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('group');
  $export['group_context'] = $context;

  return $export;
}
