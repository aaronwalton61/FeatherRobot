# FeatherRobot
Robot based on the AdaFruit ESP8266 Feather Huzzah and a FeatherWing motor control board

based on: https://github.com/openhardwarerobots/esp8266-robot

**Libraries Needed:**

+ [aRest](https://github.com/marcoschwartz/aREST)
+ [Adafruit_MotorShield V2](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library)

[Arduino IDE](https://www.arduino.cc/en/Main/Software), used 1.8.1

Also, Board for _AdaFruit Huzzah ESP8266_  

   Add this in _Additional Boards Manager URLs_: http://arduino.esp8266.com/stable/package_esp8266com_index.json

    Under <File>-<Preferences> and then goto Managing Boards

Sketches:

+ Blink - simple blink LED test for esp8266 Huzzah
+ WiFi - Log into WiFi
+ WiFiList - sketch that prints (displays) list of WiFi
+ esp8266-robot - basic REST interface driven robot uses interface to control robot
+ interface - html based interface to REST driven robot, needs the ip and needs to be on the same network as REST robot
