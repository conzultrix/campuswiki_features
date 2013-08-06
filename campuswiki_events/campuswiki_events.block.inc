<?php

function campuswiki_events_frontpage_block() {
  $content  = array();
  // check if there is an upcoming event
  $ids = campuswiki_events_get_upcoming_events_id();
  if (!empty($ids)) {
    if (count($ids) > 1) {
      shuffle($ids);
    }
    $nid = array_shift($ids);
    $content['title'] = t('Upcoming Event');
    $content['body'] = node_view(node_load($nid), 'showcase');
    return $content;
  }
  
  $ids = campuswiki_events_get_past_events_id();
  if (!empty($ids)) {
    if (count($ids) > 1) {
      shuffle($ids);
    }
    $nid = array_shift($ids);
    $content['title'] = t('Recent Event');
    $content['body'] = node_view(node_load($nid), 'showcase');
    return $content;
  }
  
  return $content;
}