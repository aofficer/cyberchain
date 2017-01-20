<?php

$plugin = array(
  'title' => t("Has submitted part 1"),
  'description' => t('Control access by checking that the user has submitted the assessments in part 1.'),
  'callback' => 'part_1_access_check',
  //'default' => array('vid' => array(), 'negate' => 0),
  //'settings form' => 'nsteez_term_child_access_settings',
  //'settings form validation' => 'nsteez_term_child_access_settings_validate',
  //'settings form submit' => 'nsteez_term_child_access_settings_submit',
  //'summary' => 'nsteez_term_child_access_summary',
  //'required context' => new ctools_context_required(t('Term'), array('term', 'terms')),
);

function part_1_access_check() {
  global $user;
  
  if ($user->uid == 1) {
    return TRUE;
  }
  
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $submission = webform_get_submissions(array('nid' => 111, 'uid' => $user->uid, 'is_draft' => 0));
  
  return $submission ? TRUE : FALSE;
}
