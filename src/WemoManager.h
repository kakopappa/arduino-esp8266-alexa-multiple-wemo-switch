#ifndef WemoManager_h
#define WemoManager_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include "WemoSwitch.h"

class WemoManager {
private:
        WiFiUDP UDP;
public:
        WemoManager();
        ~WemoManager();
        bool begin();
        void serverLoop();
        void addDevice(WemoSwitch& device);
};

#endif
