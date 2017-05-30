#include "WemoManager.h"
#include "WemoSwitch.h"
#include <functional>

// Multicast declarations
IPAddress ipMulti(239, 255, 255, 250);
const unsigned int portMulti = 1900;
char packetBuffer[512];

#define MAX_SWITCHES 14
WemoSwitch switches[MAX_SWITCHES] = {};
int numOfSwitchs = 0;

//#define numOfSwitchs (sizeof(switches)/sizeof(Switch)) //array size

//<<constructor>>
WemoManager::WemoManager(){

}

//<<destructor>>
WemoManager::~WemoManager(){/*nothing to destruct*/}

bool WemoManager::begin(){
  boolean state = false;

  Serial.println("Begin multicast ..");

  if(UDP.beginMulticast(WiFi.localIP(), ipMulti, portMulti)) {
    Serial.print("Udp multicast server started at ");
    Serial.print(ipMulti);
    Serial.print(":");
    Serial.println(portMulti);

    state = true;
  }
  else{
    Serial.println("Connection failed");
  }

  return state;
}

//Switch *ptrArray;

void WemoManager::addDevice(WemoSwitch& device) {
  Serial.print("Adding switch : ");
  Serial.print(device.getAlexaInvokeName());
  Serial.print(" index : ");
  Serial.println(numOfSwitchs);

  switches[numOfSwitchs] = device;
  numOfSwitchs++;
}

void WemoManager::serverLoop(){

  int packetSize = UDP.parsePacket();
  if (packetSize > 0)
  {
    IPAddress senderIP = UDP.remoteIP();
    unsigned int senderPort = UDP.remotePort();

    // read the packet into the buffer
    UDP.read(packetBuffer, packetSize);

    // check if this is a M-SEARCH for WeMo device
    String request = String((char *)packetBuffer);
    // Serial.println("----------");
    // Serial.println(request);
    // Serial.println("-----------");
    if(request.indexOf('M-SEARCH') > 0) {
        if((request.indexOf("urn:Belkin:device:**") > 0) || (request.indexOf("ssdp:all") > 0) || (request.indexOf("upnp:rootdevice") > 0)) {
          Serial.println("Got UDP Belkin Request..");

          // int arrSize = sizeof(switchs) / sizeof(Switch);

          for(int n = 0; n < numOfSwitchs; n++) {
              WemoSwitch &sw = switches[n];

              if (&sw != NULL) {
                sw.respondToSearch(senderIP, senderPort);
              }
          }
        }
    }
  }

  for(int i = 0; i < numOfSwitchs; i++) {
      WemoSwitch &swit = switches[i];

      if (&swit != NULL) {
        swit.serverLoop();
      }
  }
}
