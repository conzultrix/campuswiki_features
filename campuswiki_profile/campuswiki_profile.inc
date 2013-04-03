<?php

function campuswiki_profile_events_count($uid) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('uid', $uid)
    ->propertyCondition('status', 1)
    ->fieldCondition($field, 'value', $now, '>=')
    ->count();
  return $query->execute();
}