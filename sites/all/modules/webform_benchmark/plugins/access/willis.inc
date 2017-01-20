<?php

$plugin = array(
  'title' => t("Has submitted part 1 and 2 and should see  Willis"),
  'description' => t('Control access by checking that the user has submitted the assessments in part 1 and 2 and is publicly traded in the U.S.'),
  'callback' => 'willis_access_check',
  //'default' => array('vid' => array(), 'negate' => 0),
  //'settings form' => 'nsteez_term_child_access_settings',
  //'settings form validation' => 'nsteez_term_child_access_settings_validate',
  //'settings form submit' => 'nsteez_term_child_access_settings_submit',
  //'summary' => 'nsteez_term_child_access_summary',
  //'required context' => new ctools_context_required(t('Term'), array('term', 'terms')),
);

function willis_access_check() {
  global $user;
  //return FALSE;
  if ($user->uid == 1) {
    //return TRUE;
  }
  
  $nids = array(111, 144);
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  // load first two assesments
  foreach ($nids as $nid) {
    $submission = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
    if (!$submission) {
      return FALSE;
    }
  }
  //load section 10 of third assessment
    $nid = 125;
    $submission_data = current(webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0)))->data;
    if (isset($submission_data[8]['value'][0])) {
        if ($submission_data[8]['value'][0] == 'Yes'){
          return TRUE;
        }
     
    }
  
  
  return FALSE;
}
