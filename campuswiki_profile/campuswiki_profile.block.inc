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
  
  // get the user image
    
  if (!empty($user->picture)) {
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

function campuswiki_profile_user_groups_block() {
  define('NUMBER_OF_GROUPS', 5);
  // retrive the object of the user being viewed
  
  $output = array();
  
  $user = menu_get_object('user');
  
  // Get the group IDs of all the groups a user is an approved member of.
  $gids = og_get_groups_by_user($user, 'node');
  if (!empty($gids)) {
    // randomize the array
    shuffle($gids);
  }
  
  
  // limit the $gids array to the number of groups needed to be listed
  // in the block
  // may make this configurable but currently using the constant
  // NUMBER_OF_GROUPS
  $more_link = FALSE;
  if (count($gids) > NUMBER_OF_GROUPS) {
    $more_link = TRUE;
    $gids = array_slice($gids, 0, NUMBER_OF_GROUPS);
  }
  
  // initialise an items array to hold the list of groups
  $items = array();
  
  // load the groups that the user belong to using the $gids
  foreach ($gids as $gid) {
    $group_node = node_load($gid);
    if (!empty($group_node->field_group_photo)) {
      $variables = array(
        'item' => $group_node->field_group_photo[LANGUAGE_NONE][0],
        'image_style' => 'user_avatar',
      );
      $image = theme('image_formatter', $variables);
    }
    else {
      $image = NULL; // to be replaced by default image
    }
    $group_name = $group_node->title;
    $title = '<span class="group-thumbnail">' . $image . '</span><span class="group-name">' . $group_name . '</span>';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => $title,
        '#href' =>  'node/' . $group_node->nid,
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
    
  }
  
  
  // build a list of the links
  $output['groups'] = array(
    '#prefix' => '<div id="user-groups-block">',
    '#suffix' => '</div>',
  );
  
  $output['groups']['list'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#pre_render' => array('campuswiki_basic_item_list_child_render'),
  );
  
  if ($more_link) {
    $output['groups']['more_link'] = array(
      '#theme' => 'more_link',
      '#url' => 'user/' . $user->uid . '/groups',
      '#title' => 'View more groups',
    );
  }
  
  return $output;
  
}

function campuswiki_profile_user_connection_block() {
  $user = menu_get_object('user');
  $output = array();
  
  // array to hold links
  $items = array();
  if (!empty($user->field_facebook_url)) {
    // build link to user's facebook page
    $fb = $user->field_facebook_url[LANGUAGE_NONE][0]['url'];
    $icon = drupal_get_path('module', 'campuswiki_basic') . '/images/icons/facebook-24.png';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => theme('image', array('path' => $icon, 'width' => 24, 'height' => 24, 'alt' => 'Facebook icon', 'title' => 'Facebook')),
        '#href' =>  $fb,
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
  }
  
  if (!empty($user->field_twitter_url)) {
    $twitter = $user->field_twitter_url[LANGUAGE_NONE][0]['url'];
    $icon = drupal_get_path('module', 'campuswiki_basic') . '/images/icons/twitter-24.png';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => theme('image', array('path' => $icon, 'width' => 24, 'height' => 24, 'alt' => 'Twitter icon', 'title' => 'Twitter')),
        '#href' =>  $twitter,
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
  }
  
  if (!empty($user->field_google_plus_url)) {
    $gplus = $user->field_google_plus_url[LANGUAGE_NONE][0]['url'];
    $icon = drupal_get_path('module', 'campuswiki_basic') . '/images/icons/gplus-24.png';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => theme('image', array('path' => $icon, 'width' => 24, 'height' => 24, 'alt' => 'Google Plus icon', 'title' => 'Google Plus')),
        '#href' =>  $gplus,
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
  }
  
  if (module_exists('contact') && !empty($user)) {
    $icon = drupal_get_path('module', 'campuswiki_basic') . '/images/icons/mail-24.png';
    $items[] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => theme('image', array('path' => $icon, 'width' => 24, 'height' => 24, 'alt' => 'Mail icon', 'title' => 'Contact')),
        '#href' =>  'user/' . $user->uid . '/contact',
        '#options' => array(
          'html' => TRUE,
        ),
      ),
    );
  }
  
  
  // build a list of user connection links
  if (!empty($items)) {
    $output = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#prefix' => '<div id="user-connections-block">',
      '#suffix' => '</div>',
      '#pre_render' => array('campuswiki_basic_item_list_child_render'),
      '#attributes' => array(
        'class' => array('inline'),
      ),
    );
  }
  
  return $output;
}

function campuswiki_profile_user_groups_count() {
  $user = menu_get_object('user');
  
  // Get the group IDs of all the groups a user is an approved member of.
  $gids = og_get_groups_by_user($user, 'node');
  
  return count($gids);
}

/**
 * Returns the user message block for the top of the page.
 *
 */
function campuswiki_profile_user_message_block() {
  return array(
    '#prefix' => '<div class="l-user-message">',
    '#suffix' => '</div>',
    'picture' => _campuswiki_profile_user_message_picture(),
    'message' => _campuswiki_profile_user_message_actions(),
  );
}