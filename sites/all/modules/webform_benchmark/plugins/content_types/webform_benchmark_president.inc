<?php

$plugin = array(
  // the title in the admin
  'title' => t('President initiative score'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Assessments'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_president_render',
);

function webform_benchmark_president_render($subtype, $conf, $args) {
  global $user;
  
  $uid = $user->uid;
  //if (!$uid) return;
  //printr($uid);
  
  $block = new stdClass();
  if ($uid == 1 || 1==1) {
    $points = webform_benchmark_get_president_initiative_score_2($uid);
    $possible = webform_benchmark_get_president_initiative_possible_points_2($uid);
    
    $tier1['total'] = $points[1];
    $tier1['possible'] = $possible[1];
    $tier2['total'] = $points[2];
    $tier2['possible'] = $possible[2];
    $tier3['total'] = $points[3];
    $tier3['possible'] = $possible[3];
    $tier4['total'] = $points[4];
    $tier4['possible'] = $possible[4];
    $tier5['total'] = $points[5];
    $tier5['possible'] = $possible[5];
  }
  else { //currently disabled
    $tier1 = webform_benchmark_get_community_framework_score($uid, 1);
    $tier1['possible'] = 60;
    //printr($tier1);
    $tier2 = webform_benchmark_get_community_framework_score($uid, 2);
    $tier2['possible'] = 98 ;
    $tier3 = webform_benchmark_get_community_framework_score($uid, 3);
    $tier3['possible'] = 22;
    $tier4 = webform_benchmark_get_community_framework_score($uid, 4);
    $tier4['possible'] = 16;
    $tier5 = webform_benchmark_get_community_framework_score($uid, 5);
    $tier5['possible'] = 14;
  }
  
  $block->content = theme('executive_initiative_results', array('function1' => $tier1, 'function2' => $tier2, 'function3' => $tier3, 'function4' => $tier4, 'function5' => $tier5));
  //printr($tier1);
  return $block;
  
  //$nids = array(144, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125);
  $block = new stdClass();
  $block->content = '';
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $scores = array();
  $total_score = array(1 => array('total' => 0, 'possible' => 0),
                         2 => array('total' => 0, 'possible' => 0),
                         3 => array('total' => 0, 'possible' => 0),);
  //foreach ($nids as $nid) {
  for ($nid=531; $nid<553; $nid++) {
    $submissions = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
    $survey = node_load($nid);
    //printr($survey);
    //printr($submissions);
    $block->content .= '<a name="assessment-' . $survey->nid . '"><h2>' . $survey->title . '</h2></a>';
    $sid = key($submissions);
    
    //printr($total_score);
    if ($submissions && !empty($submissions[$sid])) {
      //printr($submissions);
      $sid = key($submissions);
      //printr($sid);
      $submission = $submissions[$sid];
      //printr($submission);
      $score = webform_benchmark_get_capability_score($submission->sid);
      printr($score);
      $scores[$nid] = $score;
      $total_score[1]['total'] += $score['tiers'][1]['total'];
      $total_score[1]['possible'] += $score['tiers'][1]['possible'];
      $total_score[2]['total'] += $score['tiers'][2]['total'];
      $total_score[2]['possible'] += $score['tiers'][2]['possible'];
      $total_score[3]['total'] += $score['tiers'][3]['total'];
      $total_score[3]['possible'] += $score['tiers'][3]['possible'];
      
      $total_score[1]['possible'] = 48;
      $total_score[2]['possible'] = 44;
      $total_score[3]['possible'] = 76;
    }
    else {
      //$block->content .= '<h4>You have no peers to benchmark against right now.</h4>';
    }
  }
  $block->content = theme('capability_score_benchmark', array('total_score' => $total_score));
  //printr($total_score);

  //$block->content = theme('item_list', array('items' => $links, 'title' => 'Jump to assessments')) . $block->content;
  return $block;
}
