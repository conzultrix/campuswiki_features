<?php

/**
 * Get the group that a node belongs to,
 * works for either the group node itself or a group content node.
 */
function campuswiki_groups_get_node_group($node) {
  if (og_is_group_type('node', $node->type)) {
    $group = og_get_group('node', $node->nid);
  }
  elseif (og_is_group_content_type('node', $node->type)) {
    $gids = og_get_entity_groups('node', $node);
    if (!$gids) {
      return;
    }
    // Get the first group.
    $gid = reset($gids);
    $group = og_load($gid);
  }
  if (empty($group)) {
    return;
  }
  return $group;

}

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


/**
 * Get the nid for the next event for this group
 */
function campuswiki_groups_next_event($gid) {
  // Get a comparison date in the same timezone and format
  // as the data stored in the database.
  $now = date_now('UTC');
  $now = $now->format(DATE_FORMAT_DATETIME);

  $query = db_select('og_membership', 'og');
  $query->condition('og.gid', $gid);
  $query->condition('og.entity_type', 'node');
  $query->leftJoin('node', 'n', 'n.nid = og.etid');
  $query->condition('n.type', 'event');
  $query->leftJoin('field_data_field_event_date', 'd', 'n.nid=d.entity_id');
  $query->condition('d.field_event_date_value', $now, '>=');
  $query->addField('n', 'nid');
  $query->orderBy('d.field_event_date_value', 'asc');
  $query->range(0, 1);
  $result = $query->execute()->fetchField();
  return $result;
}
