<?php

/**
 * Check whether to show RSVP for an Event
 */
function campuswiki_events_show_rsvp_link($node = NULL) {
  // if $node not provided, get one from loaded page
  if (empty($node)) {
    $node = menu_get_object();
    $nid = $node->nid;
  }
  
 //if (empty($node) || !variable_get('cck_signup_type_' . $node->type, FALSE)) {
 //   return FALSE;
 // }
 
 if (empty($node) || ($node->type != 'event')) {
    return FALSE;
  }
  
  // ensure user is logged in
  global $user;
  if ($user->uid < 1) {
    return FALSE;
  }
  
  //$override = user_access('override cck signup restrictions');

  // See if signups are closed for this event.
  // set status field
  
  
  $status_field = 'field_event_open';
  //field current takes 1 or 0, should be changed to a checkbox
  if ($status = field_get_items('node', $node, $status_field)) {
    // dpm($status);
    $status = $status[0]['value'];
    if ($status < 1)  {
      return FALSE;
    }
  }
  
  
  // See if the event is past already.
  if (!campuswiki_events_event_is_past($node)) {
    // See if the event is full.
    $capacity = campuswiki_events_get_remaining_capacity($node);
    // A NULL value means there was no capacity set.
    if ($capacity === NULL || $capacity > 0) {
      return TRUE;
    }
  }
  
  return FALSE;
}

/**
 * Check if rsvp is enabled for an event
 *
 * @param object $event
 *  Event node object
 *
 * @return bool
 *  Returns FALSE if rsvp is not allowed
 *  TRUE if rsvp is allowed
 *
 */
function campuswiki_events_allow_rsvp($event) {
  // Check signup status.
  // Simple status check.
  $status_field = 'field_event_open';
  if ($status = field_get_items('node', $event, $status_field)) {
    $status = $status[0]['value'];
    if ($status > 0) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * get the number of attenddee for an event
 *
 * @param object $event
 *   Event node object.
 *
 */
function campuswiki_events_attendee_count($event) {
  $signup_field = 'field_rsvp_event';
  // content type $signup_field refers to
  $signup_type = 'rsvp';

  $field = field_info_field($signup_field); 
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $signup_type)
    ->fieldCondition($field, 'target_id', $event->nid)
    ->count();
    
  return $query->execute();

}

/**
 * Get the ids of those signing up for an event.
 */
function _campuswiki_events_attendee_ids($event, $max) {

  // This could be generalized to use the signup variables,
  // as in campuswiki_events_attendee_count instead of hard-coding the
  // field and table names.
  $query = db_select('field_data_field_rsvp_event', 'r');
  $query->addField('n', 'uid');
  $query->condition('field_rsvp_event_target_id', $event->nid);
  $query->leftJoin('node', 'n', 'n.nid=r.entity_id');
  if (!empty($max)) {
    $query->range(0, $max);
  }
  $result = $query->execute();
  $uids = array();
  foreach ($result as $row) {
    $uids[] = $row->uid;
  }
  return $uids;
}

/**
 * Get names or pix of meeting attendees.
 */
function campuswiki_events_attendees($node, $type = 'picture', $max = 10) {
  $attendees = array();
  $ids = _campuswiki_events_attendee_ids($node, $max);
  foreach ($ids as $id) {
    $account = user_load($id);
    $attendees[$id] = $type == 'picture' ?  theme('user_picture', array('account' => $account)) : theme('username', array('account' => $account));
  }
  return $attendees;
}



/**
 * get the number of comments for an event
 *
 * @param object $event
 *   Event node object.
 *
 */
function campuswiki_events_comment_count($event) {
  $signup_field = 'field_rsvp_event'; 
  // content type $signup_field refers to
  $signup_type = 'rsvp';

  $field = field_info_field($signup_field); 
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $signup_type)
    ->fieldCondition($field, 'target_id', $event->nid)
    ->fieldCondition('field_add_a_comment', 'value', 'NULL', '!=' )
    ->count();
    
  return $query->execute();
}


/**
 * Check if date for event is passed.
 * 
 * @param object $event
 *  The Event node
 */
function campuswiki_events_event_is_past($event) {
  // function is a reimplementation of cck_signup_event_is_past($node)
  //TODO programatically get the date field for the event
  //rather than hard coding it
  if (class_exists('DateObject')) {
    $check_date = 'field_event_date';
    $date = field_get_items('node', $event, $check_date);
    $event_date = new DateObject(
      $date[0]['value'],
      $date[0]['timezone']
    );
    $now = date_now();
    return $event_date <= $now;
  }
  return FALSE;

}

/**
 * Get the remaining capacity for an event
 *
 * @param object $event
 *  The Event node
 */
function campuswiki_events_get_remaining_capacity($event) {
  // reimplementation of cck_signup_get_remaining_capacity($node)
   $capacity_field = 'field_event_capacity';
  if (!$capacity = field_get_items('node', $event, $capacity_field)) {
    return;
  }
  $capacity = $capacity[0]['value'];
  //$signup_field = variable_get('cck_signup_field_' . $event->type, FALSE);
  $signup_field = 'field_rsvp_event';
  //$types = cck_signup_get_signup_types($signup_field);
  //the node type for signups
  $signup_type = 'rsvp';

  $field = field_info_field($signup_field);
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $signup_type)
    ->fieldCondition($field, 'target_id', $event->nid)
    ->count();
  $count = $query->execute();
  

  return $capacity - $count;
  
}


/**
 * Get the id of the user signup entity
 *
 * @param object $event
 *  The Event node
 *
 *  optional
 *  @param object $account
 *    The user object to check, defaults to loggin in user
 *
 *  @return mixed
 *    object he user signup entity
 *    bool false if the user hasn't signed up for the event
 */
function campuswiki_events_get_signup($event, $account= NULL) {
  if (empty($account)) {
    global $user;
    $account = user_load($user->uid);
  }
  
  // if no user is log in return
  if (!$account->uid) {
    return FALSE;
  }
  
  $signup_field = 'field_rsvp_event';
  $field = field_info_field($signup_field);
  $signup_type = 'rsvp';
  
  $query  = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'rsvp')
    ->fieldCondition($field, 'target_id', $event->nid)
    ->propertyCondition('uid', $account->uid);
  foreach ($query->execute() as $entity_type => $entities) {
    foreach ($entities as $entity_id => $entity) {
      if (!empty($entity->nid)) {
        return node_load($entity->nid);
      }
    }
  }
  return FALSE;
}

/**
 * return the correct link for an event signup
 *
 * @param object $event
 *  The event node
 *
 * @return array
 *  Render array to sinup or manage signup for an event
 *  If no rsvp link is required, return empty array
 */
function campuswiki_events_return_signup_link($event) {
  if (campuswiki_events_show_rsvp_link($event)) {
    if ($signup = campuswiki_events_get_signup($event)) {
      // if there is a signup for this event
      // return rsvp manage link
      return _campuswiki_events_manage_rsvp_link($signup->nid);
    }
    else {
      return _campuswiki_events_build_rsvp_link($event);
    }
  }
  else {
    return array();
  }
}

/**
 * Build a signup link
 *
 * @param object $event
 *  The event node
 *
 * @return array
 *  rsvp link as render array
 */
function _campuswiki_events_build_rsvp_link($event) {
  return array(
    '#theme' => 'links__node',
    '#links' => array(
      'rsvp_field_rsvp_event' => array(
        'title' => 'RSVP',
        'query' => array(
          'field_rsvp_event' => $event->nid,
          'destination' => 'node/' . $event->nid,
        ),
        'href' => 'node/add/rsvp',
        'attributes' => array(
          'title' => 'Signup for this event',
        ),
      ),
    ),
    '#attributes' => array(
      'class' => array('links', 'inline'),
    ),
  );
}


/**
 * Build a signup manage link
 *
 * @param int $id
 *  The signup entity id
 *
 * @return array
 *  manage rsvp link as render array
 */
function _campuswiki_events_manage_rsvp_link($id) {
  return array(
    '#theme' => 'links__node',
    '#links' => array(
      'rsvp_field_rsvp_event' => array(
        'href' => 'node/' . $id . '/edit',
        'title' => 'Manage your RSVP',
        'attributes' => array(
          'title' => 'Manage your RSVP',
        ),
      ),
    ),
    '#attributes' => array('links', 'inline'),
  );
}


function _campuswiki_events_get_event_image($event) {
  if (!empty($event->field_event_image)) {
    return $event->field_event_image[LANGUAGE_NONE][0];
  }
  return FALSE;
}

function _campuswiki_events_get_event_group_image($event) {
  $is_group_content = og_is_group_content_type('node', $event->type);
  if ($is_group_content && $gids = og_get_entity_groups('node', $event->nid)) {
    $first_group = array_shift($gids['node']);
    $group = node_load($first_group);
    if (!empty($group->field_group_photo)) {
      return $group->field_group_photo[LANGUAGE_NONE][0];
    }
  }
  return FALSE;
}

function _campuswiki_events_get_event_department_image($event) {
  if (!empty($event->field_campus_audience)) {
    $tid = $event->field_campus_audience[LANGUAGE_NONE][0]['tid'];
    $dept = taxonomy_term_load($tid);
    if (!empty($dept->field_audience_image)) {
      return $dept->field_audience_image[LANGUAGE_NONE][0];
    }
  }
  return FALSE;
}

function campuswiki_events_get_image($event) {
  if ($image = _campuswiki_events_get_event_image($event)) {
    return $image;
  }
  
  if ($image = _campuswiki_events_get_event_group_image($event)) {
    return $image;
  }
  
  if ($image = _campuswiki_events_get_event_department_image($event)) {
    return $image;
  }
  
  return FALSE;
}

function campuswiki_events_get_upcoming_events_id($range = 14) {
  $now = date_now('UTC');
  $now = $now->format(DATE_FORMAT_DATETIME);
  
  $time = strtotime('+ ' . $range . ' days'); //dpm($time);
  $then = new DateObject($time, 'UTC');
  $then = $then->format(DATE_FORMAT_DATETIME);
  
  $field = 'field_event_date';
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('status', 1)
    ->fieldCondition($field, 'value', $now, '>')
    ->fieldCondition($field, 'value', $then, '<=');
  
  $result = $query->execute();
  if (!empty($result)) {
    return array_keys($result['node']);
  }
  return array();
}

function campuswiki_events_get_past_events_id($range = 7) {
  $now = date_now('UTC');
  $now = $now->format(DATE_FORMAT_DATETIME);
  
  $field = 'field_event_date';
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('status', 1)
    ->fieldCondition($field, 'value', $now, '<')
    ->fieldOrderBy($field, 'value', 'DESC')
    ->range(0, $range);
    
  $result = $query->execute();
  if (!empty($result)) {
    return array_keys($result['node']);
  }
  return array();
}