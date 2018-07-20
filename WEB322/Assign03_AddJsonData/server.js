/*********************************************************************************
*  WEB322 Assignment 3
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: _Jihyun Yoon_ Student ID: _124558172_ Date: _06/14/2018_
*
*  Online (Heroku) URL: https://nameless-atoll-63740.herokuapp.com/
*
********************************************************************************/

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var multer = require("multer");
var bodyParser = require("body-parser");
var app = express();
var path = require('path');
var fs = require('fs');
var dataService = require('./data-service.js');

const storage = multer.diskStorage({
    destination: "./public/images/uploaded/",
    filename: function (req, file, cb) {
      cb(null, Date.now() + path.extname(file.originalname));
    }
});
var upload = multer({ storage: storage });

app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/home.html"));
});

app.get("/about", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/about.html"));
});

app.get("/employees/add", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/addEmployee.html"));
});

app.get("/images/add", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/addImage.html"));
});

app.get('/employee/:employeeNum', (req, res) => {
    dataService.getEmployeesByNum(req.params.employeeNum)
    .then((data) => {
        res.json(data);
    })
});

app.get('/employees', (req, res) => {
    if(req.query.status) {
        dataService.getEmployeesByStatus(req.query.status)
            .then((data) => res.json(data))
            .catch((err) => res.json({"message": err}))
    }else if(req.query.manager){
        dataService.getEmployeesByManager(req.query.manager)
            .then((data) => res.json(data))
            .catch((err) => res.json({"message": err}))
    }else if(req.query.department){
        dataService.getEmployeesByDepartment(req.query.department)
            .then((data) => res.json(data))
            .catch((err) => res.json({"message": err}))
    }else{
        dataService.getAllEmployees()
            .then((data) => res.json(data))
            .catch((err) => res.json({"message": err}))
    }
});

app.get('/managers', (req, res) => {
    dataService.getManagers()
        .then((data) => res.json(data))
        .catch((err) => res.json({"message": err}))
});

app.get('/departments', (req, res) => {
    dataService.getDepartments()
        .then((data) => res.json(data))
        .catch((err) => res.json({"message": err}))
})

app.get("/images", (req, res) => {
    fs.readdir("./public/images/uploaded", function(err, imageFile){
        res.json(imageFile);
    })
})

app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
});

app.post('/employees/add', function(req, res) {
    dataService.addEmployee(req.body)
        .then(res.redirect('/employees'))
        .catch((err) => res.json({"message": err}))   
}) 

app.get('*', (req, res) => {
    //res.send("Page Not Found");
    res.status(404);
    res.redirect("https://cdn-images-1.medium.com/max/1600/1*2AwCgo19S83FGE9An68w9A.gif");
})

// setup http server to listen on HTTP_PORT
dataService.initialize()
.then((data) => {
    app.listen(HTTP_PORT, () => console.log(`Listening on port ${HTTP_PORT}`));
})
.catch(() => {
    console.log("There was an error initializing");
})