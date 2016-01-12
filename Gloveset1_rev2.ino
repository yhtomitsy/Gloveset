#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ADXL345.h>

#define DEVICE 0x53 // adxl345 address

// declaring neopixel parameters
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 7, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, 6, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, 5, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(1, 4, NEO_RGB + NEO_KHZ800);

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

SoftwareSerial BLESerial(10, 11); // pin 10 - RX   pin 11 - TX

// global variables
uint8_t sequence = 0;
uint8_t sensitivity = 0;//  = 20;
volatile uint8_t presetsCount = 0;

char hand = ' ';
char motion = ' ';
char effect1 = ' ', effect2 = ' ';
char pattern1[5] = {'\0'}, pattern2[5] = {'\0'};;
char fingers[4] = {'\0'};

// store the rgb values of received colors
uint8_t r[5][6] = {0};
uint8_t g[5][6] = {0};
uint8_t b[5][6] = {0};
uint8_t r_[5][6] = {0};
uint8_t g_[5][6] = {0};
uint8_t b_[5][6] = {0};

String comands = ""; // stores incoming string

volatile boolean active = false; // activates or diactivates the controller
volatile long lastButtonPress = 0; // stores the last time the button was pressed
boolean commandsEmpty = false; // indicates comands variable state
boolean store = false;
volatile boolean dataCaptureComplete = true; // indicates if all the serial incoming data has been received

uint8_t effect3Delay = 10; // delay in knight rider mode 3

int addr = 0; // EEPROM address 
int addr2 = 0; // EEPROM address 2
boolean forSaving = false;

byte interrupts; // stores the accelerometer interrupt source
float timing = 0; // delay before glove can be said to be inactive
boolean gloveMoving = false; //indicates hands motion status

// handle serial data from BT module
char c;
String x = "";
boolean z = false;
boolean eeprom = false;

void setup() {
  Serial.begin(9600);  // serial communication  
  BLESerial.begin(9600); // set baud rate for communication between BLE  
  Wire.begin();
  setupNeopixels(); // setup neopixels
  setupAccelerometer(); // setup accelerometer
  
  // interrupts
  attachInterrupt(0, accelInterrupt, HIGH);
  attachInterrupt(1, pushButton, RISING);

  // set mode of ble wake pin
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  delay(1000);
}

void loop() { 
  if(BLESerial.available()){
    c = ' '; // clear incoming character
    c= char(BLESerial.read()); //read serial input
    if (c == 'S') z = true;
    if (c == ',') z = false;
    if (c == 'R'){
      store = false;
      if(!commandsEmpty){ // commands are available
        active = false;
        comands = ""; // empty commands
        commandsEmpty = true;
        //Serial.println(F("going to standby mode"));
        adxl.standby();
        //Serial.println(F("ready!"));
      }
    }
    if (c == 'V')store = true;
    if (store){
      if (c != 'V'&& c != '=' && c != '\n' && c != '\r' && c != '#' && c != ' '){
        comands += c;
        if (z && c != 'S'){
          x += c;
        }
      }
      else if (c == '#'){
        Serial.println(comands);
        changeSensitivity(x.toInt());
        x = "";
        dataCaptureComplete = true; // indicate that data has been completely captured
        commandsEmpty = false;
        active = true;
      }
    }
  }
  //Serial.println(active);
  if (active == true){
    //digitalWrite(9, LOW); // send BLE module to sleep
    if(comands[0] == 'M' && dataCaptureComplete){ // check if there are any favorite preset that have been sent and save them  
      noInterrupts();
      forSaving = true; // indicates the received modes are for saving in EEPROM
      parseData(); // save data
      comands = "";
      dataCaptureComplete = false;
      forSaving = false; // saving complete 
      interrupts();
    }   
    if(dataCaptureComplete && comands == "c"){ // clear saved modes
      noInterrupts();
      clearSavedPaterns();
      dataCaptureComplete = false;
      active = false;
      comands = "";
      interrupts();
    }
    if (dataCaptureComplete && comands != ""){ // if there is no favorite presets get data the send command
      noInterrupts();
      parseData(); // parse data  
      dataCaptureComplete = false;
      interrupts();
      displayValues();
    }
    
    if (hand == '0' || hand == '2'){ // check if its the correct hand
      if (motion == 'Y'){ // motion control
        accelerometer();
      }
      else{ // no motion control 
        selectEffect(effect1);
      }
    }
  }
  else if (active == false){  
    if (eeprom){ // if data is from eeprom
      //Serial.println(F("Setting up module"));
      adxl.standby();
      if(motion == 'Y'){
        changeSensitivity(sensitivity); // change sensitivity
      }
      active = true;
      eeprom = false;
    }
  }
}
