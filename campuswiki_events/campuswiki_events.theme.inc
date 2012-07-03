<?php


function campuswiki_events_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'event') {
    //dpm($node);
    dpm($var);
    $var['rsvp_button'] = $var['content']['links']['nodereference_url'];
    //unset($var['content']['links']['nodereference_url']);
    //dpm($var);
    //$date = new DateObject($node->field_event_date[0]['value'], $tz = date_default_timezone_object());
    //date_timezone_set($date, date_default_timezone_object());
    dpm(campuswiki_events_allow_rsvp($node));
    /*if (!cck_signup_event_is_past($node)) {
      dpm('yes');
      unset($var['rsvp_button']);
    }*/
  }
}