<?php
  
  include_once('campuswiki_departments.inc');
  include_once(drupal_get_path('module', 'campuswiki') . '/campuswiki.inc');

/**
 * Implements hook_block_info().
 *
 */
function campuswiki_departments_block_info() {
  $blocks['department_info'] = array(
    'info' => t('Department info'),
    'cache' => DRUPAL_NO_CACHE,
    // DRUPAL_CACHE_PER_ROLE will be assumed if not set.
  );
  
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function campuswiki_departments_block_view($delta = '') {
  // create an empty block.
  $block = array(
    'subject' => '',
    'content' => '',
  );
  
  // check which block is being requested.
  if ($delta == 'department_info') {
    $term = menu_get_object('taxonomy_term', 2);
    dpm($term);
    dpm(campuswiki_departments_department_user_count($term->tid));
    
    
    $block['subject'] = t('Department info');
    //$block['content'] = '<div>' . $term->tid . '</div>';
    
    // add the department image if found
    if (!empty($term->field_dept_photo)) {
      $item = $term->field_dept_photo['und'][0];

      $block['content']['image'] = array(
        '#theme' => 'image_formatter',
        '#item' => $item,
        '#image_style' => 'sidebar',
      );
    }
    
    // display the faculty this department belongs to
    if (!empty($term->field_faculty)) {
      $faculty_id = $term->field_faculty['und'][0]['tid'];
      
      // locad the faculty object to retrive the term name by id
      $faculty = taxonomy_term_load($faculty_id);
            
      $value = array('@faculty' => $faculty->name);
      $title = t('Faculty of @faculty', $value);
      $block['content']['faculty'] = array(
        '#prefix' => '<div class = "faculty-link">',
        '#suffix' => '</div>',
        '#type' => 'link',
        '#title' => $title,
        '#href' => 'taxonomy/term/' . $faculty_id,
        '#options' => array(
          'attributes' => array(
            'class' => array('faculty'),
            'title' => t('view the Faculty of @faculty page', $value),
          ),
        ),
      );
    }
    
    // build the department menu
    // initialise and $items array to hold the item in the menu
    $items = array();
    
    // create the home link for the menu
    $title = t('Home');
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => '<span class="first">' . $title . '</span><span class="icon second"></span>',
        '#href' => 'taxonomy/term/' . $term->tid,
        '#options' => array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array('icon-' . strtolower($title)),
          ),
        ),
      ),
    );
  }
  
  // create the member link
  if (TRUE) {
    // check if the members feature s enabled
    $count = campuswiki_departments_department_user_count($term->tid);
    $title = t('Members');
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => '<span class="first">' . $title . '</span><span class="count second">' . $count . '</span>',
        '#href' => 'taxonomy/term/' . $term->tid . '/' . strtolower($title),
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
  }
  
  
  // add menu to block
  $block['content']['menu'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#pre_render' => array('campuswiki_item_list_child_render'),
  );
  
  //dpm(campuswiki_item_list_child_render($items));
  
  return $block;
}