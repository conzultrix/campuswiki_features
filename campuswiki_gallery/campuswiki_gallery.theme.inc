<?php


function campuswiki_gallery_preprocess_node(&$var) {
  
  $node = $var['node'];
  
  if ($node->type == 'album') {
    $photo_count = campuswiki_gallery_photo_count($node);
    $var['album_info'] = '<div class="album-cover-info overlay"> <h3>' . l($node->title, 'node/' . $node->nid) . '</h3><div class="album-photo-count">' . t('@count @text', array('@count' => $photo_count, '@text' => $photo_count > 1 ? 'photos' : 'photo')) . '</div></div>';
    
    // build the reference link from Album to Photo
    // replacement for nodereference_url using entityreference_propopulate
    if (isset($var['content']['links']) && user_access('create photo content')) {
      $var['content']['links']['add_photo'] = campuswiki_gallery_add_photo_link($node); //dpm($var);
      //unset($var['content']['links']['nodereference_url']);
    }
  }
}