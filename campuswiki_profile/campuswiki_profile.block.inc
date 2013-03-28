<?php

/**
 * Create the user information block
 *
 */

function campuswiki_profile_user_info_block() {
  // retrive the object of the user being viewed
  
  $output = array();
  
  $user = menu_get_object('user');
  dpm($user);
  dpm($user->picture->uri);
  
  // get the user image
    
  if (!empty($user->picture->uri)) {
    $output['image'] = array(
      '#theme' => 'image_style',
      '#path' => $user->picture->uri,
      '#style_name' => 'sidebar',
    );
  }
  
  // creating the user menu
  // initialise the items array to hold the links
  $items = array();
  
  
  // the home link
  $label = t('Wall');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'user/' . $user->uid,
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // wiki
  $label = t('Wiki');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'user/' . $user->uid . '/wiki',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // events
  $label = t('Events');
  $count = campuswiki_profile_events_count($user->uid);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'user/' . $user->uid . '/events',
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
      '#href' =>  'user/' . $user->uid . '/calendar',
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
      '#href' =>  'user/' . $user->uid . '/gallery',
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
    '#prefix' => '<div id="user-info-block-menu">',
    '#suffix' => '</div>',
    '#pre_render' => array('campuswiki_basic_item_list_child_render'),
  );
  
  
  return $output;
} 