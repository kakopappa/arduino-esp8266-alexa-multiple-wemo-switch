#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include "switch.h"
#include "UpnpBroadcastResponder.h"
#include "CallbackFunction.h"

// prototypes
boolean connectWifi();
void s1On();
void s1Off();
void s2On();
void s2Off();

const char* ssid = "Aruna";
const char* password = "********";

boolean wifiConnected = false;

UpnpBroadcastResponder upnpBroadcastResponder;

// Define all switches here. Max 14
// Format: Alexa invocation name, local port no, on callback, off callback
Switch s1("office lights", 1501, s1On, s1Off);
Switch s2("kitchen lights", 1502, s2On, s2Off);

void setup()
{
  Serial.begin(115200);
   
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    upnpBroadcastResponder.beginUdpMulticast();
    
    // Add your switches here
    upnpBroadcastResponder.addDevice(s1);
    upnpBroadcastResponder.addDevice(s2);
  }
}
 
void loop()
{
	 if(wifiConnected){
      upnpBroadcastResponder.serverLoop();
	 }
}

void s1On() {
    // Switch 1 turn on
}

void s1Off() {
  // Switch 1 turn off
}


void s2On() {
    // Switch 2 turn on
}

void s2Off() {
  // Switch 2 turn off
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 10){
      state = false;
      break;
    }
    i++;
  }
  
  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  
  return state;
}
