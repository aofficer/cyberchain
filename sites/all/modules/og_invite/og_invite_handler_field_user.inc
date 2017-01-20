<?php

class og_invite_handler_field_user extends views_handler_field_user_name {
  function init(&$view, &$data) {
    parent::init($view, $data);
    if (!empty($this->options['overwrite_anonymous']) || !empty($this->options['format_username']) || !empty($this->options['link_to_user'])) {
      $this->additional_fields['uid'] = 'invitee';
    }
  }
}
