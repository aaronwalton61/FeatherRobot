// Import required libraries
#include "ESP8266WiFi.h"
#include <aREST.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Define display
Adafruit_SSD1306 display = Adafruit_SSD1306();
 
#if defined(ESP8266)
  #define BUTTON_A 0
  #define BUTTON_B 16
  #define BUTTON_C 2
  #define LED      0
#elif defined(ARDUINO_STM32F2_FEATHER)
  #define BUTTON_A PA15
  #define BUTTON_B PC7
  #define BUTTON_C PC5
  #define LED PB5
#elif defined(TEENSYDUINO)
  #define BUTTON_A 4
  #define BUTTON_B 3
  #define BUTTON_C 8
  #define LED 13
#else 
  #define BUTTON_A 9
  #define BUTTON_B 6
  #define BUTTON_C 5
  #define LED      13
#endif
 
#if (SSD1306_LCDHEIGHT != 32)
 #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// And connect 2 DC motors to port M3 & M4 !
Adafruit_DCMotor *L_MOTOR = AFMS.getMotor(1);
Adafruit_DCMotor *R_MOTOR = AFMS.getMotor(2);

// Create aREST instance
aREST rest = aREST();

// WiFi parameters
const char* ssid = "";
const char* password = "";

// The port to listen for incoming TCP connections 
#define LISTEN_PORT           80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// Function
int stop(String message);
int forward(String message);
int right(String message);
int left(String message);
int backward(String message);

void setup(void)
{  
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  
  // Start Serial
  Serial.begin(115200);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  Serial.println("OLED begun");
  
  display.display();
  delay(1000);
 
  // Clear the buffer.
  display.clearDisplay();
  display.display();
  
  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  // Init motor shield
  AFMS.begin();  

  // Functions          
  rest.function("stop", stop);
  rest.function("forward", forward);
  rest.function("left", left);
  rest.function("right", right);
  rest.function("backward", backward);
      
  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("robot");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  display.print("Connecting to ");
  display.println(ssid);
  display.display();
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(0, HIGH);
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
    // put your main code here, to run repeatedly:
    digitalWrite(0, LOW);
    delay(500);
    }
  Serial.println("");
  Serial.println("WiFi connected");
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("WiFi connected");
  display.display();
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  display.println("Server started");
  display.display();
  
  // Print the IP address
  Serial.println(WiFi.localIP());
  display.println(WiFi.localIP());
  display.display();  
}

void loop() {
  
  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
}

int stop(String command) {
  
  // Stop
    Serial.print("Stop");
  L_MOTOR->setSpeed(0);
  L_MOTOR->run( RELEASE );
 
  R_MOTOR->setSpeed(0);
  R_MOTOR->run( RELEASE );
  
}

int forward(String command) {
  
  // Stop
    Serial.print("Forward");
  L_MOTOR->setSpeed(200);
  L_MOTOR->run( FORWARD );
 
  R_MOTOR->setSpeed(200);
  R_MOTOR->run( FORWARD );
  
}

int left(String command) {
  
  // Stop
    Serial.print("Left");
  L_MOTOR->setSpeed(100);
  L_MOTOR->run( BACKWARD );
 
  R_MOTOR->setSpeed(100);
  R_MOTOR->run( FORWARD );
  
}

int right(String command) {
  
  // Stop
    Serial.print("Right");
  L_MOTOR->setSpeed(100);
  L_MOTOR->run( FORWARD );
 
  R_MOTOR->setSpeed(100);
  R_MOTOR->run( BACKWARD );
  
}

int backward(String command) {
  
  // Stop
    Serial.print("Back");
  L_MOTOR->setSpeed(150);
  L_MOTOR->run( BACKWARD );
 
  R_MOTOR->setSpeed(150);
  R_MOTOR->run( BACKWARD );
  
}
