<?php //printr($components); ?>

<table class="community-framework">
  <tr>
    <td></td>
    <td></td>
    <td></td>
    <td>Your points earned</td>
    <td>Total possible points</td>
    <td>% of extent of coverage of attributes</td>
  </tr>
  <?php if ($total_score[1]['possible']):?> 
  <tr>
    <td>TIER I</td>
    <td>Risk Governance</td>
    <td><p>A1 Executive Risk Governance Group</p>
  <p>A2 Extended Enterprise Risk Assessment</p>
  <p>A3 Extended Enterprise Risk Mitigation Strategy</p>
  <p>A4 Extended Enterprise Risk Monitoring</p></td>
    <td><?php print $total_score[1]['total']; ?></td>
    <td><?php print $total_score[1]['possible']; ?></td>
    <td><?php print round(($total_score[1]['total']/$total_score[1]['possible'])*100, 1); ?>%</td>
  </tr>
  <?php endif; ?>
  <?php if ($total_score[2]['possible']):?> 
  <tr>
    <td>TIER II</td>
    <td>Systems Integration</td>
    <td><p>B1 System Lifecycle Integration/Design</p>
  <p>B2 System Risk Assessment/Sourcing</p>
  <p>B3 Acquisition Risk Assessment/Sourcing</p>
  <p>B4 Mapping</p>
  <p>B5 Tracking and Visibility of Supply Chain</p>
  <p>B6 Program/Project/Process Auditing</p></td>
    <td><?php print $total_score[2]['total']; ?></td>
    <td><?php print $total_score[2]['possible']; ?></td>
    <td><?php print round(($total_score[2]['total']/$total_score[2]['possible'])*100, 1); ?>%</td>
  </tr>
  <?php endif; ?>
  <?php if ($total_score[3]['possible']):?> 
  <tr>
    <td>TIER III</td>
    <td>Operations</td>
    <td><p>C1 Plan</p>
  <p>C2 Design</p>
  <p>C3 Make</p>
  <p>C4 Source</p>
  <p>C5 Deliver</p>
  <p>C6 Return</p>
  <p>C7 Process Risk Auditing</p></td>
    <td><?php print $total_score[3]['total']; ?></td>
    <td><?php print $total_score[3]['possible']; ?></td>
    <td><?php print round(($total_score[3]['total']/$total_score[3]['possible'])*100, 1); ?>%</td>
  </tr>
  <?php endif; ?>
</table>

