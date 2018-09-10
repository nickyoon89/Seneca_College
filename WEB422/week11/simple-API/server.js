const express = require("express");
const cors = require("cors");
const dataService = require("./data-service.js");
const userService = require("./user-service.js");
const app = express();

app.use(cors());

const HTTP_PORT = process.env.PORT || 8080;

app.get("/api/vehicles", (req,res)=>{
    dataService.getAllVehicles().then((data)=>{
        res.json(data);
    }).catch(()=>{
        res.status(500).end();
    });
});

app.use((req, res) => {
    res.status(404).end();
});

app.listen(HTTP_PORT, ()=>{
    console.log("App listening on: " + HTTP_PORT);
});