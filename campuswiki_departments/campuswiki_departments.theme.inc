<?php

/**
 * Implements hook_preprocess_taxonomy_term().
 */
function campuswiki_departments_preprocess_taxonomy_term(&$vars) {
  $title = $vars['name'];
  $term = $vars['term'];
  $term_id = $vars['tid'];
  
  // Get the number of groups in a this department
  $group_count = campuswiki_departments_group_count($term);
  if (!empty($group_count)) {
    $group_text = $group_count > 1 ? $group_count . ' Groups' : $group_count . ' Group';
  }
  else {
    $group_text = NULL;
  }
  
  // Get the number of events in this department
  $event_count = campuswiki_departments_content_count($term, 'event');
  
  if (!empty($event_count)) {
    $event_text = $event_count;
    $event_text .= $event_count > 1 ?  '  Events' : ' Event';
  }
  else {
    $event_text = NULL;
  }
  
  // Get the number of Wiki pages in this department
  $wiki_count = campuswiki_departments_content_count($term, 'wiki');
  
  if (!empty($wiki_count)) {
    $wiki_text = $wiki_count;
    $wiki_text .= $wiki_count > 1 ? ' Wiki pages' : ' Wiki page';
  }
  else {
    $wiki_text = NULL;
  }
  
  // Create 'audience formatted text' field
  
  $vars['audience_formatted_text'] = array(
    '#prefix' => '<div class="audience-formatted-text">',
    '#suffix' => '</div>',
  );
  
  $vars['audience_formatted_text']['department'] = array(
    '#prefix' => '<h3>',
    '#suffix' => '</h3>',
    '#type' => 'link',
    '#title' => $title,
    '#href' => 'taxonomy/term/' . $term_id,
  );
  
  $vars['audience_formatted_text']['info'] = array(
    '#prefix' => '<div class="audience-content"> <span>',
    '#suffix' => '</div>',
    '#markup' => '<span>' . $group_text . ' </span><span>' . $wiki_text . ' </span><span>' . $event_text . ' </span>',
  );
  
  
}