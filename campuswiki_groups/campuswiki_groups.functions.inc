<?php

/**
 * Helper function to get group information even when when we 
 * get access denied on group page, needed to collect group
 * information for private groups.
 */
function campuswiki_groups_get_group_by_arg() {
  $group = NULL;

  // Only implemented on 'node/%' and 'node/%/view'.
  if (arg(0) == 'node' && is_numeric(arg(1)) && (arg(2) == 'view' || count(arg()) < 3)) {
    $node = node_load(arg(1));
    if (og_is_group_type('node', $node->type)) {
      $group = og_get_group('node', $node->nid);
    }
  }
  return $group;
}


/**
 * Helper function to get a count of the members in a group.
 */
function campuswiki_groups_member_count($gid) {
  $members = og_membership_load_multiple(FALSE, array('gid' => $gid, 'entity_type' => 'user'));
  return count($members);
}

/**
 * Number of upcoming Events for a group.
 */
function campuswiki_groups_upcoming_events_count($gid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition($field, 'value', $now, '>=')
    ->fieldCondition(OG_AUDIENCE_FIELD, 'gid', $gid, '=')
    ->count();
  return $query->execute();
}


/**
 * Number of past Events for a group.
 */
function campuswiki_groups_past_events_count($gid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition($field, 'value', $now, '<')
    ->fieldCondition(OG_AUDIENCE_FIELD, 'gid', $gid, '=')
    ->count();
  return $query->execute();
}
