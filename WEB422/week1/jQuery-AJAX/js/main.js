$(function() { // this is the same as: $(document).ready(function(){

    // store a reference to $("#employees-table body")
    let tbody = $("#employees-table tbody");

    $.ajax({
        url: "your teams api url/employees", // change "your teams api url" to your Teams API url on Heroku
        type: "GET",
        //data: JSON.stringify({ some: "data" }), // we can also send data using the "data" option
        contentType: "application/json"
    })
    .done(function (employees) {

        for(let i = 0; i < 5; i++){ // only show the first 5 employees

            // Create each table cell for the current employee row and add the text
            let fNameTD = $('<td>').text(employees[i].FirstName);
            let lNameTD = $('<td>').text(employees[i].LastName);
            let positionTD = $('<td>').text(employees[i].Position.PositionName);

            // append all table cells to a new row
            let row = $('<tr>').append(fNameTD).append(lNameTD).append(positionTD); // create the row and append all of the TD elements.

            // append the row to the table body
            tbody.append(row);
        }
        
    })
    .fail(function (err) {
        console.log("error: " + err.statusText);
    });

});