/**
 * @file
 * Adds a function to generate a round chart to the `Drupal` object.
 */
/**
 * Notes on data formatting:
 * legend: array of text values. Length is number of data types.
 * rows: array of arrays. One array for each point of data
 * arrays have format array(label, data1, data2, data3, ...)
 */
(function($) {
  Drupal.d3.round = function(select, settings) {
    var total = settings.total,
      possible = settings.possible,
      
      // Padding is top, right, bottom, left as in css padding.
      p = [10, 50, 15, 15],
      w = 100,
      h = 100,
      
      // Chart diameter is w or h, (whichever is smaller) - padding.
      radius = Math.min((w - p[1] - p[3]), (h - p[0] - p[2])) / 2,
      
      div = (settings.id) ? settings.id : 'visualization';
      
    var percentage = total / possible;
    
      
    var svg = d3.select('#' + div).append("svg")
      .attr("width", w)
      .attr("height", h)
      .append("g")
         
    var graph = svg.append("g")
      .attr("class", "chart");
      
    var bg_arc = d3.svg.arc()
        .startAngle(20 * (Math.PI/180))
        .endAngle(340 * (Math.PI/180))
        .outerRadius(w/2)
        .innerRadius(w/2 * .75);     
      
    var arc = d3.svg.arc()
        .startAngle(20 * (Math.PI/180))
        .endAngle(340 * (Math.PI/180) * percentage)
        .outerRadius(w/2)
        .innerRadius(w/2 * .75);
        
        
/*        
    graph.append("rect")
      .attr("class","background")
      .attr("width", w)
      .attr("height", h);
*/
     
    graph.append("path")
      .attr("fill", "red")
      .attr("transform", 
        "translate(" + w/2 + "," + h/2 + ")" +
        "rotate(180)")
      .attr("d", bg_arc);
      

    graph.append("path")
      .attr("fill", "purple")
      .attr("transform", 
        "translate(" + w/2 + "," + h/2 + ")" +
        "rotate(180)")
      .attr("d", arc);

/*    
    var circle = graph.append("circle")
      .attr("cx", 30)
      .attr("cy", 30)
      .attr("r", 20);    
*/

console.log("see ya later!");
  }
  
})(jQuery);