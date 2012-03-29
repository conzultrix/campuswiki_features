<?php

/**
 *Return the number of users tagged with a department
 *
 */
function campuswiki_departments_department_user_count($tid) {
  // create an EntityFieldQuery() to get number of users tag with the department field
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
        ->fieldCondition('field_department', 'tid', $tid)
        ->addMetaData('account', user_load(1));
        
  return $query->count()->execute();
}