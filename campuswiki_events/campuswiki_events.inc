<?php

// module_load_include('inc', 'campuswiki_groups', 'campuswiki_groups.functions');

/**
 * Check if to allow RSVP for an Event
 */
function campuswiki_events_show_rsvp_link($node = NULL) {
  // if $node not provided, get one from loaded page
  if (empty($node)) {
    $node = menu_get_object();
    $nid = $node->nid;
  }
  
 if (empty($node) || !variable_get('cck_signup_type_' . $node->type, FALSE)) {
    return FALSE;
  }
  
  // ensure user is logged in
  global $user;
  if ($user->uid < 1) {
    return FALSE;
  }
  
  $override = user_access('override cck signup restrictions');

  // See if signups are closed for this event.
  if ($check_status = variable_get('cck_signup_field_status_' . $node->type, FALSE)) {
    if ($status = field_get_items('node', $node, $check_status)) {
     // dpm($status);
      $status = $status[0]['value'];
      if (($status < 1) && !$override) {
        return FALSE;
      }
    }
  }
  
  // See if the event is past already.
  if ($override || !cck_signup_event_is_past($node)) {
    // See if the event is full.
    $capacity = cck_signup_get_remaining_capacity($node);
    // A NULL value means there was no capacity set.
    if ($override || $capacity === NULL || $capacity > 0 || cck_signup_get_signup($node)) {
      // TODO: SEE HOW IT WORKS WITH A GROUP
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
  $signup_field = variable_get('cck_signup_field_' . $event->type, FALSE);
  // content type $signup_field refers to
  $types = cck_signup_get_signup_types($signup_field);

  $signups = array();
  foreach ($types as $type) {
    $field = field_info_field($signup_field);
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $type)
      ->fieldCondition($field, 'nid', $event->nid)
      ->count();
    $count = $query->execute();
    $signups[$type] = $count;
  }

  return array_sum($signups);
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
  $query->condition('field_rsvp_event_nid', $event->nid);
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

