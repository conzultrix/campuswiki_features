<?php

function campuswiki_gallery_photo_count($album) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'photo')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_photo_gallery', 'target_id', $album->nid)
        ->count();
  
  return $query->execute();
}


/**
 * Build a add photo link when viewing the gallery node
 *
 * @param object $gallery
 *  The gallery node
 *
 * @return array
 *  add photo link as render array
 */
function campuswiki_gallery_add_photo_link($gallery) {
  return array(
    '#theme' => 'links__node',
    '#links' => array(
      'photo_field_photo_gallery' => array(
        'title' => 'Add photo',
        'query' => array(
          'field_photo_gallery' => $gallery->nid,
          'destination' => 'node/' . $gallery->nid,
        ),
        'href' => 'node/add/photo',
        'attributes' => array(
          'title' => t('Add photo to @gallery', array('@gallery' => $gallery->title)),
        ),
      ),
    ),
    '#attributes' => array(
      'class' => array('links', 'inline'),
    ),
  );
}
