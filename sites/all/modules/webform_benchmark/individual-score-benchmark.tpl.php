<?php //printr($my_results); ?>

<?php foreach($my_results->data as $cid => $response): ?>
  <?php //printr($response); ?>
  <?php if ($counts[$cid]['fieldset']): ?>
    <?php $h = 'h4'; ?>
    <h3><?php print trim($counts[$cid]['fieldset'], '-'); ?></h3>
  <?php else: ?>
    <?php $h = 'h3'; ?>
  <?php endif; ?>
  <<?php print $h; ?>><?php print trim(trim($counts[$cid]['question'], '-'), '--'); ?></<?php print $h; ?>>
  <h5>Your response:</h5> 
  <?php foreach ($response['value'] as $answer): ?>
    <?php print $key_label[$cid][$answer]; ?><br />
  <?php endforeach; ?>
  <h5>Everyone else:</h5>
    <?php foreach ($counts[$cid]['counts'] as $label => $count): ?>
      <?php print $label; ?>: <?php print $count; ?><br />
    <?php endforeach; ?>
<?php endforeach; ?>
