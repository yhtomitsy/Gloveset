/*
 * sets up parameters for the accelerometer
 */
void setupAccelerometer(){ 
  adxl.standby(); // set accelerometer on standby
  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(23); //62.5mg per increment preferably between 75 and 70
 
  //look of activity movement on this axes - 1 == on; 0 == off 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
  
  //setting activity interupt to take place on int pin 1
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
  // set activity interrupt on
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
}

/*
 * sets up the neopixels
 */
void setupNeopixels(){ 
  //begin neopixels
  strip.begin();
  strip1.begin();
  strip2.begin();
  strip3.begin();
  // intialize them to off state
  strip.show();
  strip1.show();
  strip2.show();
  strip3.show();
}

/*
 * change adxl345 sensitivity
 */
void changeSensitivity(int sensitive){
  //Serial.println(F("set sensitivity"));
  adxl.setActivityThreshold(sensitive); //62.5mg per increment
  adxl.powerOn(); // begin measurements
  delay(10);
  //Serial.println(F("ready!"));
  //Serial.print(F("Sensitivity: "));Serial.println(sensitive);
}

