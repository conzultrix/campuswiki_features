<?php

module_load_include('inc', 'campuswiki_basic', 'campuswiki_basic.functions');
module_load_include('inc', 'campuswiki_groups', 'campuswiki_groups.functions');



/**
 * Create a group information block
 *
 */
function campuswiki_groups_info_block() {
  $output = array();
  
  $group = og_context();
  dpm($group);
  
  $is_private = FALSE;

  if (empty($group)) {

    // If there is no group at this point we might be viewing
    // a private group page. In that case we still want to
    // to display this block, so try to retrieve it manually from the arg.
    $group = campuswiki_groups_get_group_by_arg();

    // Private groups will see the data but no link for many of the items
    // in this block.
    $is_private = TRUE;

    // Still no group? This is not a group page.
    if (empty($group)) {
      return $output;
    }
  }
  
  $gid = $group->gid;

  $group_node = node_load($group->etid);
  dpm($group_node);
  
  if (!empty($group_node->field_group_photo)) {
    $output['image'] = array(
      '#theme' => 'image_formatter',
      '#item' => $group_node->field_group_photo['und'][0],
      '#image_style' => 'sidebar',
    );
  }
  
  // add group fonded date
  $output['funded'] = array(
    '#markup' => t('Founded @date', array('@date' => format_date($group_node->created, 'custom', 'd M Y'))),
    '#prefix' => '<div class="founded">',
    '#suffix' => '</div>',
  );
  
  if (!empty($group_node->field_campus_audience)) {
    $tid = $group_node->field_campus_audience['und'][0]['tid'];
    
    $audience = taxonomy_term_load($tid);
    $name = t('@name', array('@name' => $audience->name));
    
    $output['audience'] = array(
      '#prefix' => '<div class = "audience-link">',
      '#suffix' => '</div>',
      '#type' => 'link',
      '#title' => $name,
      '#href' => 'taxonomy/term/' . $tid,
      '#options' => array(
        'attributes' => array(
        'class' => array('audience'),
        'title' => $name . t(' page'),
        ),
      ),
    );
  }
  
  // creating Group info menu
  // initailize the items array to hold the links
  $items = array();
  
  // the home link
  $label = t('Wall');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid,
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // Members link
  $label = t('Members');
  $count = campuswiki_groups_member_count($gid);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/members',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // upcoming events
  $label = t('Upcoming events');
  $count = campuswiki_groups_upcoming_events_count($gid);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/events',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
    // past events
  $label = t('Past events');
  $count = campuswiki_groups_past_events_count($gid);
  $title = '<span class="label">' . $label . '</span><span class="count">' . $count . '</span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/past-events',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('count-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  // events calendar
  $label = t('Calendar');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/calendar',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // wiki
  $label = t('Wiki');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/wiki',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // Gallery
  $label = t('Gallery');
  $title = '<span class="label">' . $label . '</span><span class="icon"></span>';
  $items[] = array(
    'data' => array(
      '#type' => 'link',
      '#title' => $title,
      '#href' =>  'node/' . $group_node->nid . '/gallery',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('icon-' . strtolower($label)),
        ),
      ),
    ),
  );
  
  
  // build a list of the links
  $output['menu'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#prefix' => '<div id="group-info-block-menu">',
    '#suffix' => '</div>',
    '#pre_render' => array('campuswiki_basic_item_list_child_render'),
  );
  
  // Add group Manager(s) info
  $manager_uids = array($group_node->uid);
  $role = og_role_load(3);
  foreach (og_get_users_by_roles($gid, array(3)) as $item) {
    $manager_uids[] = $item->uid;
  }
  $manager_uids = array_unique($manager_uids);
  
  $first = TRUE;
  $header = count($manager_uids) > 1 ? t('Managers:') . '<br />': t('Manager:') . '<br />';
  $names = array();
  foreach ($manager_uids as $uid) {
    $account = user_load($uid);
    $names[] =  l($account->name, 'user/' . $account->uid);
    if ($first) {
      $picture = theme('user_picture', array('account' => $account));
    }
    $first = FALSE;
  }
  
  // reset $items array
  $items = array();
  
  // add Managers' names and $picture to $tiems
  $items[] = array(
    'data' => $header . implode(', ', $names),
    'class' => array('group-info-manager-name'),
  );
  
  $items[] = array(
    'data' => $picture,
    'class' => array('group-info-manager-picture'),
  );
  
  
  $output['manager'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#prefix' => '<div id="group-info-block-manager">',
    '#suffix' => '</div>',
  );

  
  return $output;
}