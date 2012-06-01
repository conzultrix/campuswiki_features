<?php
/**
 * @file
 * campuswiki_wiki.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function campuswiki_wiki_filter_default_formats() {
  $formats = array();

  // Exported format: Wiki
  $formats['wiki'] = array(
    'format' => 'wiki',
    'name' => 'Wiki',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'freelinking' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_markdown' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
