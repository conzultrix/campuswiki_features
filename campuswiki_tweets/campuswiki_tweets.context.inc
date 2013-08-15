<?php
/**
 * @file
 * campuswiki_tweets.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function campuswiki_tweets_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cw_tweets';
  $context->description = '';
  $context->tag = 'twitter';
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
        'views-cw_tweets-block_1' => array(
          'module' => 'views',
          'delta' => 'cw_tweets-block_1',
          'region' => 'footertop_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('twitter');
  $export['cw_tweets'] = $context;

  return $export;
}
