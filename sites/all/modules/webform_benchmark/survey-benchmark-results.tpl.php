<h2>Capability score: <?php print $cscore['total']; ?> / <?php print $cscore['possible']; ?></h2>
<?php if (!empty($stats_lists)): ?>
  <?php foreach($stats_lists as $cid => $component_stats): ?>

    <?php print theme('item_list', array('title' => $component_stats['title'], 'items' => $component_stats['data'])); ?>
    <?php print $charts[$cid]; ?>
  <?php endforeach; ?>
<?php else: ?>
  There are no survey submissions to benchmark against right now.
<?php endif; ?>