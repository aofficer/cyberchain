<?php

class og_invite_handler_field_accept_link extends views_handler_field {
  function render($values) {
    //printr($values);
    return l(t('Accept'), 'og-invite/invite-response/' . $values->og_invite_hash . '/accept');
  }
}
