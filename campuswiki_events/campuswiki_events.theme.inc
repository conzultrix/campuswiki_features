<?php


function campuswiki_events_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'event') {
    
    $var['rsvp_link'] = NULL;
    if (isset($var['content']['links']['nodereference_url'])) {
      $var['rsvp_link'] = $var['content']['links']['nodereference_url'];
      unset($var['content']['links']['nodereference_url']);
    }
    
    $var['rsvp_badge'] = array(
      '#theme' => 'campuswiki_events_rsvp_badge',
      '#nid' => $node->nid,
      '#link' => $var['rsvp_link'],
    );
    
    $var['attendee_count'] = '<div class="event-attendance">' . t('@count @action', array(
      '@count' => campuswiki_events_attendee_count($node), 
      '@action' => (cck_signup_event_is_past($node) ? t('attended') : t('attending')),
    ))  . '</div>';
    
    $var['attendee_images'] = '<div class="attendee-images clearfix">' . implode(' ', campuswiki_events_attendees($node, 'picture')) . '</div>';
    $var['attendee_names'] = '<div class="attendee-names">' . implode(', ', campuswiki_events_attendees($node, 'name')) . '</div>';
  }
}


function theme_campuswiki_events_flipcard ($var) {
  $output = '';
  $nid = $var['nid'];
  $node = node_load($nid);
  $remaining = cck_signup_get_remaining_capacity($node);
  
  // Event never had capacity set
  if ($remaining === NULL) {
    return $output;
  }
  
  // set $spot_left value
  $spot_left = $remaining > 20 ? '20+' : $remaining;
  
  // set $spot_text
  $spot_text = $remaining > 1 ? t('Spots left') : t('Spot left');
  
  $output .= '<span class = "rsvp-flipcard spots">';
  $output .= '<span class = "rsvp-flipcard-ring"></span>';
  $output .= '<span class ="rsvp-flipcard-count">' . $spot_left . '</span>';
  $output .= '<span class = "rsvp-flipcard-text">' . $spot_text . '</span>';
  $output .= '</span>';

  
  return $output;
}

function theme_campuswiki_events_rsvp_badge($var) {
  $output = "";
  $nid = $var['nid'];
  $node = node_load($nid);
  $link = $var['link'];
  
  $output .= '<div class="rsvp-badge clearfix">';
  $output .= theme('campuswiki_events_flipcard', array('nid' => $nid));
  if (campuswiki_events_show_rsvp_link($node)) {
    $output .= '<div class="rsvp-link">';
    $output .= is_array($link) ? drupal_render($link) : $link;
    $output .= '</div>';
  }
  $output .= '</div>';

  return $output;
}