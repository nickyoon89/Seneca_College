/*********************************************************************************
*  WEB422 – Assignment 3
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: Jihyun Yoon Student ID: 124558172 Date: Oct 12th, 2018
*
*
********************************************************************************/ 

var viewModel = {
    teams: ko.observable([]),
    employees: ko.observable([]),
    projects: ko.observable([])
};

function initializeTeams(){
    return new Promise(function(resolve, reject){
        $.ajax({
            url: "https://web422-server.herokuapp.com/teams-raw",
            type: "GET",
            contentType: "application/json"
        })
        .done(function(data){
            viewModel.teams=ko.mapping.fromJS(data);
            resolve(data);
        })
        .fail(function(err){
            reject("Error loading the team data");
        });
    });
};

function initializeEmployees(){
    return new Promise(function(resolve, reject){
        $.ajax({
            url: "https://web422-server.herokuapp.com/employees",
            type: "GET",
            contentType: "application/json"
        })
        .done(function(data){
            viewModel.employees=ko.mapping.fromJS(data);
            resolve(data);
        })
        .fail(function(err){
            reject("Error loading the employee data");
        });
    });
};

function initializeProjects(){
    return new Promise(function(resolve, reject){
        $.ajax({
            url: "https://web422-server.herokuapp.com/projects",
            type: "GET",
            contentType: "application/json"
        })
        .done(function(data){
            viewModel.projects=ko.mapping.fromJS(data);
            resolve(data);
        })
        .fail(function(err){
            reject("Error loading the 'project' data");
        });
    });
};

function saveTeam(){
    var currentTeam = this;
    $.ajax({
        url: "https://web422-server.herokuapp.com/team/"+currentTeam._id(),
        type: "PUT",
        data: JSON.stringify(
            {
                Projects: currentTeam.Projects(),
                Employees: currentTeam.Employees(),
                TeamLead: currentTeam.TeamLead()
            }
        ),
        contentType: "application/json"
    })
    .done(function(data){
        showGenericModal("Success", currentTeam.TeamName() + " Updated Successfully");
    })
    .fail(function(err){
        showGenericModal("Error", "Error updating the team information.");
    });
}

function showGenericModal(title,message){
    $("#genericModal .modal-title").empty()
        .append(title);
    $("#genericModal .modal-body").empty()
        .append(message);
    $("#genericModal").modal('show');
};

$(document).ready(function() {
    
    console.log("jQuery Working");
    initializeTeams()
        .then(initializeEmployees)
        .then(initializeProjects)
        .then(()=>{
                ko.applyBindings(viewModel, $("body")[0]);
                $("select.multiple").multipleSelect({filter:true});
                $("select.single").multipleSelect({single:true, filter:true});
            }
        );
});