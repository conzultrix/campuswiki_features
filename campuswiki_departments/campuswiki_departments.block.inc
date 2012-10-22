<?php

/**
 * Create the Department/Faculty information block
 *
 */
function campuswiki_departments_info_block() {
  $output = array();
  
  // retrive the term object being viewed
  $term = menu_get_object('taxonomy_term', 2);
  //dpm($term);
  $children = taxonomy_get_children($term->tid, $term->vid);
  //dpm($children);
  $parents = taxonomy_get_parents($term->tid);
  //dpm($parents);
  
  if (!empty($term->field_audience_image)) {
    $output['image'] = array(
      '#theme' => 'image_formatter',
      '#item' => $term->field_audience_image['und'][0],
      '#image_style' => 'sidebar',
    );
  }
  
  // if term has parent, display it
  if (!empty($parents)) {
    foreach ($parents as $pid => $parent) {
      $output['faculty'][$pid] = array(
        '#prefix' => '<div class = "audience-link">',
        '#suffix' => '</div>',
        '#type' => 'link',
        '#title' => $parent->name,
        '#href' => 'taxonomy/term/' . $parent->tid,
        '#options' => array(
          'attributes' => array(
            'class' => array('audience'),
            'title' => t('@faculty page', array('@faculty' => $parent->name)),
          ),
        ),
      );
    }
  }
  
  
  // creating Department info menu
  // initailize the items array to hold the links
  $items = array();
  
  // the home link
  $label = t('Wall');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid,
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // Members link
  $label = t('Members');
  $count = campuswiki_departments_member_count($term);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/members',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // Groups link
  $label = t('Groups');
  $count = campuswiki_departments_group_count($term);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/groups',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // Add departments link if we are looking at a faculty
  if (!empty($children)) {
    $label = t('Departments');
    $count = count($children);
    $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => $title,
        '#href' =>  'taxonomy/term/' . $term->tid . '/departments',
        '#options' => array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array('count-' . strtolower($label)),
          ),
        ),
      ),
    );
  }
  
  // wiki
  $label = t('Wiki');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/wiki',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // upcoming events
  $label = t('Upcoming events');
  $count = campuswiki_departments_upcoming_events_count($term);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/events',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // past events
  $label = t('Past events');
  $count = campuswiki_departments_past_events_count($term);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/past-events',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // events calendar
  $label = t('Calendar');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/calendar',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  
  // Gallery
  $label = t('Gallery');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'taxonomy/term/' . $term->tid . '/gallery',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
   
  // build a list of the links
  $output['menu'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#prefix' => '<div id="group-info-block-menu">',
    '#suffix' => '</div>',
    '#pre_render' => array('campuswiki_basic_item_list_child_render'),
  );
  
  
  // return the $output array
  return  $output;
}
