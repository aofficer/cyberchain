<?php

$plugin = array(
  'title' => t("Webform submission"),
  'description' => t('A single submission of a webform.'),
  'context' => 'page_steez_context_create_webform_submission',  // func to create context
  'context name' => 'webform_submission',
  //'settings form' => 'webform_submission_settings_form',
  'keyword' => 'webform_submission',

  // Provides a list of items which are exposed as keywords.
  'convert list' => 'webform_submission_convert_list',
  // Convert keywords into data.
  'convert' => 'webform_submission_convert',

  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter some data to represent this "webform_submission".'),
  ),
);

//printr('huh');

/**
 * Create a context, either from manual configuration or from an argument on the URL.
 *
 * @param $empty
 *   If true, just return an empty context.
 * @param $data
 *   If from settings form, an array as from a form. If from argument, a string.
 * @param $conf
 *   TRUE if the $data is coming from admin configuration, FALSE if it's from a URL arg.
 *
 * @return
 *   a Context object/
 */
function page_steez_context_create_webform_submission($empty, $data = NULL, $conf = FALSE) {
  //print 'wut';
  $context = new ctools_context('webform_submission');
  $context->plugin = 'webform_submission';

  if ($empty) {
    return $context;
  }

  if ($conf) {
    if (!empty($data)) {
      $context->data = new stdClass();

      return $context;
    }
  }
  else {
    $context->title = t("Webform submission #!sid", array('!sid' => $data->sid));
    $context->argument = $data->sid;
    // Make up a bogus context
    $context->data = $data;
    return $context;
  }
}

function webform_submission_convert($context, $type) {
  //return 'huh';
}

function webform_submission_convert_list() {
  
}
