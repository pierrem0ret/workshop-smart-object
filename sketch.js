/*
adapted from https://github.com/tigoe/mqtt-examples/blob/master/p5js-mqtt-client/public/sketch.js
//https://public.cloud.shiftr.io/

https://github.com/tigoe/mqtt-examples
*/


// MQTT client details:
let broker = {
  hostname: 'public.cloud.shiftr.io',
  port: 443
};
// MQTT client:
let client;
// client credentials:
let creds = {
  clientID: 'p5Client',
  userName: 'public',
  password: 'public'
}

//Interface
let input, button, greeting;

//Messages
let messages = [];


let sliderR;
let psliderR = 0

let connected = false;



function setup() {
  // put setup code here
  //createCanvas(300, 300);

  client = new Paho.MQTT.Client(broker.hostname, Number(broker.port), creds.clientID);
  // set callback handlers for the client:
  client.onConnectionLost = onConnectionLost;
  client.onMessageArrived = onMessageArrived;
  // connect to the MQTT broker:
  client.connect({
    onSuccess: onConnect, // callback function for when you connect
    userName: creds.userName, // username
    password: creds.password, // password
    useSSL: true // use SSL
  });

  input = document.getElementById("chant");

  //sliderR = createSlider(0, 255, 100);
  //sliderR.position(10, 10);
  //sliderR.style('width', '80px');

  /*
  input = createInput();
  input.position(width/2 -  input.width/2, height/2);

  button = createButton('Envoyer !!');
  button.position(input.x + input.width, height/2);
  button.mousePressed(stockInput);

  buttonAdmin = createButton('Imprimer');
  buttonAdmin.position(input.x + input.width, height/2 + 30);
  buttonAdmin.mousePressed(sendMessages);
  */

}


// called when the client connects
function onConnect() {
  console.log("connected")
  client.subscribe("/lamp1/r");
  client.subscribe("/printer/test");
  connected = true
}

// called when the client loses its connection
function onConnectionLost(response) {
  if (response.errorCode !== 0) {
    console.log(response.errorMessage)
  }
}

// called when a message arrives
function onMessageArrived(message) {
  console.log("incoming message : " + message.payloadString)
  /*
  let incomingNumber = parseInt(message.payloadString);
  if (incomingNumber > 0) {
    intensity = 255;
  }*/
}

function printTest() {
    if (connected) {
      let message = new Paho.MQTT.Message("printTest"); // start an MQTT message:
      message.destinationName = "/printer/test";
      client.send(message);
      console.log("sending test to printer")
    }
  
}

function printInput() { 
  if (connected) {
    let message = new Paho.MQTT.Message(input.value()); // start an MQTT message:
    message.destinationName = "/printer/test";
    client.send(message);
    console.log("sending test to printer")
  }

}

function printMessages() { 
  if (connected) {
    let message = new Paho.MQTT.Message(input.value); // start an MQTT message:
    message.destinationName = "/printer/test";
    client.send(message);
    console.log("sending test to printer")
  }

}


function stockInput() { 
  console.log(input.value);
  console.log("test");
  if (connected) {
    let newLength = messages.push(input.value);
    input.value = "";
  }


}

function sendMessages() {
  console.log("envoi")
    messages.forEach(function(item, index, array) {
    let message = new Paho.MQTT.Message(item, index); // start an MQTT message:
    message.destinationName = "/printer/test";
    client.send(message);
    console.log(index, item)
  });
}

