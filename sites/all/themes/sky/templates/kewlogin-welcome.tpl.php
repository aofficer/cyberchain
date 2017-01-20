Why hello there, <?php print $user->name; ?>.
<?php print l('Profile', 'user'); ?> | <?php print l('Account settings', "user/$user->uid/edit"); ?> | <?php print l('Logout', 'user/logout'); ?>
