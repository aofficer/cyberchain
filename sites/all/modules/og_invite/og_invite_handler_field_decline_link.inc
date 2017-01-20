<?php

class og_invite_handler_field_decline_link extends views_handler_field {
  function render($values) {
    //printr($values);
    return l(t('Decline'), 'og-invite/invite-response/' . $values->og_invite_hash . '/decline');
  }
}
