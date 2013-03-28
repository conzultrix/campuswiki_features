<?php
/**
 * @file
 * campuswiki_profile.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_profile_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile_page';
  $context->description = 'active when viewing a user\'s profile page';
  $context->tag = 'user';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'campuswiki_profile-cw_user_info' => array(
          'module' => 'campuswiki_profile',
          'delta' => 'cw_user_info',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('active when viewing a user\'s profile page');
  t('user');
  $export['user_profile_page'] = $context;

  return $export;
}
