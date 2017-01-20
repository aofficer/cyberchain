<?php

/** Implements hook_views_data() **/
function webform_benchmark_views_data_alter(&$data) {
  $data['webform']['has_submitted'] = array(
    'real field' => 'nid',
    //'alias' => 'has_submitted',
    'field' => array(
      'title' => t('Has submitted webform'),
      'help' => t('Boolean indicating wether or not the current user has submitted the webform.'),
      'handler' => 'webform_benchmark_handler_field_has_submitted',
    ),
  );
}
