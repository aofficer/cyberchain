<?php

$plugin = array(
  // the title in the admin
  'title' => t('Individual score'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Webform'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_individual_score_render',
);

function webform_benchmark_individual_score_render($subtype, $conf, $args) {
  $block = new stdClass();
  
  $uid = $args[0];
  $sid = $args[1];
  
  $submission = webform_get_submission(NULL, $sid);
  $survey = node_load($submission->nid);
  
  module_load_include('inc', 'webform', 'includes/webform.components');
  $components = webform_component_list($survey);
  //printr($components);
  $counts = array();
  $key_label = array();
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
      
      $counts[$cid]['counts'] = webform_benchmark_count_responses($survey->nid, $cid, $submission->sid, $key_label);
      $counts[$cid]['question'] = $question;
    }
  }
  
  //printr($counts);
  
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $my_results = webform_get_submission($survey->nid, $submission->sid);
  $block->content = theme('individual_score_benchmark', array('my_results' => $my_results, 'counts' => $counts,
                                                              'key_label' => $key_label));
  
  return $block;
  //printr($counts);
}
