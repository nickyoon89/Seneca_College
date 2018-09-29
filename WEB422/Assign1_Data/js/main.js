/*********************************************************************************
*  WEB422 – Assignment 1
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: Jihyun Yoon Student ID: 124558172 Date: Sep 14th, 2018
*
*
********************************************************************************/ 


$(document).ready(function(){
    console.log("jQuery Working");
    $( "#teams-menu" ).on( "click", function(event) {
        event.preventDefault();
        $.get("https://web422-server.herokuapp.com/teams")
            .done(function(data){
                $(".well").empty()
                    .append("<h3>Teams<h3>")
                    .append(JSON.stringify(data));
            });   
    });
    $( "#employees-menu" ).on( "click", function(event) {
        event.preventDefault();
        $.get("https://web422-server.herokuapp.com/employees")
            .done(function(data){
                $(".well").empty()
                    .append("<h3>Employees<h3>")
                    .append(JSON.stringify(data));
            });   
    });
    $( "#projects-menu" ).on( "click", function(event) {
        event.preventDefault();
        $.get("https://web422-server.herokuapp.com/projects")
            .done(function(data){
                $(".well").empty()
                    .append("<h3>Projects<h3>")
                    .append(JSON.stringify(data));
            });   
    });
    $( "#positions-menu" ).on( "click", function(event) {
        event.preventDefault();
        $.get("https://web422-server.herokuapp.com/positions")
            .done(function(data){
                $(".well").empty()
                    .append("<h3>Positions<h3>")
                    .append(JSON.stringify(data));
            });   
    });
});

