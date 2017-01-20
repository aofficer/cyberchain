<?php

$plugin = array(
  'title' => t('Webform node from submission'),
  'keyword' => 'webform_node_from_submission',
  'description' => t('Get the node associated with a webform submission.'),
  'required context' => new ctools_context_required(t('Webform submission'), 'webform_submission'),
  'context' => 'webform_node_from_submission_context',
  //'edit form' => 'ctools_term_from_node_settings_form',
  //'defaults' => array('vid' => ''),
);

function webform_node_from_submission_context($context, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('node');
  }
  
  if (isset($context->data->nid)) {
    $node = node_load($context->data->nid);
    if ($node) {
      //printr($node);
      return ctools_context_create('node', $node);
    }
  }
  
  return FALSE;
}
