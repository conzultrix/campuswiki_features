<?php


function campuswiki_groups_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'group') {
    
    dpm($var);
    // Add group information that display suite and custom node templates can use.
    if ($group = campuswiki_groups_get_node_group($node)) {
      $gid = $group->gid;
      $var['group'] = $group;
      $var['group_node'] = node_load($group->etid);
      $var['group_url'] = 'node/' . $group->etid;
      $var['group_name'] = $group->label;
      $var['group_link'] = l($group->label, 'node/' . $group->etid);
    }
    
    // find next event for the group
    // check if user is able to view upcoming event for this group
    // See if this user should be able to view this group's meetings.
    $access = field_get_items('node', $var['group_node'], 'group_access'); dpm($access);
    $private = $access[0]['value'];
    if ($private && og_user_access($gid, 'view event content')) {
      $private = FALSE;
    }
    
    $next_event_id = campuswiki_groups_next_event($gid);
    
    if ($private) {
      $var['next_event_view'] = '<div class="private-event-text">' . t('Event details are available only to members.') . '</div>';
    }
    elseif (!empty($next_event_id)) {
      $var['next_event_node'] = node_load($next_event_id);
      $event_node = node_view($var['next_event_node'], 'square');
      $var['next_event_view'] = '<div class="next-event-view">' . drupal_render($event_node) . '</div>';
      $date = new DateObject($var['next_event_node']->field_event_date[LANGUAGE_NONE][0]['value'], 'UTC');
      date_timezone_set($date, date_default_timezone_object());
      $var['next_event_date'] = date_format($date, 'M d, Y');
    }
    else {
      $var['next_event_view'] = '<div class="no-event-text">' . t('There are no upcoming events for this group.') . '</div>';
    }
    
    //dpm($var['next_event_view']);
    // Showcase group content for teaser
    $var['group_content_view'] = $var['next_event_view'];
  
  }
}