<?php 
  $groups = array('Emergent' => 0, 'Diligent' => 1, 'Proficient' => 2, 'Undefined' => 0); 
  $badges = array(0 => 0, 1 => 0, 2 => 0, 3 => 0);
?>

<table class="capability-maturity">
  <tr class="level" style="background-color: #DDD; "><?php //printr($tier_scores); ?>
    <td>Framework Levels</td>
    <td>Framework Implementation Tiers</td>
    <td/>
    <td/>
    <td/>
  </tr>
  <tr class="level-description">
    <td/>
    <td>Partial</td>
    <td>Risk Informed</td>
    <td>Repeatable</td>
    <td>Adaptive</td>
  </tr>
  <tr class="level">
    <td>Level I: Risk Management Process</td>
    <td>Risk managed in ad hoc/reactive manner</td>
    <td>Risk management practices conducted but not established as organizational-wide policy</td>
    <td>Risk management practices formally approved as organization-wide policy and regularly updated</td>
    <td>Continuous improvement of cyber security practices based on lessons learned and predictive indicators</td>
  </tr>
  <?php
    $idxL1_1 = 0;
    $IC1 = $tier_scores['IC1'];
    $IC2 = $tier_scores['IC2_1'] + $tier_scores['IC2_2'] + $tier_scores['IC2_3'];
    if ($IC1 > 0) {
      if ($IC2 > 4) {
        $idxL1_1 = 3;
      }
      else if ($IC2 > 2) {
        $idxL1_1 = 2;
      }
      else $idxL1_1 = 1;
    } 
    $badges[$idxL1_1] += 1;
  ?>
  <tr>
    <td class="category">Responsibility for Risk Management</td>
    <td<?php if ($idxL1_1 == 0):?> class="selected"<?php endif; ?>>No Single Person Managing Information Security or Information Security Officer with No Executive Support</td>
    <td<?php if ($idxL1_1 == 1):?> class="selected"<?php endif; ?>>Information Security Officer Has Executive Support in One Functional Area</td>
    <td<?php if ($idxL1_1 == 2):?> class="selected"<?php endif; ?>>Information Security Officer Has Executive Support in Two Functional Areas</td>
    <td<?php if ($idxL1_1 == 3):?> class="selected"<?php endif; ?>>Information Security Officer Has Executive Support Across All Functional Areas</td>
  </tr>
  <?php
    $idxL1_2 = 0;
    $tmpL1_2 = $tier_scores['IC3_1'] + $tier_scores['IC3_2'] + $tier_scores['IC3_3'] + $tier_scores['IC3_4'] + $tier_scores['IC3_5'] + $tier_scores['IC3_6'] + $tier_scores['IC3_7'];
    if (($tmpL1_2 >= 3) and ($tmpL1_2 <= 6)) {
      $idxL1_2 = 1;
    }
    else if (($tmpL1_2 >= 7) and ($tmpL1_2 <= 10)) {
      $idxL1_2 = 2;
    }
    else if ($tmpL1_2 >= 11) $idxL1_2 = 3;
    $badges[$idxL1_2] += 1;

  ?>
  <tr>
    <td class="category">Interaction between CIO/CSO and other key enterprise executives/supply chain partners</td>
    <td<?php if ($idxL1_2 == 0):?> class="selected"<?php endif; ?>>Minimal</td>
    <td<?php if ($idxL1_2 == 1):?> class="selected"<?php endif; ?>>Limited</td>
    <td<?php if ($idxL1_2 == 2):?> class="selected"<?php endif; ?>>Collaborative</td>
    <td<?php if ($idxL1_2 == 3):?> class="selected"<?php endif; ?>>Extensive</td>
  </tr>
  <?php
    $idxL1_3 = 0;
    $tmpL1_3 = $tier_scores['IB1'] + $tier_scores['IB2'] + $tier_scores['IC4'];
    $tmpL1_3 += $tier_scores['IE1'] + $tier_scores['IE2'] + $tier_scores['IE3'] + $tier_scores['IE4'];
    $tmpL1_3 += $tier_scores['IE4_1'] + $tier_scores['IE4_2'] + $tier_scores['IE4_3'];
    if (($tmpL1_3 >= 7) and ($tmpL1_3 <= 12)) {
      $idxL1_3 = 1;
    }
    else if (($tmpL1_3 >= 13) and ($tmpL1_3 <= 16)) {
      $idxL1_3 = 2;
    }
    else if ($tmpL1_3 >= 17) $idxL1_3 = 3;
    $badges[$idxL1_3] += 1;

  ?>
  <tr>
    <td class="category">Enterprise Risk Management (ERM) program elements</td>
    <td<?php if ($idxL1_3 == 0):?> class="selected"<?php endif; ?>>Weakly defined</td>
    <td<?php if ($idxL1_3 == 1):?> class="selected"<?php endif; ?>>Defined and partially implemented</td>
    <td<?php if ($idxL1_3 == 2):?> class="selected"<?php endif; ?>>Further implemented, much more formalized</td>
    <td<?php if ($idxL1_3 == 3):?> class="selected"<?php endif; ?>>Fully defined and implemented</td>
  </tr>  
  <?php
    $idxL1_4 = 0;
    $tmpL1_4 = $tier_scores['ID1'] + $tier_scores['ID2'] + $tier_scores['ID3'] + $tier_scores['ID4'] + $tier_scores['ID6'];
    $tmpL1_4 += $tier_scores['IIIA2'] + $tier_scores['IIIA2_1'] + $tier_scores['IIIA2_2'] + $tier_scores['IIIA3'] + $tier_scores['IIIA4'];
    if (($tmpL1_4 >= 8) and ($tmpL1_4 <= 10)) {
      $idxL1_4 = 1;
    }
    else if (($tmpL1_4 >= 11) and ($tmpL1_4 <= 16)) {
      $idxL1_4 = 2;
    }
    else if ($tmpL1_4 >= 17) $idxL1_4 = 3;
    $badges[$idxL1_4] += 1;
  ?>
  <tr>
    <td class="category">Systematic Risk Assessment activities</td>
    <td<?php if ($idxL1_4 == 0):?> class="selected"<?php endif; ?>>Minimal</td>
    <td<?php if ($idxL1_4 == 1):?> class="selected"<?php endif; ?>>Selected risk assessment activities across the enterprise</td>
    <td<?php if ($idxL1_4 == 2):?> class="selected"<?php endif; ?>>Formalized approach to internal, enterprise-wide risk assessment</td>
    <td<?php if ($idxL1_4 == 3):?> class="selected"<?php endif; ?>>Extensive supply chain-wide risk assessment activities involving suppliers and customers</td>
  </tr>  
  <?php
    $idxL1_5 = 0;
    $tmpL1_5 = $tier_scores['IIB4'] + $tier_scores['IIIB1'] + $tier_scores['IIIC1'];
    $tmpL1_5 += $tier_scores['IVD1_1'] + $tier_scores['IVD1_2'] + $tier_scores['IVD1_3'] + $tier_scores['IVD1_4'];
    $tmpL1_5 += $tier_scores['VC2'] + $tier_scores['VC3'];
    if (($tmpL1_5 >= 8) and ($tmpL1_5 <= 10)) {
      $idxL1_5 = 1;
    }
    else if (($tmpL1_5 >= 11) and ($tmpL1_5 <= 14)) {
      $idxL1_5 = 2;
    }
    else if ($tmpL1_5 >= 15) $idxL1_5 = 3;
    $badges[$idxL1_5] += 1;
  ?>
  <tr>
    <td class="category">Risk Monitoring/digital forensics and reporting capacity</td>
    <td<?php if ($idxL1_5 == 0):?> class="selected"<?php endif; ?>>Minimal risk monitoring/digital forensics and reporting capacity in place</td>
    <td<?php if ($idxL1_5 == 1):?> class="selected"<?php endif; ?>>Limited capacity in place</td>
    <td<?php if ($idxL1_5 == 2):?> class="selected"<?php endif; ?>>In-house capacity reaches internal critical mass</td>
    <td<?php if ($idxL1_5 == 3):?> class="selected"<?php endif; ?>>Extensive capacity in place</td>
  </tr>    
  <?php
    $badge = 0;
    for ($i = 0; $i < 4; $i++) {
      if ($badges[$i] > $badge) {
        $badge = $i;
      }
    }
    $badge++;
  ?>  
  <tr>
    <td style="text-align: center;">Level 1 Achievement<br/><img height=100 width=100 src="<?php print base_path() . path_to_theme() . '/' . 'images/Badge-'. $badge .'.jpg'; ?>" /></td>
  </tr>   
  

  <tr class="level">
    <td>Level 2: Integrated Risk Management Program</td>
    <td>Implementation of cybersecurity risk management irregular and on case-by-case basis</td>
    <td>Risk awareness but no organization-wide approach to cybersecurity risk management</td>
    <td>Risk-informed policies, processes, and procedures are defined, implemented, and reviewed</td>
    <td>Cybersecurity risk management embedded in organizational culture with continuous awareness of system/network activities</td>
  </tr>
  <?php
    $badges = array(0 => 0, 1 => 0, 2 => 0, 3 => 0);
    $idxL2_1 = 0;
    $tmpL2_1 = $tier_scores['IID1'] + $tier_scores['IID2'] + $tier_scores['IIA9'];
    $tmpL2_1 += $tier_scores['IIA11'] + $tier_scores['IIA12'] + $tier_scores['IIIB8'];
    if (($tmpL2_1 >= 4) and ($tmpL2_1 <= 6)) {
      $idxL2_1 = 1;
    }
    else if (($tmpL2_1 >= 8) and ($tmpL2_1 <= 11)) {
      $idxL2_1 = 2;
    }
    else if ($tmpL2_1 >= 12) $idxL2_1 = 3;
    $badges[$idxL2_1]++;
  ?>
  <tr>
    <td class="category">Security control of personnel, facilities, and processes</td>
    <td<?php if ($idxL2_1 == 0):?> class="selected"<?php endif; ?>>Due diligence/background checks of new hires and facility access control</td>
    <td<?php if ($idxL2_1 == 1):?> class="selected"<?php endif; ?>>Periodic security reviews of current employees and periodic monitoring of physical and IT access logs</td>
    <td<?php if ($idxL2_1 == 2):?> class="selected"<?php endif; ?>>Frequent security reviews and monitoring of access logs</td>
    <td<?php if ($idxL2_1 == 3):?> class="selected"<?php endif; ?>>Constant due diligence of employees and contractors/ suppliers; and continuous monitoring of extended enterprise physical and IT access logs</td>
  </tr>     
  <?php
    $idxL2_2 = 0;
    $tmpL2_2 = $tier_scores['IE5'] + $tier_scores['IE6'] + $tier_scores['IE7'] + $tier_scores['IE8'];
    $tmpL2_2 += $tier_scores['IIA3'] + $tier_scores['IIIB7'];
    if (($tmpL2_2 >= 3) and ($tmpL2_2 <= 6)) {
      $idxL2_2 = 1;
    }
    else if (($tmpL2_2 >= 7) and ($tmpL2_2 <= 11)) {
      $idxL2_2 = 2;
    }
    else if ($tmpL2_2 >= 12) $idxL2_2 = 3;
    $badges[$idxL2_2]++;
  ?>
  <tr>
    <td class="category">System risk management embedded as overarching contractual obligation for contractors/ suppliers</td>
    <td<?php if ($idxL2_2 == 0):?> class="selected"<?php endif; ?>>Minimal contractual mandates for contractors/suppliers</td>
    <td<?php if ($idxL2_2 == 1):?> class="selected"<?php endif; ?>>Explicitly built into contracts but not aggressively monitored or enforced</td>
    <td<?php if ($idxL2_2 == 2):?> class="selected"<?php endif; ?>>Contractual risk-monitoring/enforcement capabilities established</td>
    <td<?php if ($idxL2_2 == 3):?> class="selected"<?php endif; ?>>Explicitly built into contracts; aggressively monitored and enforced</td>
  </tr>   

  <?php
    $idxL2_3 = 0;
    $tmpID5 = $tier_scores['ID5'];
    $tmpID7 = $tier_scores['ID7'];
    
    if ($tmpID5 == 2) {
      $idxL2_3 = 3;      
    }
    else if ($tmpID5 == 1) {
      if ($tmpID7 == 0) {
        $idxL2_3 = 1;
      }
      else {
        $idxL2_3 = 2;
      }
    }
    $badges[$idxL2_3]++;

  ?>
  <tr>
    <td class="category">Design of resilient systems via threat modeling and war gaming</td>
    <td<?php if ($idxL2_3 == 0):?> class="selected"<?php endif; ?>>Used sporadically to react to /address escalation in system threats</td>
    <td<?php if ($idxL2_3 == 1):?> class="selected"<?php endif; ?>>Used by internal enterprise personnel in pro-actively designing selective systems</td>
    <td<?php if ($idxL2_3 == 2):?> class="selected"<?php endif; ?>>Educating IT supply chain partners about the importance of collaborative threat modeling</td>
    <td<?php if ($idxL2_3 == 3):?> class="selected"<?php endif; ?>>Used as a critical design tool across all critical systems with  key supply chain partners</td>
  </tr>  

  <?php
    $idxL2_4 = 0;
    $tmpL2_4 = $tier_scores['IIIC2'] + $tier_scores['IVA1'] + $tier_scores['IVA2'] + $tier_scores['IVA3'];
    //$tmpL2_4 += $tier_scores['IIA3'] + $tier_scores['IIB7'];
    if ($tmpL2_4 >= 4) {
      $idxL2_4 = 1;
    }
    if ($tmpL2_4 >= 6) {
      $idxL2_4 = 2;
    }
    if ($tmpL2_4 >= 8) $idxL2_4 = 3;
    $badges[$idxL2_4]++;
  ?>
  <tr>
    <td class="category">Risk mitigation</td>
    <td<?php if ($idxL2_4 == 0):?> class="selected"<?php endif; ?>>Risks not identified, nor assigned to specific personnel for mitigation purposes</td>
    <td<?php if ($idxL2_4 == 1):?> class="selected"<?php endif; ?>>Some risks identified and assigned for mitigation purposes, with sporadic follow up</td>
    <td<?php if ($idxL2_4 == 2):?> class="selected"<?php endif; ?>>More formal risk management/mitigation process</td>
    <td<?php if ($idxL2_4 == 3):?> class="selected"<?php endif; ?>>Continuous identification, assignation, mitigation and monitoring of identified risks</td>
  </tr>   

  <?php
    $idxL2_5 = 0;
    $tmpL2_5 = $tier_scores['IA2'] + $tier_scores['IA2_1'] + $tier_scores['IA3'] + $tier_scores['IA4'];
    $tmpL2_5 += $tier_scores['IIA7_1'] + $tier_scores['IIA7_2'] + $tier_scores['IIA10'];
    $tmpL2_5 += $tier_scores['IIC4'] + $tier_scores['IIC5'] + $tier_scores['IIC6'];
    $tmpL2_5 += $tier_scores['IIC11'] + $tier_scores['IIC15'] + $tier_scores['IIC16'] + $tier_scores['IIC17'] + $tier_scores['IIC19'];
    $tmpL2_5 += $tier_scores['IIE5'] + $tier_scores['IIE6'];
    $tmpL2_5 += $tier_scores['IIE7'] + $tier_scores['IIE8'];
    $tmpL2_5 += $tier_scores['IIIB1'] + $tier_scores['IIIB2'];
    if (($tmpL2_5 >= 11) && ($tmpL2_5 <= 20)) {
      $idxL2_5 = 1;
    }
    else if (($tmpL2_5 >= 21) && ($tmpL2_5 <= 30)) {
      $idxL2_5 = 2;
    }
    else if ($tmpL2_5 >= 31) $idxL2_5 = 3;
    $badges[$idxL2_5]++;

  ?>
  <tr>
    <td class="category">Defense against IT supply chain breaches</td>
    <td<?php if ($idxL2_5 == 0):?> class="selected"<?php endif; ?>>Limited to IT perimeter defenses and intrusion detection</td>
    <td<?php if ($idxL2_5 == 1):?> class="selected"<?php endif; ?>>Broader IT system surveillance, including mechanisms such as proxy server code repositories for scanning/detecting viruses</td>
    <td<?php if ($idxL2_5 == 2):?> class="selected"<?php endif; ?>>Dashboard-enabled threat visualization</td>
    <td<?php if ($idxL2_5 == 3):?> class="selected"<?php endif; ?>>Real Time sensor grids for global situational awareness of IT and physical supply chains</td>
  </tr> 
  <?php
    $badge = 0;
    for ($i = 0; $i < 4; $i++) {
      if ($badges[$i] > $badge) {
        $badge = $i;
      }
    }
    $badge++;
  ?>  
  <tr>
    <td style="text-align: center;">Level 2 Achievement<br/><img height=100 width=100 src="<?php print base_path() . path_to_theme() . '/' . 'images/Badge-'. $badge .'.jpg'; ?>" /></td>
  </tr>   



  <tr class="level";>
    <td>Level 3: Operations/External Participation</td>
    <td>Limited or no processes in place for coordination/ collaboration with other entities</td>
    <td>Awareness of larger ecosystem but no formalized capabilities to interact and share information</td>
    <td>Organization understands dependencies and has risk management collaboration with partners</td>
    <td>Organization actively shares information with partners to anticipate and prevent Cybersecurity events</td>
  </tr>
  <?php
    $badges = array(0 => 0, 1 => 0, 2 => 0, 3 => 0);
    $idxL3_1 = 0;
    $tmpL3_1 = $tier_scores['IB5_2'] + $tier_scores['IB6_1'] + $tier_scores['IB6_2'] + $tier_scores['IB7_1'];
    $tmpL3_1 += $tier_scores['IB7_2'] + $tier_scores['IB7_3'] + $tier_scores['IID6'];
    //$tmpL3_1 += $tier_scores['IC19'] + $tier_scores['IIA7'] + $tier_scores['IIIA7_2'] + $tier_scores['IIA10'];
    //$tmpL3_1 += $tier_scores['IIC4'] + $tier_scores['IIC5'] + $tier_scores['IIC6'] + $tier_scores['IIC11'] + $tier_scores['IIC15'] + $tier_scores['IIC16'] + $tier_scores['IIC17'];
    //$tmpL3_1 += $tier_scores['IIE7'] + $tier_scores['IIE8'] + $tier_scores['IIIB1'] + $tier_scores['IIIB2'];
    if (($tmpL3_1 >= 3) && ($tmpL3_1 <= 6)) {
      $idxL3_1 = 1;
    }
    else if (($tmpL3_1 >= 7) && ($tmpL3_1 <= 10)) {
      $idxL3_1 = 2;
    }
    else if ($tmpL3_1 >= 11) $idxL3_1 = 3;
    $badges[$idxL3_1]++;
  ?>
  <tr>
    <td class="category">Adoption of Standards-Based IT System Development Process and Quality Assurance</td>
    <td<?php if ($idxL3_1 == 0):?> class="selected"<?php endif; ?>>Use of standards limited to compliance level testing for specific processes and products/services</td>
    <td<?php if ($idxL3_1 == 1):?> class="selected"<?php endif; ?>>Standards based quality assurance processes scaling to enterprise/system-wide level</td>
    <td<?php if ($idxL3_1 == 2):?> class="selected"<?php endif; ?>>Enterprise system-wide IT quality assurance standards</td>
    <td<?php if ($idxL3_1 == 3):?> class="selected"<?php endif; ?>>Enterprise/system-wide quality assurance and audit/validation processes put into place</td>
  </tr> 

  <?php
    $idxL3_2 = 0;
    $tmpL3_2 = $tier_scores['IA7'] + $tier_scores['IA10'] + $tier_scores['IA11'] + $tier_scores['IB3'];
    $tmpL3_2 += $tier_scores['IB3_1'] + $tier_scores['IID3_1'] + $tier_scores['IID3_2'];
    //$tmpL3_2 += $tier_scores['IC19'] + $tier_scores['IIA7'] + $tier_scores['IIIA7_2'] + $tier_scores['IIA10'];
    //$tmpL3_2 += $tier_scores['IIC4'] + $tier_scores['IIC5'] + $tier_scores['IIC6'] + $tier_scores['IIC11'] + $tier_scores['IIC15'] + $tier_scores['IIC16'] + $tier_scores['IIC17'];
    //$tmpL3_2 += $tier_scores['IIE7'] + $tier_scores['IIE8'] + $tier_scores['IIIB1'] + $tier_scores['IIIB2'];
    if (($tmpL3_2 >= 3) && ($tmpL3_2 <= 6)) {
      $idxL3_2 = 1;
    }
    else if (($tmpL3_2 >= 7) && ($tmpL3_2 <= 10)) {
      $idxL3_2 = 2;
    }
    else if ($tmpL3_2 >= 11) $idxL3_2 = 3;
    $badges[$idxL3_2]++;
  ?>
  <tr>
    <td class="category">Achieving Visibility Across IT Supply Chain</td>
    <td<?php if ($idxL3_2 == 0):?> class="selected"<?php endif; ?>>Sporadic tracking/ traceability of IT hardware and software products</td>
    <td<?php if ($idxL3_2 == 1):?> class="selected"<?php endif; ?>>Initial organizational efforts to maintain the accurate, complete, and auditable information on the history/pedigree of all IT hardware and software products</td>
    <td<?php if ($idxL3_2 == 2):?> class="selected"<?php endif; ?>>Sustained, expanded surveillance and tracking of critical IT hardware and software</td>
    <td<?php if ($idxL3_2 == 3):?> class="selected"<?php endif; ?>>Continuous visibility of software and hardware moving through the production/delivery cycle </td>
  </tr> 

  <?php
    $idxL3_3 = 0;
    $tmpL3_3 = $tier_scores['IB1'] + $tier_scores['IB2'] + $tier_scores['IB6_3'] + $tier_scores['IB6_4'];
    $tmpL3_3 += $tier_scores['IB6_5'] + $tier_scores['ID9_1'] + $tier_scores['ID9_2'] + $tier_scores['ID9_3'];
    $tmpL3_3 += $tier_scores['IE5'] + $tier_scores['IE9'] + $tier_scores['IIA5'] + $tier_scores['IIA6'];
    //$tmpL3_3 += $tier_scores['IIC4'] + $tier_scores['IIC5'] + $tier_scores['IIC6'] + $tier_scores['IIC11'] + $tier_scores['IIC15'] + $tier_scores['IIC16'] + $tier_scores['IIC17'];
    //$tmpL3_3 += $tier_scores['IIE7'] + $tier_scores['IIE8'] + $tier_scores['IIIB1'] + $tier_scores['IIIB2'];
    if (($tmpL3_3 >= 8) && ($tmpL3_3 <= 12)) {
      $idxL3_3 = 1;
    }
    else if (($tmpL3_3 >= 13) && ($tmpL3_3 <= 18)) {
      $idxL3_3 = 2;
    }
    else if ($tmpL3_3 >= 19) $idxL3_3 = 3;
    $badges[$idxL3_3]++;
  ?>
  <tr>
    <td class="category">Supplier qualification and operational checks</td>
    <td<?php if ($idxL3_3 == 0):?> class="selected"<?php endif; ?>>Limited due diligence over suppliers</td>
    <td<?php if ($idxL3_3 == 1):?> class="selected"<?php endif; ?>>Pre-screening of suppliers; limited screening of carriers</td>
    <td<?php if ($idxL3_3 == 2):?> class="selected"<?php endif; ?>>Diligence over suppliers increases significantly; frequent post contract reviews</td>
    <td<?php if ($idxL3_3 == 3):?> class="selected"<?php endif; ?>>Comprehensive sourcing strategy and use of only known suppliers and trusted carriers</td>
  </tr> 

  <?php
    $idxL3_4 = 0;
    $tmpL3_4 = $tier_scores['IB6_6'] + $tier_scores['IIB1'] + $tier_scores['IIE5'] + $tier_scores['IIE6'];
    $tmpL3_4 += $tier_scores['IIIB2'] + $tier_scores['IIIB4'] + $tier_scores['IVC1'] + $tier_scores['IVD4'];
    //$tmpL3_4 += $tier_scores['IE5'] + $tier_scores['IE9'] + $tier_scores['IIA5'] + $tier_scores['IIA6'];
    //$tmpL3_4 += $tier_scores['IIC4'] + $tier_scores['IIC5'] + $tier_scores['IIC6'] + $tier_scores['IIC11'] + $tier_scores['IIC15'] + $tier_scores['IIC16'] + $tier_scores['IIC17'];
    //$tmpL3_4 += $tier_scores['IIE7'] + $tier_scores['IIE8'] + $tier_scores['IIIB1'] + $tier_scores['IIIB2'];
    if (($tmpL3_4 >= 3) && ($tmpL3_4 <= 6)) {
      $idxL3_4 = 1;
    }
    else if (($tmpL3_4 >= 7) && ($tmpL3_4 <= 12)) {
      $idxL3_4 = 2;
    }
    else if ($tmpL3_4 >= 13) $idxL3_4 = 3;
    $badges[$idxL3_4]++;
  ?>
  <tr>
    <td class="category">Protocols to deal with counterfeit parts</td>
    <td<?php if ($idxL3_4 == 0):?> class="selected"<?php endif; ?>>Case by case response to suspect parts</td>
    <td<?php if ($idxL3_4 == 1):?> class="selected"<?php endif; ?>>Built in contract mechanisms to return suspect parts to suppliers</td>
    <td<?php if ($idxL3_4 == 2):?> class="selected"<?php endif; ?>>Identification of suppliers who account for high incidence of counterfeits</td>
    <td<?php if ($idxL3_4 == 3):?> class="selected"<?php endif; ?>>Pre-established relationships with Customs, the FBI, etc.; and standard operating procedures (SOPs) to remove/refer suspect parts from the supply chain</td>
  </tr> 
    <?php
    $badge = 0;
    for ($i = 0; $i < 4; $i++) {
      if ($badges[$i] > $badge) {
        $badge = $i;
      }
    }
    $badge++;
  ?>  
  <tr>
    <td style="text-align: center;">Level 3 Achievement<br/><img height=100 width=100 src="<?php print base_path() . path_to_theme() . '/' . 'images/Badge-'. $badge .'.jpg'; ?>" /></td>
  </tr>  
 
</table>

