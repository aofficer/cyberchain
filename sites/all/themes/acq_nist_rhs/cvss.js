(function ($) {
  $(document).ready(function() {
  
    $('#edit-field-impact-subscore-und-0-value').attr('readonly', true);
    $('#edit-field-exploitability-subscore-und-0-value').attr('readonly', true);
    $('#edit-field-cvss-base-score-und-0-value').attr('readonly', true);
/*  
    $("#supply-chain-transaction-node-form input:text").keypress(function(e) {
        if(window.event) {
            if(!(e.keyCode > 47 && e.keyCode < 58 || e.keyCode == 8 || e.keyCode == 0)) {
                return false;
            }
        } else if(e.which) {
            if(!(e.which > 47 && e.which < 58 || e.which == 8 || e.which == 0)) {
                return false;
            }
        }
    });
    $("#supply-chain-transaction-node-form input:text").keyup(function(e) {
        if(window.event) {
            if(e.keyCode > 47 && e.keyCode < 58 || e.keyCode == 8 || e.keyCode == 0) {
                $calculate();
            } else {
                return false;
            }
        } else if(e.which) {
            if(e.which > 47 && e.which < 58 || e.which == 8 || e.which == 0) {
                $calculate();
            } else {
                return false;
            }
        }
    });
*/
    $("#supply-chain-transaction-node-form select").change(function(e) {
      $calculate();
    });
    var $setUndefined = function() {
      $('#edit-field-impact-subscore-und-0-value').val('Undefined');
      $('#edit-field-exploitability-subscore-und-0-value').val('Undefined');
      $('#edit-field-cvss-base-score-und-0-value').val('Undefined');
    }
    var $calculate = function() {
      if ($('#edit-field-impact-subscore-und-0-value').val() == '') {
        $('#edit-field-impact-subscore-und-0-value').val(0);
      }
      if ($('#edit-field-exploitability-subscore-und-0-value').val() == '') {
        $('#edit-field-exploitability-subscore-und-0-value').val(0);
      }
    
      var $accessVector = parseFloat($('#edit-field-access-vector-und').val());
      if ($accessVector < 0) { $setUndefined(); return; }
      
      var $accessComplexity = parseFloat($('#edit-field-access-complexity-und').val());
      if ($accessComplexity < 0) { $setUndefined(); return; }
      
      var $authentication = parseFloat($('#edit-field-authentication-und').val());
      if ($authentication < 0) { $setUndefined(); return; }

      var $exploitability = 20.0*$accessComplexity*$authentication*$accessVector;      
      $('#edit-field-exploitability-subscore-und-0-value').val($exploitability.toFixed(1));
      
      
      
      
      var $confImpact = parseFloat($('#edit-field-conf-impact-und').val());
      if ($confImpact < 0) { $setUndefined(); return; }
      
      var $integImpact = parseFloat($('#edit-field-integ-impact-und').val());
      if ($integImpact < 0) { $setUndefined(); return; }
      
      var $availImpact = parseFloat($('#edit-field-avail-impact-und').val());
      if ($availImpact < 0) { $setUndefined(); return; }

      var $impact = 10.41*(1.0-(1.0-$confImpact)*(1.0-$integImpact)*(1.0-$availImpact))
      $('#edit-field-impact-subscore-und-0-value').val($impact.toFixed(1));
      
      
      
      var $impactSubscore = parseFloat($('#edit-field-impact-subscore-und-0-value').val());
      var $exploitabilitySubscore = parseFloat($('#edit-field-exploitability-subscore-und-0-value').val());
      
      var $fimpact = 0.0; if ($impact != 0.0) $fimpact = 1.1761;
      var $baseScore = (0.6*$impact + 0.4*$exploitability-1.5) * $fimpact;
      $('#edit-field-cvss-base-score-und-0-value').val($baseScore.toFixed(1));
      
      
      var $baseScore = parseFloat($('#edit-field-cvss-base-score-und-0-value').val());
      
      if ($('#edit-field-impact-subscore-und-0-value').val() == 'NaN' || $impactSubscore < 0) {
        $('#edit-field-impact-subscore-und-0-value').val('Undefined')
      }
      if ($('#edit-field-exploitability-subscore-und-0-value').val() == 'NaN' || $exploitabilitySubscore < 0) {
        $('#edit-field-exploitability-subscore-und-0-value').val('Undefined')
      }
      if ($('#edit-field-cvss-base-score-und-0-value').val() == 'NaN' || $baseScore < 0) {
        $('#edit-field-cvss-base-score-und-0-value').val('Undefined')
      }      
      
      
    };
  });
    
}(jQuery));


