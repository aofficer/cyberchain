<?php

$plugin = array(
  // the title in the admin
  'title' => t('All Assessments Scores'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Assessments'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_assessments_render',
);

function webform_benchmark_assessments_render($subtype, $conf, $args) {
  global $user;
  
  $uid = $user->uid;
  //if (!$uid) return;
  //printr($uid);
  
  $block = new stdClass();
  $responses = 60;
  $points = webform_benchmark_get_president_initiative_score_2($uid);
  //printr($points);
  //printr($points);
  $function1['total'] = $points[1];
  $function1['possible'] = 60;
  $function2['total'] = $points[2];
  $function2['possible'] = 98 ;
  $function3['total'] = $points[3];
  $function3['possible'] = 22;
  $function4['total'] = $points[4];
  $function4['possible'] = 16;
  $function5['total'] = $points[5];
  $function5['possible'] = 14;
  
  $points = webform_benchmark_get_community_framework_score_2($uid);
  //printr($points);
  //printr($points);
  $tier1['total'] = $points[1];
  $tier1['possible'] = 54;
  $tier2['total'] = $points[2];
  $tier2['possible'] = 70;
  $tier3['total'] = $points[3];
  $tier3['possible'] = 86;


  $block->content = theme('webform_benchmark_results', array('tier1' => $tier1, 'tier2' => $tier2, 'tier3' => $tier3, ));
  //printr($tier1);
  return $block;
  
}
