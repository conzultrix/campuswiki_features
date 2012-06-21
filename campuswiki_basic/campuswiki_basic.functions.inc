<?php

/**
 * Pre render function for links arry in a list item
 */
function campuswiki_basic_item_list_child_render($elements) {
  foreach (array_keys($elements['#items']) AS $key) {
    // Take the renderable array of links and render it into string
    // that theme_item_list() expects.
    if (is_array($elements['#items'][$key]['data'])) {
      $elements['#items'][$key]['data'] =
      drupal_render($elements['#items'][$key]['data']);
    }
  }
  return $elements;
}