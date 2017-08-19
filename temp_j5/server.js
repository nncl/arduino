"use strict";

// Declarations
let express = require("express")
    , app = express()
    , jFive = require("johnny-five")
    , board = new jFive.Board({port: "COM3"})
    , led
    , temperature;

board.on("ready", () => {
  console.log("Arduino connected");
  led = new jFive.Led(10);

  temperature = new jFive.Thermometer({
    controller: "LM35",
    pin: "A0"
  });

  temperature.on("change", function() {
    console.log(this.celsius + "°C", this.fahrenheit + "°F");
    console.log(__dirname);
    temperature = this.celsius;
  });
});

// Routes
app.get("/", (req, res) => {
  res.send("FIAP IOT");
});

app.get("/toggle", (req, res) => {
  led.toggle();
  res.send("LED TOGGLED");
});

app.get("/temperature", (req, res) => {
  res.send(temperature.toString());
});

// Server
let server = app.listen(3000);
console.log("Running on 3000");
