FeatherRobot
======
Robot based on the AdaFruit ESP8266 Feather Huzzah, a FeatherWing motor control board and a FeatherWing oled 128x32 display.

based on: https://github.com/openhardwarerobots/esp8266-robot
[Adafruit Learn esp8266](https://learn.adafruit.com/build-an-esp8266-mobile-robot)

[Arduino IDE](https://www.arduino.cc/en/Main/Software), used 1.8.1

Also, Board for _AdaFruit Huzzah ESP8266_  

   Add this in _Additional Boards Manager URLs_: http://arduino.esp8266.com/stable/package_esp8266com_index.json

    Under <File>-<Preferences> and then goto Managing Boards

**Libraries Needed:**
------
+ [aRest](https://github.com/marcoschwartz/aREST)
+ [Adafruit_MotorShield V2](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library)
+ [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
+ [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
+ [Adafruit FeatherOLED](https://github.com/adafruit/Adafruit_FeatherOLED) - optional beta

  Install all of these libraries into the Arduino Libraries directory.

Sketches:
------
* Blink - simple blink LED test for esp8266 Huzzah
* WiFi - Log into WiFi
* WiFiList - sketch that prints (displays) list of WiFi
* FeatherOLED128x32 - Test sketch for featheroled 128x32
* esp8266-robot - basic REST interface driven robot uses interface to control robot
* interface - html based interface to REST driven robot, needs the ip and needs to be on the same network as REST robot

# Hardware:

+ [robot motors](https://www.adafruit.com/products/3244) [Learn]()
+ [esp8266 Huzzah](https://www.adafruit.com/products/2821) [Learn]()
+ [motor featherwing](https://www.adafruit.com/products/2927) [Learn]()
+ [lipo battery](https://www.adafruit.com/products/1781) [Learn]()
+ [featherwing oled 128x32](https://www.adafruit.com/products/2900) [Learn](https://learn.adafruit.com/adafruit-oled-featherwing)
+ [sensors](https://www.adafruit.com/products/1927) [Learn]()
+ [robot adafruit](https://learn.adafruit.com/curiebot-arduino-101-mini-robot-rover)
