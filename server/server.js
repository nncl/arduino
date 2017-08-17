"use strict";

// Declarations
let express = require("express")
    , app = express()
    , jFive = require("johnny-five")
    , board = new jFive.Board({port: "COM3"})
    , relay
    , led;

board.on("ready", () => {
  console.log("Arduino connected");
  // relay = new jFive.Relay(10);
  led = new jFive.Led(10);
});

// Routes
app.get("/", (req, res) => {
  res.send("FIAP IOT");
});

app.get("/toggle", (req, res) => {
  led.toggle();
  res.send("TOGGLED");
});

// Server
let server = app.listen(3000);
console.log("Running on 3000");
