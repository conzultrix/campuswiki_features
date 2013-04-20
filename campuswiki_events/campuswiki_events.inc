<?php

// module_load_include('inc', 'campuswiki_groups', 'campuswiki_groups.functions');

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
  if ($override || !campuswiki_events_event_is_past($node)) {
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
  //TODO reimplement to programatically get the date field for the event
  //rather than hard coding it
  if (($check_date = 'field_event_date') && class_exists('DateObject')) {
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
    ->fieldCondition($field, 'nid', $event->nid)
    ->count();
  $count = $query->execute();
  

  return $capacity - $count;
  
}