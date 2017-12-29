#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include "switch.h"
#include "UpnpBroadcastResponder.h"
#include "CallbackFunction.h"

// prototypes
boolean connectWifi();

//on/off callbacks 
bool turnOnRelay();
bool turnOffRelay();


// Change this before you flash
const char* ssid = "xxxxx";
const char* password = "xxxxx";

boolean wifiConnected = false;

UpnpBroadcastResponder upnpBroadcastResponder;

Switch *outlet = NULL;

bool isturnOnRelay = false;

// For NodeMCU boards, use these constants
// const int relayPin  = D6;
// const int switchPin = D3;
// const int ledPin    = D7;

// For non-NodeMCU boards (Sonoff, Wemos), use these constants
const int relayPin  = 12;
const int switchPin = 0;
const int ledPin    = 13;

int switchState = 0;

boolean cannotConnectToWifi = false;

void setup()
{
  Serial.begin(115200);

   // Setup Relay
  pinMode(relayPin, OUTPUT);

  // Setup Switch
  pinMode(switchPin, INPUT);  

  // Setup LED
  pinMode(ledPin, OUTPUT);

//Default Relay state is on when unit is initially powered on
  turnOffRelay();
  switchState = 0;
  
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    upnpBroadcastResponder.beginUdpMulticast();
    
    // Define your switches here. Max 10
    // Format: Alexa invocation name, local port no, on callback, off callback
    outlet = new Switch("smart plug", 80, turnOnRelay, turnOffRelay);
    

    Serial.println("Adding switches upnp broadcast responder");
    upnpBroadcastResponder.addDevice(*outlet);
    
  }
}
 
void loop() 

 {
 if (digitalRead(switchPin)){
  delay(250);
  if (!digitalRead(switchPin)){
  switchState = !switchState;
  
if (switchState){
    digitalWrite(relayPin, HIGH); // turn on relay with voltage HIGH 
    digitalWrite(ledPin, LOW  ); // turn on LED with voltage HIGH 
    switchState = 1;
  }
    else
    {
    digitalWrite(relayPin, LOW);  // turn off relay with voltage LOW
    digitalWrite(ledPin, HIGH);  // turn off LED with voltage LOW
    switchState = 0;
    }
  delay(500);

  
   }
  }
 


{
	 if(wifiConnected){
      upnpBroadcastResponder.serverLoop();
      
      outlet->serverLoop();
      
	}
 }
}

bool turnOnRelay() {
    Serial.println("Switch 1 turn on ...");
    
    isturnOnRelay = true;
      
    digitalWrite(relayPin, HIGH); // turn on relay with voltage HIGH 
    digitalWrite(ledPin, LOW  ); // turn on LED with voltage HIGH 
    Serial.println("Turning on relay");
    switchState = 1;
       
    return isturnOnRelay;
    
}

bool turnOffRelay() {
    Serial.println("Switch 1 turn off ...");

    isturnOnRelay = false;

    digitalWrite(relayPin, LOW);  // turn off relay with voltage LOW
    digitalWrite(ledPin, HIGH);  // turn off LED with voltage LOW
    Serial.println("Turning off relay");
    switchState = 0;
    
    return isturnOnRelay;
    
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


