<?php

$plugin = array(
  // the title in the admin
  'title' => t('View results page'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Assessments'), -9),
  //'edit form' => 'page_steez_page_pane_content_type_edit_form',
  'render callback' => 'webform_benchmark_view_results_render',
);

function webform_benchmark_view_results_render($subtype, $conf, $args) {
  global $user;
  //printr($user);
  $block = new stdClass();
  $output = '';
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $nids = array(111, 144, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125);
  $links = array();
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $submission = webform_get_submissions(array('nid' => $nid, 'uid' => $user->uid, 'is_draft' => 0));
    if ($node && $submission) {
      $sid = key($submission);
      $links[] = l($node->title, 'node/' . $node->nid . '/submission/' . $sid);
    }
    
    
    /*if ($submission) {
      $menu_submission = webform_menu_submission_load($submission->sid);
      //printr(webform_submission_page($node, $submission, 'html'));
      $output .= drupal_render(webform_submission_page($node, $menu_submission, 'html'));
    }*/
    
  }
$output .= theme('item_list', array('items' => $links));
  
  $block->content = $output;
  
  return $block;

}
