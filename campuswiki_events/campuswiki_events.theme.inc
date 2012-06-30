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
    dpm(campuswiki_events_allow_rsvp($node));
  }
}