<?php

class webform_benchmark_handler_field_has_submitted extends views_handler_field_boolean {
  function pre_render(&$values) {
    global $user;
    
    foreach ($values as $index => $result) {
      $nid = $result->nid;
      $values[$index]->webform_nid = webform_benchmark_has_submitted($nid, $user->uid);
    }
  }
}
