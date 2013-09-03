<?php

function campuswiki_profile_events_count($uid) {
  return campuswiki_profile_created_events_count($uid) + campuswiki_profile_user_attendance_count($uid);
}

function campuswiki_profile_created_events_count($uid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');
  $rsvp_field = field_info_field('field_rsvp');

  // count events user created
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('uid', $uid)
    ->propertyCondition('status', 1)
    ->fieldCondition($field, 'value', $now, '>=')
    ->count();
  return $query->execute();
}


function campuswiki_profile_user_attendance_count($uid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  
  // count events user is attending
  $query = db_select('field_data_field_rsvp_event', 'r');
  $query->leftjoin('node', 'n', 'r.entity_id = n.nid');
  $query->condition('n.uid', $uid);
  $query->leftjoin('field_data_field_event_date', 'd', 'd.entity_id = r.field_rsvp_event_target_id');
  $query->condition('d.field_event_date_value', $now, '>=');
  $query->leftjoin('field_data_field_rsvp', 'rp', 'r.entity_id = rp.entity_id');
  $query->condition('rp.field_rsvp_value', 'Yes', 'LIKE');
  $query->addField('r', 'field_rsvp_event_target_id');
  
  return $query->execute()->rowCount();
}



function campuswiki_profile_created_events($uid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');
  $rsvp_field = field_info_field('field_rsvp');

  // count events user created
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('uid', $uid)
    ->propertyCondition('status', 1)
    ->fieldCondition($field, 'value', $now, '>=');
    
  return $query->execute();
}

function _campuswiki_profile_user_message_picture() {
  global $user;
  $account = user_load($user->uid);
  
  if (!empty($account->picture)) {
    return array(
      '#theme' => 'image_style',
      '#path' => $account->picture->uri,
      '#style_name' => 'user_avatar_32',
    );
  }
  else {
    return array(
      '#theme' => 'image',
      '#path' => drupal_get_path('module', 'campuswiki_profile') . '/images/icons/user-32.png',
      '#width' => '32',
      '#height' => '32',
      '#alt' => 'default-user-image',
      //'#prefix' => '<div class="user-image">',
      //'#suffix' => '</div>',
    );
  }
}

function _campuswiki_profile_user_message_actions() {
  global $user;
  
  $output = array(
    '#prefix' => '<div class="user-actions">',
    '#suffix' => '</div>',
  );
  
  if (!$user->uid) {
    $var = array(
      '@login' => url('user/login'),
      '@register' => url('user/register'),
    );
    $output['#markup'] = t('Please <a href="@login">Login</a> or <a href="@register">Sign up</a>', $var);
  }
  else {
    $username = theme('username', array('account' => $user));
    $var = array(
      '@view' => url('user/' . $user->uid),
      '@edit' => url('user/' . $user->uid . '/edit'),
      '@logout' => url('user/logout'),
    );
    
    $output['#markup'] = '<div class="username">' . t('Hello !user', array('!user' => $username)) .'</div>';
    $output['#markup'] .= t('<a href="@view">View</a> | <a href="@edit">Edit</a> | <a href="@logout">Logout</a>', $var);
    
  }
  
  return $output;
}