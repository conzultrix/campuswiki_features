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
  $context->name = 'cw_omega_layout_switch';
  $context->description = 'chose the desired layout depending on the page being viewed';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('chose the desired layout depending on the page being viewed');
  t('theme');
  $export['cw_omega_layout_switch'] = $context;

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
        'campuswiki_profile-cw_user_message' => array(
          'module' => 'campuswiki_profile',
          'delta' => 'cw_user_message',
          'region' => 'header',
          'weight' => '-10',
        ),
        'campuswiki_basic-cw_main_menu' => array(
          'module' => 'campuswiki_basic',
          'delta' => 'cw_main_menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'campuswiki_basic-cw_copyright' => array(
          'module' => 'campuswiki_basic',
          'delta' => 'cw_copyright',
          'region' => 'footer',
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
