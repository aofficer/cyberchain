<?php

$plugin = array(
  // the title in the admin
  'title' => t('Peer benchmark'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Assessments'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_peer_benchmark_render',
);

function webform_benchmark_peer_benchmark_render($subtype, $conf, $args) {
  global $user;
  
  //$nids = array(144, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125);
  $block = new stdClass();
  $block->content = '';
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  module_load_include('inc', 'webform', 'includes/webform.components');
  //foreach ($nids as $nid) {
    $nid = $args[0];
    $submissions = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
    if ($submissions) {
      //printr($submissions);
      $sid = key($submissions);
      $submission = $submissions[$sid];
      //printr($submission);
      $survey = node_load($submission->nid);
      //$links[] = l($survey->title, $_GET['q'], array('fragment' => 'assessment-' . $survey->nid));
      //$block->content .= '<h2>' . $survey->title . '</h2></a>';
      $components = webform_component_list($survey);
      //printr($components);
      //printr($components);
      $counts = array();
      $key_label = array();
      $respondent_profile_buddies = webform_benchmark_get_respondent_profile_buddies($user->uid);
      foreach ($components as $cid => $question) {
        $extra = unserialize(db_query("SELECT extra FROM {webform_component} WHERE nid = :nid AND cid = :cid",
                               array(':nid' => $survey->nid, ':cid' => $cid))->fetchField());
        if (isset($extra['items'])) {
          $items = $extra['items'];
          $items = explode("\r\n", $items);
          foreach ($items as $item) {
            $split = explode('|', $item);
            $key_label[$cid][$split[0]] = isset($split[1]) ? $split[1] : $split[0];
          }
          //printr($key_label);
          //printr($question);
          //printr($survey);
          $counts[$cid]['counts'] = webform_benchmark_count_responses($survey->nid, $cid, $submission->sid, $key_label, $respondent_profile_buddies);
          $counts[$cid]['question'] = $question;
          $counts[$cid]['fieldset'] = webform_benchmark_get_parent_fieldset_title($nid, $cid);
          
        }
      }
      //printr($counts);
      $my_results = webform_get_submission($survey->nid, $submission->sid);
      $block->content .= theme('individual_score_benchmark', array('my_results' => $my_results, 'counts' => $counts,
                                                              'key_label' => $key_label));
    }

  //$block->content = theme('item_list', array('items' => $links, 'title' => 'Jump to assessments')) . $block->content;

  return $block;
}
