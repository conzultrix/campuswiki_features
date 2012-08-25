<?php


function campuswiki_wiki_preprocess_node(&$var) {
  global $user;
  
  $node = $var['node'];
  
  if ($node->type == 'wiki') {
    dpm($var);
    if (module_exists('talk')) {
      // remove the add comment link to allow
      // only the discuss link
      
      if ($var['view_mode'] == 'full') {
        if (isset($var['content']['links']['comment']['#links'][0])) {
          unset($var['content']['links']['comment']['#links'][0]);
        }
      }
    }
    
  }
}