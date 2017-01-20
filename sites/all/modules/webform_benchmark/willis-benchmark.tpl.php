<?php
//print_r($my_responses);
//print ('<br/>');
//print_r($fortune1000);
//print_r($fortune1000->field_privacy_loss_of_confidenti['und'][0]);
?>
        <h2 class="pane-title">Reported Exposures</h2>
    
  
    <table class="tftable" border="1"><tbody><tr><th>Reported Exposures</th>
<th>Fortune 1000 - % of companies reporting</th>
<th><?php print($industry->title);?>  - % of companies reporting</th>
<th>Your Company's Reported Exposures</th>
</tr><tr><td>Privacy/Loss of Confidential Data</td>
<td><?php print($fortune1000->field_privacy_loss_of_confidenti['und'][0]['value']);?>%</td>
<td><?php print($industry->field_privacy_loss_of_confidenti['und'][0]['value']);?>%</td>
<td><?php if(in_array('A',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Reputation Risk</td>
<td><?php print($fortune1000->field_reputation_risk['und'][0]['value']);?>%</td>
<td><?php print($industry->field_reputation_risk['und'][0]['value']);?>%</td>
<td><?php if(in_array('B',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Malicious Acts</td>
<td><?php print($fortune1000->field_malicious_acts['und'][0]['value']);?>%</td>
<td><?php print($industry->field_malicious_acts['und'][0]['value']);?>%</td>
<td><?php if(in_array('C',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Liability</td>
<td><?php print($fortune1000->field_liability['und'][0]['value']);?>%</td>
<td><?php print($industry->field_liability['und'][0]['value']);?>%</td>
<td><?php if(in_array('D',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber Terrorism</td>
<td><?php print($fortune1000->field_cyber_terrorism['und'][0]['value']);?>%</td>
<td><?php print($industry->field_cyber_terrorism['und'][0]['value']);?>%</td>
<td><?php if(in_array('E',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber Regulatory Risk</td>
<td><?php print($fortune1000->field_cyber_regulatory_risk['und'][0]['value']);?>%</td>
<td><?php print($industry->field_cyber_regulatory_risk['und'][0]['value']);?>%</td>
<td><?php if(in_array('F',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Business Interruption</td>
<td><?php print($fortune1000->field_business_interruption['und'][0]['value']);?>%</td>
<td><?php print($industry->field_business_interruption['und'][0]['value']);?>%</td>
<td><?php if(in_array('G',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Errors and Malfunction</td>
<td><?php print($fortune1000->field_errors_and_malfunction['und'][0]['value']);?>%</td>
<td><?php print($industry->field_errors_and_malfunction['und'][0]['value']);?>%</td>
<td><?php if(in_array('H',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Outsourced Vendor Risk</td>
<td><?php print($fortune1000->field_outsourced_vendor_risk['und'][0]['value']);?>%</td>
<td><?php print($industry->field_outsourced_vendor_risk['und'][0]['value']);?>%</td>
<td><?php if(in_array('I',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Loss of Intellectual Property</td>
<td><?php print($fortune1000->field_loss_of_intellectual_prope['und'][0]['value']);?>%</td>
<td><?php print($industry->field_loss_of_intellectual_prope['und'][0]['value']);?>%</td>
<td><?php if(in_array('J',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Product or Service Failure</td>
<td><?php print($fortune1000->field_product_or_service_failure['und'][0]['value']);?>%</td>
<td><?php print($industry->field_product_or_service_failure['und'][0]['value']);?>%</td>
<td><?php if(in_array('K',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Social Media Risk</td>
<td><?php print($fortune1000->field_social_media_risk['und'][0]['value']);?>%</td>
<td><?php print($industry->field_social_media_risk['und'][0]['value']);?>%</td>
<td><?php if(in_array('L',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Actual Cyber Events</td>
<td><?php print($fortune1000->field_actual_cyber_events['und'][0]['value']);?>%</td>
<td><?php print($industry->field_actual_cyber_events['und'][0]['value']);?>%</td>
<td><?php if(in_array('M',$my_responses[3]['value']) ){ print("✔");}?> </td>
</tr></tbody></table>  

  
        <h2 class="pane-title">Extent of Cyber Risk</h2>
    
  
    <table class="tftable" border="1"><tbody><tr><th>Extent of Cyber Risk</th>
<th>Fortune 1000</th>
<th><?php print($industry->title);?></th>
<th>Your Extent of Risk</th>
</tr><tr><td>Silent on Cyber Risk</td>
<td><?php print($fortune1000->field_a_silent_on_cyber_risk['und'][0]['value']);?>%</td>
<td><?php print($industry->field_a_silent_on_cyber_risk['und'][0]['value']);?>%</td>
<td><?php if(in_array('A',$my_responses[2]['value']) ){ print("✔");}?> </td>
</tr><tr><td> Cyber Risk would "Impact" or " Adversely Impact" the business</td>
<td><?php print($fortune1000->field_b_cyber_risk_would_impact_['und'][0]['value']);?>%</td>
<td><?php print($industry->field_b_cyber_risk_would_impact_['und'][0]['value']);?>%</td>
<td><?php if(in_array('B',$my_responses[2]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber Risk "Significant</td>
<td><?php print($fortune1000->field_c_cyber_risk_significant_['und'][0]['value']);?>%</td>
<td><?php print($industry->field_c_cyber_risk_significant_['und'][0]['value']);?>%</td>
<td><?php if(in_array('C',$my_responses[2]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber Risk "Material Harm" or "Seriously Harm"</td>
<td><?php print($fortune1000->field_d_cyber_risk_material_harm['und'][0]['value']);?>%</td>
<td><?php print($industry->field_d_cyber_risk_material_harm['und'][0]['value']);?>%</td>
<td><?php if(in_array('D',$my_responses[2]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber risk "Critical"</td>
<td><?php print($fortune1000->field_e_cyber_risk_critical_['und'][0]['value']);?>%</td>
<td><?php print($industry->field_e_cyber_risk_critical_['und'][0]['value']);?>%</td>
<td><?php if(in_array('E',$my_responses[2]['value']) ){ print("✔");}?> </td>
</tr></tbody></table>  

  
        <h2 class="pane-title">Insurance Coverage</h2>
    
  
    <table class="tftable" border="1"><tbody><tr><th>Insurance Coverage</th>
<th>Fortune 1000</th>
<th><?php print($industry->title);?></th>
<th>Your Coverage</th>
</tr><tr><td>Silent</td>
<td><?php print($fortune1000->field_insurance_coverage_silent['und'][0]['value']);?>%</td>
<td><?php print($industry->field_insurance_coverage_silent['und'][0]['value']);?>%</td>
<td><?php if(in_array('A',$my_responses[4]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Yes</td>
<td><?php print($fortune1000->field_insurance_coverage_yes['und'][0]['value']);?>%</td>
<td><?php print($industry->field_insurance_coverage_yes['und'][0]['value']);?>%</td>
<td><?php if(in_array('B',$my_responses[4]['value']) ){ print("✔");}?> </td>
</tr></tbody></table>  

  
        <h2 class="pane-title">Risk Protections</h2>
    
  
    <table class="tftable" border="1"><tbody><tr><th>Risk Protections</th>
<th>Fortune 1000</th>
<th><?php print($industry->title);?></th>
<th>Your Risk Protections</th>
</tr><tr><td>Reference to technical safeguards</td>
<td><?php print($fortune1000->field__reference_to_technical_sa['und'][0]['value']);?>%</td>
<td><?php print($industry->field__reference_to_technical_sa['und'][0]['value']);?>%</td>
<td><?php if(in_array('A',$my_responses[5]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Reference to inability to have the resources to limit loss</td>
<td><?php print($fortune1000->field__reference_to_inability_to['und'][0]['value']);?>%</td>
<td><?php print($industry->field__reference_to_inability_to['und'][0]['value']);?>%</td>
<td><?php if(in_array('B',$my_responses[5]['value']) ){ print("✔");}?> </td>
</tr><tr><td>Cyber risks are covered by insurance</td>
<td><?php print($fortune1000->field__cyber_risks_are_covered_b['und'][0]['value']);?>%</td>
<td><?php print($industry->field__cyber_risks_are_covered_b['und'][0]['value']);?>%</td>
<td><?php if(in_array('C',$my_responses[5]['value']) ){ print("✔");}?> </td>
</tr><tr><td>No comments on risk protection</td>
<td><?php print($fortune1000->field__no_comments_on_risk_prote['und'][0]['value']);?>%</td>
<td><?php print($industry->field__no_comments_on_risk_prote['und'][0]['value']);?>%</td>
<td><?php if(in_array('D',$my_responses[5]['value']) ){ print("✔");}?> </td>
</tr></tbody></table>  
<?php 
?>
