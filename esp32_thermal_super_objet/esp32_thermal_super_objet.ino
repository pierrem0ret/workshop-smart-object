
/*

   based on : https://www.shiftr.io/docs/manuals/arduino
   install arduino-mqtt (by Joël Gähwiler) : https://github.com/256dpi/arduino-mqtt
   install WiFiManager from https://github.com/tzapu/WiFiManager
   install neopixel lib from adafruit
*/

// this example works with this web page (made with cables): https://cables.gl/p/2uvYwz

// change the name to a unique one
char *espname = "esp8266_mqtt_cablesgl";

// wifi stuff
// uncomment the 3 lines below if you are working with an esp8266
//#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>

#include <WiFiManager.h>
#include <Ticker.h>


// led stuff
#include <Adafruit_NeoPixel.h>
// neopixel variables
#define PIN        14
#define NUMPIXELS 16
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Printer stuff
#include <SoftwareSerial.h> // or SoftwareSerial
#include "Adafruit_Thermal.h"
#include "date3.h"
#include "SoftwareSerial.h"

const int printerBaudrate = 19200;  // or 19200 usually
#define TX_PIN 13 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor


// MQTT stuff
#include <MQTT.h>
WiFiClient net;
MQTTClient client;

// wifi connection feedback
Ticker ticker;
int LED = LED_BUILTIN;
#define LED_BUILTIN 13 // ESP32 DOES NOT DEFINE LED_BUILTIN

void tick() {
  digitalWrite(LED, !digitalRead(LED));
}

float red = 0;
float green = 0;
float blue = 0;

//----------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);

  // init the lights at startup
  pixels.begin();
  pixels.setBrightness(20);
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show();

  //Printer
  mySerial.begin(printerBaudrate);  // must be 8N1 mode
  printer.begin();        // Init printer (same regardless of serial type)

  // wifi stuff
  pinMode(LED, OUTPUT);
  ticker.attach(0.6, tick);// start ticker with 0.5 because we start in AP mode and try to connect

  init_wifi();

  ticker.detach();
  digitalWrite(LED, LOW);
  client.begin("public.cloud.shiftr.io", net);
  Serial.println("connecting to broker");
  while (!client.connect("ESP8266_EDNA", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  //delay(1000);
  Serial.println(client.connected());

  client.subscribe("/lamp1/r");
  client.subscribe("/lamp1/g");
  client.subscribe("/lamp1/b");
  client.subscribe("/printer/test");
  client.onMessage(doStuff);

  //printDate();
  printTest();

  printer.feed(4);
  printer.setDefault(); // Restore printer to defaults

}

void loop() {

  client.loop();
  delay(10);

  // check if connected
  if (!client.connected()) {
    // connect();


  }

  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show();
}

void doStuff(String &topic, String &payload) {
  Serial.println(topic + " 1 : " + payload);
  Serial.println(topic + " 1 : " + payload);

  if (topic.startsWith("/lamp1/r")) {
    red = payload.toFloat() * 255.0;
  } else if (topic.startsWith("/lamp1/g")) {
    green = payload.toFloat() * 255.0;
  } else if (topic.startsWith("/lamp1/b")) {
    blue = payload.toFloat() * 255.0;
  } else if (topic.startsWith("/printer/test")) {
    printer.println(payload);
  }
}



void init_wifi() {
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  //  WiFi.hostname(espname);
  //  wifi_station_set_hostname(espname);
  //WiFiManager
  WiFiManager wm;
  // wm.resetSettings();//reset settings - for testing
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);
  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP" and goes into a blocking loop awaiting configuration
  if (!wm.autoConnect(espname)) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(1000);
  }
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeah ! :)");


}

//gets called when WiFiManager enters configuration mode
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
  //entered config mode, make led toggle faster
  ticker.attach(0.2, tick);
}

void printDate() {
  printer.feed(5);
  printer.justify('L');
  printer.printBitmap(date3_width, date3_height, date3_data);
  printer.feed(1);
  printer.justify('L');
  printer.setSize('L');
  printer.println("Mars 2022");
  printer.setSize('M');
  printer.feed(1);
  printer.println("Saint Justine");
  printer.feed(1);
  printer.justify('L');
  printer.setSize('S');
  printer.println("Au tout début de la chanson “Roxane” de The Police, si vous tendez l’oreille, STING éclate de rire parcequ’il s’est assis sur le piano");
  printer.feed(1);
  printer.println("Au tout début de la chanson “Roxane” de The Police, si vous tendez l’oreille, STING éclate de rire parcequ’il s’est assis sur le piano");
  printer.feed(2);
  printer.setSize('M');
  printer.println("Vos messages");
  printer.feed(1);
  printer.feed(5);
}

void printTest() {
  printer.println("C'est le test");

}
