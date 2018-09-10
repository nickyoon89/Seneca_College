// define the "row" template
let rowTemplate = _.template('<% _.forEach(employees, function(employee) { %>' +
                                '<tr>' + 
                                    '<td><%- employee.FirstName %></td>' + 
                                    '<td><%- employee.LastName %></td>' + 
                                    '<td><%- employee.Position.PositionName %></td>' + 
                                '</tr>' +
                            '<% }); %>');

let allEmployees; // define "allEmployees" as global to this file
let tbody; // define "tbody" as global to this file


// utility function to add rows to tbody
function addRows(pgNum){
    let rows = rowTemplate({ 'employees': _.chunk(allEmployees,5)[pgNum]});
    tbody.empty();
    tbody.append(rows);
}

$(function() { // this is the same as: $(document).ready(function(){

    // store a reference to $("#employees-table body")
    tbody = $("#employees-table tbody");

    $.ajax({
        url: "your teams api url/employees", // change "your teams api url" to your Teams API url on Heroku
        type: "GET",
        //data: JSON.stringify({ some: "data" }), // we can also send data using the "data" option
        contentType: "application/json"
    })
    .done(function (employees) {
        // only grab the first 15 employees
        allEmployees = _.take(employees,15);
        addRows(0); // show rows from page 0
    })
    .fail(function (err) {
        console.log("error: " + err.statusText);
    });

    // wire up the 3 preset "paging" buttons
    
    $("#pg1").on("click", function () {
        addRows(0); // show rows from page 0
    });

    $("#pg2").on("click", function () {
        addRows(1);  // show rows from page 1
    });

    $("#pg3").on("click", function () {
        addRows(2); // show rows from page 0
    });

    // wire up the filter headings

    $("#first-name-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.FirstName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

    $("#last-name-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.LastName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

    $("#position-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.Position.PositionName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

});