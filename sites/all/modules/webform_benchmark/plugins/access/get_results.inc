<?php

$plugin = array(
  'title' => t("Has submitted all assessments"),
  'description' => t('Control access by checking that the user has submitted all assessments.'),
  'callback' => 'get_results_access_check',
  //'default' => array('vid' => array(), 'negate' => 0),
  //'settings form' => 'nsteez_term_child_access_settings',
  //'settings form validation' => 'nsteez_term_child_access_settings_validate',
  //'settings form submit' => 'nsteez_term_child_access_settings_submit',
  //'summary' => 'nsteez_term_child_access_summary',
  //'required context' => new ctools_context_required(t('Term'), array('term', 'terms')),
);

function get_results_access_check() {
  global $user;
  if ($user->uid == 1) {
    return TRUE;
  }
  //if ($user->uid == 1) { return TRUE; }
  module_load_include('inc', 'webform', 'includes/webform.submissions');
 // $nids = array(111, 144, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125);
 $nids = array(144, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552);
  foreach ($nids as $nid) {
    $submission = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
    //printr($submission);
    if ($submission) {
      continue;
    }
    else {
      return FALSE;
    }
  }
  
  return TRUE;
}
