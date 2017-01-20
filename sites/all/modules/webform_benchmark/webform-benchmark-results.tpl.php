<?php //printr($components); ?>
<!--<table class="community-framework">-->
 <a href="https://cyberchain-dev.rhsmith.umd.edu/admin/reports/benchmark/csv">Download CSV File</a> 
<table >
  <tr>
    <td>User</td>
    <td>Identify</td>
    <td>Protect</td>
    <td>Detect</td>
    <td>Respond</td>
    <td>Recover</td>
    <td>Tier 1</td>
    <td>Tier 2</td>
    <td>Tier 3</td>
  </tr>
  <?php foreach ($userids as $idx => $uid) {?>
  	<tr>
  		<td><?php print $uid;?></td>
    <td><?php print $exec[$idx][1];?></td>
    <td><?php print $exec[$idx][2];?></td>
    <td><?php print $exec[$idx][3];?></td>
    <td><?php print $exec[$idx][4];?></td>
    <td><?php print $exec[$idx][5];?></td>
    <td><?php print $tier[$idx][1];?></td>
    <td><?php print $tier[$idx][2];?></td>
    <td><?php print $tier[$idx][3];?></td>
  	</tr>
  <?php } ?>


</table>

