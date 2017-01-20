<?php

$plugin = array(
  'title' => t("Webform submission: ID"),
  // keyword to use for %substitution
  'keyword' => 'webform_submission',
  'description' => t('Identify this argument as a webform submission ID.'),
  //'settings form' => 'page_steez_webform_submission_settings_form',
  'context' => 'page_steez_argument_webform_submission_context',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the webform submission ID for this argument.'),
  ),
  //'no ui' => TRUE,
  //'path placeholder' => 'ctools_string_path_placeholder', // This is in pagemanager.
);

function page_steez_argument_webform_submission_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('webform_submission');
  }
  if (!is_numeric($arg)) {
    return FALSE;
  }
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $submission = webform_get_submission(NULL, $arg);
  //printr($submission);
  if ($submission) {
    return ctools_context_create('webform_submission', $submission);
  }
}
