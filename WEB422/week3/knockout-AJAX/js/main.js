// Note - this code uses ES6 Promises (not currently supported in IE11 - https://kangax.github.io/compat-table/es6/ )
// If this is a concern, the following "polyfill" can be used: https://github.com/taylorhakes/promise-polyfill

let employeesModel = {}; // all of the "viewmodel" data (Employees)

// Function to pull the latest data from the API

function fetchLatestEmployeeData(){
    
    return new Promise(function(resolve,reject){
        $.ajax({
            url: "your teams api url/employees", // change "your teams api url" to your Teams API url on Heroku
            type: "GET",
            contentType: "application/json"
        })
        .done(function (data) {
            resolve(data);
        })
        .fail(function (err) {
            reject("Unable to show Employee List");
        });
    });
}

// Function to programmatically show a modal window

function showModal(title,message){
    $("#modalTitle").html(title)
    $("#modalContent").html(message);
    $('#pageModal').modal();
}

$(document).ready(function(){

    fetchLatestEmployeeData()
    .then(function(data){

        employeesModel = ko.mapping.fromJS(data);
        ko.applyBindings(employeesModel);

        // Loop and manually Subscribe to every element's First & Last Name Properties

        employeesModel().forEach(function(element) {
            element.FirstName.subscribe(function(newValue){
                element.isDirty = true;
            });  
            
            element.LastName.subscribe(function(newValue){
                element.isDirty = true;
            }); 
        });
       
    })
    .catch(function(err){
         showModal("Error",err);
    });

    $("#saveChanges").on("click", function(){
        persistEmployeeChanges();
    });
    
});


function persistEmployeeChanges(){
    
    var modifiedEmployees = jQuery.grep(employeesModel(), function(obj) {
        return obj.isDirty == true;
    });

    var AJAXTasks = []; // an array of promises

    modifiedEmployees.forEach(function(employee){

        delete employee.isDirty; // no longer dirty

        let plainEmployee = ko.mapping.toJS(employee); // convert the observable employee back to a regular employee

        // push all of the promises onto an "AJAXTasks" array
    
        AJAXTasks.push(new Promise(function(resolve,reject){
            $.ajax({
                url: "your teams api url/employee/" + plainEmployee._id, //// change "your teams api url" to your Teams API url on Heroku
                type: "PUT",
                data: JSON.stringify(plainEmployee),
                contentType: "application/json"
            })
            .done(function (data) {
                resolve();
            })
            .fail(function (err) {
                employee.isDirty = true; // reinstate the "isDirty" flag, if we couldn't save the employee
                reject("Unable to update Employees");
            });
        }));
        
    });

    //Execute the promises

    Promise.all(AJAXTasks).then(function(data){
        showModal("Saved", "Data Saved Successfully");
    })
    .catch(function(err){
        showModal("Error", err);
    });
}
