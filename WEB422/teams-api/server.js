const mongoDBConnectionString = "Enter Your MongoDB Connection String Here";
const HTTP_PORT = process.env.PORT || 8081;

const express = require("express");
const bodyParser = require('body-parser');

const cors = require("cors");
const dataService = require("./data-service.js");

const data = dataService(mongoDBConnectionString);
const app = express();

app.use(bodyParser.json());
app.use(cors());

// "Employee" Routes

app.get("/employees", (req,res) => {
    data.getAllEmployees().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/employees-raw", (req,res) => {
    data.getAllEmployeesRaw().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/employee/:employeeId", (req,res) => {
    data.getEmployeeById(req.params.employeeId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/employee-raw/:employeeId", (req,res) => {
    data.getEmployeeByIdRaw(req.params.employeeId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.put("/employee/:employeeId", (req, res) => {

    data.updateEmployeeById(req.params.employeeId, req.body).then((data)=>{
        res.json({"message": "Employee " + data + " updated successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.post("/employees", (req, res) => {
    
    data.addEmployee(req.body).then((data)=>{
        res.json({"message": "Employee " + data + " added successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

////////////////////

// "Position" Routes

app.get("/positions", (req,res) => {
    data.getAllPositions().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/position/:positionId", (req,res) => {
    data.getPositionById(req.params.positionId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.put("/position/:positionId", (req,res) => {
    data.updatePositionById(req.params.positionId, req.body).then((data)=>{
        res.json({"message": "Position " + data + " updated successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.post("/positions", (req, res) => {
    
    data.addPosition(req.body).then((data)=>{
        res.json({"message": "Position " + data + " added successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

////////////////////

// "Project" Routes

app.get("/projects", (req,res) => {
    data.getAllProjects().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/project/:projectId", (req,res) => {
    data.getProjectById(req.params.projectId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.put("/project/:projectId", (req,res) => {
    data.updateProjectById(req.params.projectId, req.body).then((data)=>{
        res.json({"message": "Project " + data + " updated successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.post("/projects", (req, res) => {
    
    data.addProject(req.body).then((data)=>{
        res.json({"message": "Project " + data + " added successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

////////////////////

// "Team Routes"

app.get("/teams", (req,res) => {
    data.getAllTeams().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/teams-raw", (req,res) => {
    data.getAllTeamsRaw().then((data)=>{
        res.json(data);
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/team/:teamId", (req,res) => {
    data.getTeamById(req.params.teamId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.get("/team-raw/:teamId", (req,res) => {
    data.getTeamByIdRaw(req.params.teamId).then((data)=>{
        if(data.length > 0){
            res.json(data);
        }else{
            res.status(404).end();
        }
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.put("/team/:teamId", (req,res) => {
    data.updateTeamById(req.params.teamId, req.body).then((data)=>{
        res.json({"message": "Team " + data + " updated successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

app.post("/teams", (req, res) => {
    
    data.addTeam(req.body).then((data)=>{
        res.json({"message": "Team " + data + " added successfully"});
    })
    .catch((err)=>{
        res.status(500).end();
    })
});

////////////////////

// Catch-All 404 error

app.use((req, res) => {
    res.status(404).end();
});

// Connect to the DB and start the server

data.connect().then(()=>{
    app.listen(HTTP_PORT, ()=>{console.log("API listening on: " + HTTP_PORT)});
})
.catch((err)=>{
    console.log("unable to start the server: " + err);
    process.exit();
});
