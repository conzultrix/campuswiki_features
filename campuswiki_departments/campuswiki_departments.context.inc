<?php
/**
 * @file
 * campuswiki_departments.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_departments_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'department_context';
  $context->description = 'Active when viewing department or faculty page';
  $context->tag = 'department';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*' => 'taxonomy/term/*',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'campus_audience' => 'campus_audience',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'campuswiki_departments-department_info' => array(
          'module' => 'campuswiki_departments',
          'delta' => 'department_info',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active when viewing department or faculty page');
  t('department');
  $export['department_context'] = $context;

  return $export;
}
