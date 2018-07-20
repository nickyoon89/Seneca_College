/*********************************************************************************
*  WEB322 Assignment 2
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: _Jihyun Yoon_ Student ID: _124558172_ Date: _06/01/2018_
*
*  Online (Heroku) URL: https://nameless-atoll-63740.herokuapp.com/
*
********************************************************************************/

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();
var path = require('path');
var dataService = require('./data-service.js');

app.use(express.static('public'));
// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/home.html"));
});

app.get("/about", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/about.html"));
});

app.get('/employees', (req, res) => {
    dataService.getAllEmployees()
        .then((data) => res.json(data))
        .catch((err) => res.json({"message": err}))
});

app.get('/managers', (req, res) => {
    dataService.getManagers()
        .then((data) => res.json(data))
        .catch((err) => res.json({"message": err}))
});

app.get('*', (req, res) => {
    //res.send("Page Not Found");
    res.status(404);
    res.redirect("https://cdn-images-1.medium.com/max/1600/1*2AwCgo19S83FGE9An68w9A.gif");
})

app.get('/departments', (req, res) => {
    dataService.getDepartments()
        .then((data) => res.json(data))
        .catch((err) => res.json({"message": err}))
})

// setup http server to listen on HTTP_PORT
dataService.initialize()
.then((data) => {
    app.listen(HTTP_PORT, () => console.log(`Listening on port ${HTTP_PORT}`));
})
.catch(() => {
    console.log("There was an error initializing");
})