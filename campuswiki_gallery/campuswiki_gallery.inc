<?php

function campuswiki_gallery_photo_count($album) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'photo')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_photo_album', 'nid', $album->nid)
        ->count();
  
  return $query->execute();
}