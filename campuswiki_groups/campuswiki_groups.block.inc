<?php

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
    $group = groupal_get_group_by_arg();

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
  
  
  return $output;
}