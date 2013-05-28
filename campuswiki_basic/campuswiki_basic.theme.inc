<?php

/**
 * Add an href-based class to links for themers to implement icons.
 */
function campuswiki_basic_icon_links(&$links) {
  if (!empty($links)) {
    foreach ($links as $k => $v) {
      if (empty($v['attributes'])) {
        $v['attributes'] = array('class' => '');
      }
      else if (empty($v['attributes']['class'])) {
        $v['attributes']['class'] = '';
      }
      $v['attributes']['class'] .= ' icon-'. _campuswiki_basic_icon_class($v['href']);

      // Detect and replace counter occurrences with markup.
      $start = strpos($v['title'], '(');
      $end = strpos($v['title'], ')');
      if ($start !== FALSE && $end !== FALSE && $start < $end) {
        $v['title'] = strtr($v['title'], array('(' => "<span class='count'>", ')' => "</span>"));
      }

      $v['title'] = filter_xss_admin("<span class='icon'></span><span class='label'>". $v['title'] ."</span>");
      $v['html'] = TRUE;
      $links[$k] = $v;
    }
  }
}

/**
 * Generate an icon class from a path.
 */
function _campuswiki_basic_icon_class($path) {
  $path = drupal_get_path_alias($path);
  return str_replace('/', '-', $path);
}