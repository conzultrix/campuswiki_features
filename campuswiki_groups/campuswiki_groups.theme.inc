<?php


function campuswiki_groups_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'group') { dpm($node);
    
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
    $access = field_get_items('node', $var['group_node'], 'group_access');
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
    
    // create a square view of the recently modified
    // wiki page to be used for academic groups
    $recent_wiki_id = campuswiki_groups_recent_wiki($gid);
    
    if ($private) {
      $var['recent_wiki_view'] = '<div class="private-wiki-text">' . t('Wiki pages are available only to members.') . '</div>';
    }
    elseif (!empty($recent_wiki_id)) {
      $var['recent_wiki_node'] = node_load($recent_wiki_id);
      $wiki_node = node_view($var['recent_wiki_node'], 'square');
      $var['recent_wiki_view'] = '<div class="recent-wiki-view">' . drupal_render($wiki_node) . '</div>';
      
    }
    else {
      $var['recent_wiki_view'] = '<div class="no-wiki-text">' . t('There are no Wiki pages for this group yet.') . '</div>';
    }
    
    
    //dpm($var['next_event_view']);
    // Showcase group content for teaser
    // if group is an academic group show wiki else show event
    $group_type = $var['group_node']->field_group_type[LANGUAGE_NONE][0]['value']; 
    $var['group_content_view'] = ($group_type == '1') ? $var['recent_wiki_view'] : $var['next_event_view'];
    
  
  }
}