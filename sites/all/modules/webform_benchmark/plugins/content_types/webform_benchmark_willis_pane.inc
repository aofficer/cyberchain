<?php

$plugin = array(
  // the title in the admin
  'title' => t('Willis results'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Webform'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_willis_results_pane_render',
);

function webform_benchmark_willis_results_pane_render($subtype, $conf, $args) {
  global $user;
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  
  $block = new stdClass();
  $uid = $user->uid;
  $nid = 355; //willis survey
  $submission = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
  $nid = 125; //Control 10 where user chooses industry
  $control_10_submission = current(webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0)))->data;
  //print_r($control_10_submission);

  
  
  $willis_survey = node_load($nid);
  $fortune1000 = node_load(357);
  $industry = node_load(357);

  //print_r($control_10_submission[9]['value'][0]);
  switch(trim($control_10_submission[9]['value'][0])){
  case 'Telecommunications':
  case 'Telecom':
    $industry = node_load(358);
  break;
  case 'Transportation':
  case 'Transport':
    $industry = node_load(359);
  break;
  case 'Utilities':
  case 'Util':
    $industry = node_load(360);
  break;
  case 'Media':
  case 'Media':
    $industry = node_load(361);
  break;
  case 'Miscellaneous Services':
  case 'Misc':
    $industry = node_load(362);
  break;
  case 'Professional Services':
  case 'Prof Svcs':
    $industry = node_load(363);
  break;
  case 'Real Estate':
  case 'Realty':
    $industry = node_load(364);
  break;
  case 'Retail':
  case 'Retail':
    $industry = node_load(365);
  break;
  case 'Manufacturing - Heavy Industry':
  case 'Manu HI':
    $industry = node_load(367);
  break;
  case 'Manufacturing - High Tech Aerospace':
  case 'Manu Aero':
    $industry = node_load(366);
  }
  $my_responses = current($submission)->data;
  
  $block->content = theme('willis_benchmark', array('fortune1000' => $fortune1000, 'industry' => $industry, 'my_responses' => $my_responses));
  return $block;
  //printr($subtype); 
}
