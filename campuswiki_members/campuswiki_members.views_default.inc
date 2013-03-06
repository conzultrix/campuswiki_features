<?php
/**
 * @file
 * campuswiki_members.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function campuswiki_members_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campuswiki_members';
  $view->description = 'Listing of all member';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'campuswiki members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'sidebar';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_user_department']['id'] = 'field_user_department';
  $handler->display->display_options['fields']['field_user_department']['table'] = 'field_data_field_user_department';
  $handler->display->display_options['fields']['field_user_department']['field'] = 'field_user_department';
  $handler->display->display_options['fields']['field_user_department']['label'] = '';
  $handler->display->display_options['fields']['field_user_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_department']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Department (field_user_department) */
  $handler->display->display_options['filters']['field_user_department_tid']['id'] = 'field_user_department_tid';
  $handler->display->display_options['filters']['field_user_department_tid']['table'] = 'field_data_field_user_department';
  $handler->display->display_options['filters']['field_user_department_tid']['field'] = 'field_user_department_tid';
  $handler->display->display_options['filters']['field_user_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_department_tid']['expose']['operator_id'] = 'field_user_department_tid_op';
  $handler->display->display_options['filters']['field_user_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_user_department_tid']['expose']['operator'] = 'field_user_department_tid_op';
  $handler->display->display_options['filters']['field_user_department_tid']['expose']['identifier'] = 'field_user_department_tid';
  $handler->display->display_options['filters']['field_user_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_user_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_department_tid']['vocabulary'] = 'campus_audience';
  $handler->display->display_options['filters']['field_user_department_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'members';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Members';
  $handler->display->display_options['menu']['name'] = 'features';
  $export['campuswiki_members'] = $view;

  return $export;
}
