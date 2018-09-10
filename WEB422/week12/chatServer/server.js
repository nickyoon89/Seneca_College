const express = require("express");
const app = express();
const path = require("path");

const HTTP_PORT = process.env.PORT || 8080;

// setup the static folder 
app.use(express.static("public"));

// setup socket.io
var http = require('http').Server(app);
var io = require('socket.io')(http);

io.on('connection', function (socket) {
    console.log('a user connected'); // show when the user connected

    // assign them a temporary user name:
    let tempUserName = "User-" + Math.floor(Math.random() * (100000 - 1 + 1)) + 1; 

    socket.on('disconnect', function () {
        console.log('user disconnected'); // show when the user disconnected
    });

    socket.on('chat message', function (msg) { // when the socket recieves a "chat message"
        console.log("user sent: " + msg);
        io.emit('chat message', tempUserName + ": " + msg); // send the message back to the users
    });
});

http.listen(HTTP_PORT, () => { // note - we use http here, not app
    console.log("listening on: " + HTTP_PORT);
});