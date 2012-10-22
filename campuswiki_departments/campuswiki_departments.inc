<?php

/**
 * Return the number of users tagged with a department
 *
 * @param object $term
 *
 * @return int
 *  The number of users tagged the the taxonomy term $term
 *
 */
function campuswiki_departments_member_count($term) {
  $children = taxonomy_get_children($term->tid, $term->vid);
  // if term has no child we are viewing a department, return the count
  if (empty($children)) {
    return _campuswiki_departments_department_member_count($term);
  }
  else {
    // perform member count on each of the departments
    // since we are viewing a faculty
    $members = array();
    foreach ($children as $cid => $child) {
      $members[$cid] = _campuswiki_departments_department_member_count($child);
    }
    return array_sum($members);
  }
}
 
 
function _campuswiki_departments_department_member_count($term) {
  // create an EntityFieldQuery() to get number of users tag with the department field
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
        ->fieldCondition('field_user_department', 'tid', $term->tid)
        ->addMetaData('account', user_load(1));
       
  return $query->count()->execute();
}


/**
 * Return the number of groups tagged with a department
 *
 * @param object $term
 *
 * @return int
 *  The number of groups tagged the the taxonomy term $term
 *
 */
function campuswiki_departments_group_count($term) {
  $children = taxonomy_get_children($term->tid, $term->vid);
  // if term has no child we are viewing a department, return the count
  if (empty($children)) {
    return _campuswiki_departments_department_group_count($term);
  }
  else {
    // perform group count on each of the departments
    // since we are viewing a faculty
    $groups = array();
    // first add the faculty specific groups
    $groups[$term->tid] = _campuswiki_departments_department_group_count($term);
    // then add the groups from departments in the faculty
    foreach ($children as $cid => $child) {
      $groups[$cid] = _campuswiki_departments_department_group_count($child);
    }
    return array_sum($groups);
  }
}
 
 
function _campuswiki_departments_department_group_count($term) {
  // create an EntityFieldQuery() to get number of users tag with the department field
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'group')
        ->fieldCondition('field_campus_audience', 'tid', $term->tid);
       
  return $query->count()->execute();
}


/**
 * Number of upcoming Events for a department or faculty.
 */
function campuswiki_departments_upcoming_events_count($term) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition($field, 'value', $now, '>=')
    ->fieldCondition('field_campus_audience', 'tid', $term->tid)
    ->count();
  return $query->execute();
}

/**
 * Number of past Events for a group.
 */
function campuswiki_departments_past_events_count($term) {
  $now = date_now('UTC');
  $now->format(DATE_FORMAT_DATETIME);
  $field = field_info_field('field_event_date');

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition($field, 'value', $now, '<')
    ->fieldCondition('field_campus_audience', 'tid', $term->tid)
    ->count();
  return $query->execute();
}
