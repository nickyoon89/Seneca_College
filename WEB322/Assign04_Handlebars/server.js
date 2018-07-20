/*********************************************************************************
*  WEB322 Assignment 4
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: _Jihyun Yoon_ Student ID: _124558172_ Date: _07/06/2018_
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
var exphbs = require('express-handlebars');
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
app.engine('.hbs',exphbs({
    extname:'.hbs', 
    defaultLayout:'main',
    helpers:{
        navLink:function(url, options){
            return '<li' + ((url==app.locals.activeRoute)? ' class="active"':'')
                +'><a href="'+url+'">'+options.fn(this)+'</a></li>'
        },
        equal:function(lvalue, rvalue, options){
            if(arguments.length<3)
                throw new Error("Handlerbars Helper equal needs 2 parameters");
            if(lvalue != rvalue){
                return options.inverse(this);
            }else{
                return options.fn(this);
            }
        }
    }
}));
app.set('view engine','.hbs');
app.use(function(req,res,next){
    let route=req.baseUrl + req.path;
    app.locals.activeRoute = (route=="/")? "/":route.replace(/\/$/,"");
    next();
});

// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/home.html"));
    res.render("home");
});

app.get("/about", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/about.html"));
    res.render("about");
});

app.get("/employees/add", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/addEmployee.html"));
    res.render("addEmployee");
});

app.get("/images/add", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/addImage.html"));
    res.render("addImage");
});

app.get('/employee/:employeeNum', (req, res) => {
    dataService.getEmployeesByNum(req.params.employeeNum)
    .then((data) => res.render("employee",{employee:data}))
    .catch(()=>{res.render("employee",{message:"no results"})
})
});

app.get('/employees', (req, res) => {
    if(req.query.status) {
        dataService.getEmployeesByStatus(req.query.status)
            .then((data) => res.render("employees",{employees:data}))
            .catch(() => res.render("employees",{message: "no results"}))
    }else if(req.query.manager){
        dataService.getEmployeesByManager(req.query.manager)
            .then((data) => res.render("employees",{employees:data}))
            .catch(() => res.render("employees",{message: "no results"}))
    }else if(req.query.department){
        dataService.getEmployeesByDepartment(req.query.department)
            .then((data) => res.render("employees",{employees:data}))
            .catch(() => res.render("employees",{message: "no results"}))
    }else{
        dataService.getAllEmployees()
            .then((data) => res.render("employees",{employees:data}))
            .catch(() => res.render("employees",{message: "no results"}))
    }
});

/*app.get('/managers', (req, res) => {
    dataService.getManagers()
        .then((data) => res.json(data))
        .catch((err) => res.render({"message": err}))
});*/

app.get('/departments', (req, res) => {
    dataService.getDepartments()
        .then((data) => res.render("departments",{departments:data}))
        .catch(() => res.render("departments",{"message": "no results"}))
})

app.get("/images", (req, res) => {
    fs.readdir("./public/images/uploaded", function(err, imageFile){
        //res.json(imageFile);
        res.render("images",  { data: imageFile, title: "Images" });
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

app.post("/employee/update", function(req, res){
    dataService.updateEmployee(req.body)
    .then(res.redirect('/employees'))
});

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