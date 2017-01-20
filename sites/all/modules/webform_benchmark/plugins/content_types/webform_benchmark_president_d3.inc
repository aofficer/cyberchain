<?php

$plugin = array(
  // the title in the admin
  'title' => t('President initiative score (D3)'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Assessments'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_president_d3_render',
);

function webform_benchmark_president_d3_render($subtype, $conf, $args) {
  global $user;
  $uid = $user->uid;
  
  $block = new stdClass();
  $block->content = '';
  
  if (!module_exists('cybercharts')) {
    $block->content = "No cybercharts? DOH!";    
    return $block;
  }
  
  $points = webform_benchmark_get_president_initiative_score_2($uid);
  $possible_points = webform_benchmark_get_president_initiative_possible_points_2($uid);
  $subscores = webform_benchmark_get_president_initiative_subscores_2($uid);
  
  $identify['title'] = 'Identify';
  $identify['total'] = $points[1];
  $identify['possible'] = $possible_points[1];
  $identify['subscores'] = $subscores[1];
  
  $protect['title'] = 'Protect';
  $protect['total'] = $points[2];
  $protect['possible'] = $possible_points[2];
  $protect['subscores'] = $subscores[2];
  
  $detect['title'] = 'Detect';
  $detect['total'] = $points[3];
  $detect['possible'] = $possible_points[3];
  $detect['subscores'] = $subscores[3];
  
  $respond['title'] = 'Respond';
  $respond['total'] = $points[4];
  $respond['possible'] = $possible_points[4];
  $respond['subscores'] = $subscores[4];
  
  $recover['title'] = 'Recover';
  $recover['total'] = $points[5];
  $recover['possible'] = $possible_points[5];
  $recover['subscores'] = $subscores[5];
  
  $block->content .= cybercharts_render(array(1=>$identify, 2=>$protect, 3=>$detect, 4=>$respond, 5=>$recover));
  
  return $block;
}
