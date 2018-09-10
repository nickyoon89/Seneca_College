var express = require("express");
var app = express();

var HTTP_PORT = process.env.PORT || 8080;

// setup the static folder 
app.use(express.static("public")); 

// Start the server

app.listen(HTTP_PORT, function(){
    console.log("Server listening on port: " + HTTP_PORT);
});

