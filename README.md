#Arduino Esp8266 Alexa Multiple Belkin wemo switch emulator

This project supports emulating upto 14 belkin wemo switches using 1 ESP 8266  chip.

Parts you need:

WeMos D1-mini ($4.00)  http://www.aliexpress.com/store/product/D1-mini-Mini-NodeMcu-4M-bytes-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266/1331105_32529101036.html

How to use:

1. Download the code
2. Open wemos.ino in the Arduino editor.
3. Change the WI-FI settings. 
4. Define switches and callbacks
5. Flash 
6. Quick test via browser example: To turn on switch #1 http://IP_ADDRESS:80/upnp/control/basicevent1?SetBinaryState=SetBinaryState%3CBinaryState%3E1%3C/BinaryState%3E and to turn it back off http://IP_ADDRESS:80/upnp/control/basicevent1?SetBinaryState=SetBinaryState%3CBinaryState%3E0%3C/BinaryState%3E
7. Enjoy

## Do you want to turn on / off your TV, AirCon (AC) using Amazon Alexa? Checkout my latest project https://irdevkit.com/

Previous post on single wemo switch
https://github.com/kakopappa/arduino-esp8266-alexa-wemo-switch/edit/master/README.md

### If you have issues discovering please consider using sinric smart home skill. 
https://github.com/kakopappa/arduino-esp8266-alexa-wemo-switch/issues/7#issuecomment-355533848
* [sinric.com](https://sinric.com) 


### Articles about the Wemos switch
* [monkeytypewritr](https://medium.com/@monkeytypewritr/amazon-echo-esp8266-iot-a42076daafa5#.oc4od1xa0)


### Credits

- makermusings - [GitHub](https://github.com/makermusings/fauxmo)

### Developed By

* Aruna Tennakoon
 * [paypal.me/arunat](http://paypal.me/arunat)
