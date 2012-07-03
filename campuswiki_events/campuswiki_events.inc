<?php

module_load_include('inc', 'campuswiki_groups', 'campuswiki_groups.functions');

/**
 * Check if to allow RSVP for an Event
 */
function campuswiki_events_allow_rsvp($node = NULL) {
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
      dpm($status);
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
    if ($override || $capacity === NULL || $capacity > 0) {
      // See if this user is already subscribed to this event.
      if ($override || !cck_signup_get_signup($node)) {
        // See if this user has permission to rsvp this group.
        $group = campuswiki_groups_get_node_group($node);
        if (!empty($group) && og_user_access($group->gid, 'create rsvp content', $user)) {
          return TRUE;
        }
      }
    }
  }
  
  return FALSE;
}