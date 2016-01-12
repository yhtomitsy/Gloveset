/*
 * interupt for push button
 */
void pushButton(){
  //digitalWrite(9, LOW); // send BLE module to sleep
  initialize(); // clear all buffered data
  active = false;
  if((millis() - lastButtonPress) > 2000){  
    //get number of saved presets
    uint8_t numOfPresets = 0;
    if(EEPROM.read(0) < 4)numOfPresets++;
    if(EEPROM.read(15) < 4)numOfPresets++;
    if(EEPROM.read(30) < 4)numOfPresets++;
    
    Serial.print(F("Number of presets: "));Serial.println(numOfPresets);
    if(numOfPresets > 0){
      presetsCount++; // move to next saved preset
      if(presetsCount > numOfPresets+1){
        presetsCount = 0; // go back to the first preset
      }
      if(presetsCount <= numOfPresets){
        //if (active == false)active = true; // enable controller
        eeprom = true;
        if (presetsCount == 0){
          // use modes in the commands variable
          dataCaptureComplete = true;  
        }
        else readSavedPresets(); // get modes from EEPROM
      }
      else if(presetsCount == (numOfPresets+1)){
        for(uint8_t i = 0; i < 4; i++) setColor(i,0,0,0);
        active = false; // disable controller
        digitalWrite(9, HIGH); // wake up BLE module
      }
      Serial.print(F("Preset: "));Serial.println(presetsCount);
    } 
    else{
      Serial.print(F("no saved presets"));
      digitalWrite(9, HIGH); // wake up BLE module
    }
    lastButtonPress = millis();
  }
}
  

/*
 * accelerometer interrupt
 */
void accelInterrupt(){
  //activity
  if(adxl.triggered(interrupts, ADXL345_ACTIVITY)){
    sequence = 2; // if active set sequence to 2
    timing = millis()/1000;  
  }
}

/*
 * checks if the state of the glove (inactive or active) has changed
 */
boolean changeMode(){
  float current = millis()/1000; 
  boolean change = false;
  if ((current - timing) >= 1) sequence = 1; // if its been a second since activity trigger set sequence back to 1
  if(gloveMoving && sequence == 1)change = true;
  if(!gloveMoving && sequence == 2)change = true;
  return change;
}



