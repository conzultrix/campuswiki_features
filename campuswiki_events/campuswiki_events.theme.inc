<?php


function campuswiki_events_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'event') { //dpm($node);
    $var['rsvp_link'] = campuswiki_events_return_signup_link($node);
  
    $var['rsvp_badge'] = array(
      '#theme' => 'campuswiki_events_rsvp_badge',
      '#nid' => $node->nid,
      '#link' => $var['rsvp_link'],
    );
    
    $var['rsvp_button'] = array(
      '#theme' => 'campuswiki_events_rsvp_button',
      '#nid' => $node->nid,
      '#link' => $var['rsvp_link'],
    ); 
    
    if (!campuswiki_events_allow_rsvp($node)) {
      $var['attendee_count'] = NULL;
    }
    else {
      $var['attendee_count'] = '<div class="event-attendance">' . t('@count @action', array(
        '@count' => campuswiki_events_attendee_count($node), 
        '@action' => (campuswiki_events_event_is_past($node) ? t('attended') : t('attending')),
      ))  . '</div>';
      
    }
    
    $var['attendee_images'] = '<div class="attendee-images clearfix">' . implode(' ', campuswiki_events_attendees($node, 'picture')) . '</div>';
    $var['attendee_names'] = '<div class="attendee-names">' . implode(', ', campuswiki_events_attendees($node, 'name')) . '</div>';
  
    
    
    if ($count = campuswiki_events_comment_count($node)) {
      $var['comment_count'] = '<div class="event-comment">' . t('@count @text', array(
        '@count' => $count,
        '@text' => $count > 1 ? 'comments' : 'comment',
      )) . '</div>';
    }
    else {
      $var['comment_count'] = NULL;
    }
    
    //format date like a mini calendar
    $date = new DateObject($node->field_event_date[LANGUAGE_NONE][0]['value'], 'UTC');
    date_timezone_set($date, date_default_timezone_object());
    $var['event_calendar_day'] = theme('date_calendar_day', array('date' => $date));
    
    // get information about the venue of an event
    if (!empty($node->field_venue)) {
      $venue = $node->field_venue[LANGUAGE_NONE][0]['value'];
      $var['venue_formatted_text'] = '<span class="event-venue-formatted">' . t('at @venue', array('@venue' => $venue));
    }
  }
}


function theme_campuswiki_events_flipcard ($var) {
  $output = '';
  $nid = $var['nid'];
  $node = node_load($nid);
  $remaining = campuswiki_events_get_remaining_capacity($node);
  
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
  $output = '';
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

function theme_campuswiki_events_rsvp_button($var) {
  $output = '';
  $nid = $var['nid'];
  $node = node_load($nid);
  $link = $var['link'];
  
  $output .= '<div class="rsvp-button clearfix">';
  if (campuswiki_events_show_rsvp_link($node)) {
    $output .= '<div class="rsvp-link">';
    $output .= is_array($link) ? drupal_render($link) : $link;
    $output .= '</div>';
  }
  $output .= '</div>';
  
  return $output;
  
}