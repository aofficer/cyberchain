<?php

$plugin = array(
  // the title in the admin
  'title' => t('Capability score'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Webform'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_capability_score_render',
);

function webform_benchmark_capability_score_render($subtype, $conf, $args) {
  $block = new stdClass();
  
  $uid = $args[0];
  $sid = $args[1];
  
  $submission = webform_get_submission(NULL, $sid);
  $score = webform_benchmark_get_capability_score($submission->sid);
  $survey = node_load($submission->nid);
  
  $user = user_load($uid);
  /*$profile_type = variable_get('webform_benchmark_profile_type', '');
  $profile = profile2_load_by_user($user, $profile_type);
  $industry_type_field = variable_get('webform_benchmark_industry_type_field', '');
  $industry_size_field = variable_get('webform_benchmark_industry_size_field', '');
  if (!isset($_GET['industry_type']) || (isset($_GET['industry_type']) && !$_GET['industry_type'])) {
    $industry_type_tid = $profile->{$industry_type_field}['und'][0]['tid'];
  }
  else {
    $industry_type_tid = $_GET['industry_type'];
  }
  if (!isset($_GET['industry_size']) || (isset($_GET['industry_size']) && !$_GET['industry_size'])) {
    $industry_size_tid = $profile->{$industry_size_field}['und'][0]['tid'];
  }
  else {
    $industry_size_tid = $_GET['industry_size'];
  }
  $profile_values = array($industry_type_field => $industry_type_tid,
                          $industry_size_field => $industry_size_tid);
  $uids_to_benchmark = webform_benchmark_get_users_by_profile_values($profile_values, $user->uid);*/
  
  // get uids by answers to respondent profile
  $benchmark_nid = 111; // this is fixed
  $benchmark_uid = $uid;
  $benchmark_sid = db_query("SELECT sid FROM {webform_submissions} WHERE uid = :uid AND nid = :nid",
                             array(':uid' => $benchmark_uid, ':nid' => $benchmark_nid))->fetchField();
  $components = array();
  $components[$benchmark_nid] = array(1, 2, 3, 4, 5, 6, 7, 8, 9);
  $values = webform_benchmark_get_component_values($benchmark_sid, $components);
  printr($values);
  //return;
  $uids_to_benchmark = webform_benchmark_get_users_by_survey_results($benchmark_nid, $values);
  //printr($uids_to_benchmark);
  
  //printr($uids_to_benchmark);
  //printr($basics_profile);
  
  // get all the users that we're going to benchmark against
  /*$uids = db_query("SELECT uid FROM {webform_submissions}
                    WHERE nid = :nid AND uid <> :uid",
                    array(':nid' => $survey->nid, ':uid' => $uid))->fetchCol();*/
  
  //printr($uids);
  // get all the componenents associated with this survey
  $components = db_query("SELECT * FROM {webform_component} WHERE nid = :nid",
                    array(':nid' => $survey->nid))->fetchAllAssoc('cid');
  //printr($submission);
  $results = array();
  $points = array();
  $key_label = array();
  if (!empty($uids_to_benchmark)) {
    foreach ($components as $cid => $component) {
      if (isset($submission->data[$cid])) {
        $key_label[$cid] = webform_benchmark_get_key_label($survey->nid, $cid);
        $most_popular_responses[$cid] = webform_benchmark_get_most_popular_response($survey->nid, $cid, $uids_to_benchmark);
        $my_responses[$cid] = $submission->data[$cid]['value'][0];
        $cur_points = webform_weight_get_points($survey->nid, $cid);
        $possible_points[$cid] = $cur_points ? $cur_points : 0;
        if ($cur_points && $most_popular_responses[$cid] == $my_responses[$cid]) {
          $points[$cid] = $cur_points;
          //$possible_points[$cid] = $
        }
        else {
          $points[$cid] = 0;
        }
      }
      //$results[$cid] = webform_benchmark_benchmark_component($survey->nid, $cid, $uids_to_benchmark);
    }
  }
  
  $block->content = theme('capability_score_benchmark', array('components' => $components, 'popular' => $most_popular_responses,
                                                              'my_responses' => $my_responses, 'points' => $points,
                                                              'key_label' => $key_label, 'score' => $score,
                                                              'possible_points' => $possible_points));
  //printr($results);
                
  //$block->content = theme('survey_benchmark_results', array('results' => $results, 'components' => $components,
  //                                                          'sid' => $sid, 'key_label' => $key_label));
  
  return $block;
  //printr($subtype); 
}