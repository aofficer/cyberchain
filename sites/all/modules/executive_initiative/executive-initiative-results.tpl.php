<?php 
$percent1 = round(($function1['total']/$function1['possible'])*100, 1);
$percent2 = round(($function2['total']/$function2['possible'])*100, 1);
$percent3 = round(($function3['total']/$function3['possible'])*100, 1);
$percent4 = round(($function4['total']/$function4['possible'])*100, 1);
$percent5 = round(($function5['total']/$function5['possible'])*100, 1);
?>
<table class="community-framework">
  <tr>
    <td>FUNCTION</td>
    <td></td>
    <td>Your points earned</td>
    <td>Total possible points</td>
    <td>% of extent of coverage of attributes</td>
  </tr>
  <?php //if ($tier1['possible']):?> 
  <tr>
    <td>IDENTIFY</td>
    <td><p>Asset Management</p>
  <p>Business Environment</p>
  <p>Governance</p>
  <p>Risk Assessment</p>
  <p>Risk Management</p>
</td>
    <td><?php print $function1['total']; ?></td>
    <td><?php print $function1['possible']; ?></td>
    <td><?php if ($function1['possible']): ?>
          <?php print $percent1; ?>%
        <?php else: ?>
          n/a
        <?php endif; ?>
    </td>
  </tr>
  <?php //endif; ?>
  <?php //if ($tier2['possible']):?> 
  <tr>
    <td>PROTECT</td>
    <td><p>Access Control</p>
  <p>Awareness and Training</p>
  <p>Data Security</p>
  <p>Info Protection Processes</p>
  <p>Protective Technology</p>
  <p></p></td>
    <td><?php print $function2['total']; ?></td>
    <td><?php print $function2['possible']; ?></td>
    <td><?php if ($function2['possible']): ?>
          <?php print $percent2; ?>%
        <?php else: ?>
          n/a
        <?php endif; ?></td>
  </tr>
  <?php //endif; ?>
  <?php //if ($tier3['possible']):?> 
  <tr>
    <td>DETECT</td>
    <td><p>Anomalies and Events</p>
  <p>Security Continuous Monitoring</p>
  <p>Detection Processes</p>
  <p></p>
  <p></p>
  <p></p>
  <p></p></td>
    <td><?php print $function3['total']; ?></td>
    <td><?php print $function3['possible']; ?></td>
    <td><?php if ($function3['possible']): ?>
          <?php print $percent3; ?>%
        <?php else: ?>
          n/a
        <?php endif; ?></td>
  </tr>
  <tr>
    <td>RESPOND</td>
    <td><p>Communications</p>
  <p>Analysis</p>
  <p>Mitigation</p>
  <p></p>
  <p></p>
  <p></p>
  <p></p></td>
    <td><?php print $function4['total']; ?></td>
    <td><?php print $function4['possible']; ?></td>
    <td><?php if ($function4['possible']): ?>
          <?php print $percent4; ?>%
        <?php else: ?>
          n/a
        <?php endif; ?></td>
  </tr>
  <tr>
    <td>RECOVER</td>
    <td><p>Improvements</p>
  <p>Communications</p>
  <p></p>
  <p></p>
  <p></p>
  <p></p>
  <p></p></td>
    <td><?php print $function5['total']; ?></td>
    <td><?php print $function5['possible']; ?></td>
    <td><?php if ($function5['possible']): ?>
          <?php print $percent5; ?>%
        <?php else: ?>
          n/a
        <?php endif; ?></td>
  </tr>
  <?php //endif; ?>
</table>
<br>
<h2 class="pane-title">Performance Profile</h2>
<?php if($percent1 < 75 && $percent2 < 75 && $percent3 <75  && $percent4 < 75 && $percent5 <75 ){ ?>
<p><strong>You earned 74% or less of possible total points in each Function. Your company has received a Grade C</strong> and does not meet the performance threshold. To improve your score, consider building these core capabilities and strategies as described in the table below.</p>
<?php }elseif($percent1 >= 90 && $percent2 >= 90 && $percent3 >= 90 && $percent4 >= 90 && $percent5 >= 90 ){ ?>
<p><strong>Your company received a grade of A</strong> in this function and exceeds the performance threshold</p>
<?php }else{?>
<p><strong>Your company has received a grade of B</strong> in this function and meets the performance threshold. To improve your score, consider building these core capabilities and strategies</p>
<?php }//endif?>


<?php if($percent1 < 90 || $percent2 < 90 || $percent3 < 90  || $percent4 < 90 || $percent5 < 90 ){ ?>
<br>
        <h2 class="pane-title">Suggested Improvements</h2>
    
  
    <table class="tftable" border="1"><tbody><tr><th>Function</th>
<th>Build these Core Capabilities</th>
<th>Consider these Strategic Improvements</th>
</tr>
<?php if ($percent1 < 90) { ?>
<tr><td>IDENTIFY</td>
<td>Assessing/Managing Risk Across The Enterprise</td>
<td>1) Inventory &amp; track business-critical physical devices, systems, software platforms/applications and supply chain partners 2) Identify vulnerabilities in organizational assets 3) Establish organization-wide risk management processes and escalation thresholds for incident alerts</td>
</tr>
<?php } ?>
<?php if ($percent2 < 90) { ?>
<tr><td>PROTECT</td>
<td>Hardening Defensive IT Processes/Procedures</td>
<td>1) Tighten credential management for devices and users 2) Enforce physical access control for critical IT infrastructure 3) Toughen configuration change controls for organizational systems 4) Protect wired and wireless networks through better security planning</td>

</tr>
<?php } ?>
<?php if ($percent3 < 90) { ?>
<tr><td>DETECT</td>
<td>Conducting Real Time, Continuous IT Systems’ Monitoring</td>
<td>1) Establish baseline of “normal” organizational behaviors and expected data flows 2) Utilize network traffic analysis and malicious code detection mechanisms to identify and characterize anomalies and events 3) Perform periodic vulnerability scanning, penetration testing and access control log audits to check for possible breaches</td>

</tr>
<?php } ?>
<?php if ($percent4 < 90) { ?>
<tr><td>RESPOND</td>
<td>Analyzing Breaches/Incidents &amp; Allocating Resources To Mitigate Their Impacts</td>
<td>1) Formalize policy, procedures, practice and coordination to implement agreed upon mitigation actions in response to cyber security events 2) Conduct forensics in order to classify the incident and uncover root causes</td>

</tr>
<?php } ?>
<?php if ($percent5 < 90) { ?>
<tr><td>RECOVER</td>
<td>Distilling &amp; Communicating Lessons Learned From Breaches/Incidents</td>
<td>1) Deploy Executive Recovery Planning activities to restore services or functions 2) Compare actual recovery times for key parts of the network with pre-established TTR (Time To Recover) targets 3) Distill lessons learned from cyber events, prepare after-action reports and share them with supply chain partners </td>

</tr>
<?php } ?>

</table>
<?php } //endif?>
