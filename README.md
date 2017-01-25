FeatherRobot
======
Robot based on the AdaFruit ESP8266 Feather Huzzah and a FeatherWing motor control board

based on: https://github.com/openhardwarerobots/esp8266-robot

[Arduino IDE](https://www.arduino.cc/en/Main/Software), used 1.8.1

Also, Board for _AdaFruit Huzzah ESP8266_  

   Add this in _Additional Boards Manager URLs_: http://arduino.esp8266.com/stable/package_esp8266com_index.json

    Under <File>-<Preferences> and then goto Managing Boards

**Libraries Needed:**

+ [aRest](https://github.com/marcoschwartz/aREST)
+ [Adafruit_MotorShield V2](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library)
+ [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
+ [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
+ [Adafruit FeatherOLED](https://github.com/adafruit/Adafruit_FeatherOLED) - optional beta Feather_OLED library

  Install all of these libraries into the Arduino Libraries directory.

Sketches:
------
+ Blink - simple blink LED test for esp8266 Huzzah
+ WiFi - Log into WiFi
+ WiFiList - sketch that prints (displays) list of WiFi
+ esp8266-robot - basic REST interface driven robot uses interface to control robot
+ interface - html based interface to REST driven robot, needs the ip and needs to be on the same network as REST robot

# Hardware:

+ [robot motors](https://www.adafruit.com/products/3244) [Learn]()
+ [esp8266 Huzzah](https://www.adafruit.com/products/2821) [Learn]()
+ [motor featherwing](https://www.adafruit.com/products/2927) [Learn]()
+ [lipo battery](https://www.adafruit.com/products/1781) [Learn]()
+ [featherwing oled 128x32](https://www.adafruit.com/products/2900) [Learn](https://learn.adafruit.com/adafruit-oled-featherwing)
+ [sensors](https://www.adafruit.com/products/1927) [Learn]()

# Test section:
## Table:
| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

## Blockquotes
> Blockquotes are very handy in email to emulate reply text.
> This line is part of the same quote.

## inline HTML
<dl>
  <dt>Definition list</dt>
  <dd>Is something people use sometimes.</dd>

  <dt>Markdown in HTML</dt>
  <dd>Does *not* work **very** well. Use HTML <em>tags</em>.</dd>
</dl>

## Horizontals
---
Hyphens

***
Asterisks

___
Underscores

## inline code
```javascript
var s = "JavaScript syntax highlighting";
alert(s);
```
 
```python
s = "Python syntax highlighting"
print s
```
 
```
No language indicated, so no syntax highlighting. 
But let's throw in a <b>tag</b>.
```
