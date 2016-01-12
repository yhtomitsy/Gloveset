/*
 * save favorite modes in EEPROM
 */
void saveToEEPROM(int val){
  EEPROM.write(addr, val); // write EEPROM address
  addr++; // move to next address
  if(addr == EEPROM.length()) // resolve address back to 0 if end of EEPROM is reached
    addr = 0;
  delay(1);
}

/*
 * save favorite modes in EEPROM
 */
void saveToEEPROM2(int val){
  EEPROM.write(addr2, val);
  addr2++;
  if(addr2 == EEPROM.length())
    addr2 = 0;
  delay(1);
}

/*
 * record the number of saved presets
 */
void recordPresetNumber(){
  int i = EEPROM.read(1000); // read last added preset index from EEPROM
  if (i >= 3) i=0; // if its 3 then initialize it to 1
  EEPROM.write(1000,i+1); // store the new index of last added preset
}

/*
 * select the initial saving address for each preset
 */
void selectPresetLocation(){
  uint8_t i = EEPROM.read(1000);
  if (i >= 3 || i == 0){
    addr = 0; // if there are already 3 latest saved presets, replace the first one
    addr2 = 50;
  }
  else if (i == 1){
    addr = 15; // if there is one latest saved preset, replace the second one
    addr2 = 125;
  }
  else if (i == 2){
    addr = 30; // // if there is 2 latest saved preset, replace the third one
    addr2 = 200;
  }
}

/*
 * read presets store in EEPROM
 */
void readSavedPresets(){
  initialize(); // clear all data in all variables before getting data from EEPROM 
  uint8_t numOfPresets = 0;
  if(EEPROM.read(0) < 4)numOfPresets++;
  if(EEPROM.read(15) < 4)numOfPresets++;
  if(EEPROM.read(30) < 4)numOfPresets++; 
  
  if(numOfPresets > 0){ // Presets are available
    if(presetsCount == 1){ // Preset 1 selected
      addr = 0; // initialize start addresses of first Presets
      addr2 = 50; // initialize start address of colors for first preset
      getPreset(); // get the preset mode
    }
    else if(presetsCount == 2){ // Preset 1 selected
      addr = 15; // initialize start addresses of second Presets
      addr2 = 125; // initialize start address of colors for second preset
      getPreset(); // get the preset mode
    }
    else if(presetsCount == 3){
      addr = 30; // initialize start addresses of first Presets
      addr2 = 200; // initialize start address of colors for first preset
      getPreset(); // get the preset mode
    }
  }
  displayValues(); 
}

/*
 * get the numbers
 */
void getNumbers(uint8_t adr, uint8_t row,uint8_t mode){
  uint8_t j = 0;
  for(uint8_t i = 0; i < (3*EEPROM.read(adr)); i++){ // get rgb values upto end of colors for that finger
    if(mode == 1){
      r[row][j] = EEPROM.read(addr2+i);
      i++;
      g[row][j] = EEPROM.read(addr2+i);
      i++;
      b[row][j] = EEPROM.read(addr2+i);
      j++;
    }
    else if(mode == 2){
      r_[row][j] = EEPROM.read(addr2+i);
      i++;
      g_[row][j] = EEPROM.read(addr2+i);
      i++;
      b_[row][j] = EEPROM.read(addr2+i);
      j++;
    }
  }
  addr2 = addr2 + (3*EEPROM.read(adr)); // set start EEPROM address to the begining of next finger colors
}

/*
 * get parameters
 */
void getParameters(uint8_t finger, uint8_t adr, uint8_t mode){
   fingers[finger] = toChar(EEPROM.read(adr)); // get finger
   if(EEPROM.read(adr) != 0){ // finger is not 0
     if(mode == 1){
        pattern1[(EEPROM.read(adr))-1] = toChar(EEPROM.read(adr+1)); // get first pattern
     }
     else if(mode == 2){
        pattern2[EEPROM.read(adr)-1] = toChar(EEPROM.read(adr+1)); //get second pattern
     }
     getNumbers(adr+2,EEPROM.read(adr)- 1, mode); // get rgb values of colors for each finger
   }
   else if(EEPROM.read(adr) == 0){ // if finger is 0
     if(mode == 1){
        pattern1[4] = toChar(EEPROM.read(adr+1)); // get first pattern
     }
     else if(mode == 2){
        pattern2[4] = toChar(EEPROM.read(adr+1)); //get second pattern
     }
     getNumbers(adr+2,4,mode); // get rgb values of colors for each finger and save them in 5th row 
     duplicateColorValues(mode); // duplicate values of 5th row to all other rows
   }
}

/*
 * get full presets
 */
void getPreset(){
  if(EEPROM.read(addr) == 3){ // preset has motion
    motion = 'Y';
    sensitivity = EEPROM.read(addr+1); 
    hand = toChar(EEPROM.read(addr+2));
          
    effect1 = toChar(EEPROM.read(addr+3));
    getParameters(0, addr+4, 1); 
  
    effect2 = toChar(EEPROM.read(addr+7)); 
    getParameters(1, addr+8, 2); 
  }
  else if(EEPROM.read(addr) < 3){ // preset has no motion
    hand = toChar(EEPROM.read(addr)); 
    effect1 = toChar(EEPROM.read(addr+1)); 
   
    getParameters(0, addr+2, 1); // get mode and colors for first finger addr+2
    if(fingers[0] != '0'){ // different mode set for each finger
       getParameters(1, addr+5, 1); 
       getParameters(2, addr+8, 1);
       getParameters(3, addr+11, 1); 
     }
  }
}

/*
 * Clear save modes
 */
void clearSavedPaterns(){
  uint8_t numOfPresets = 0;
  if(EEPROM.read(0) < 4)EEPROM.write(0, 255);
  if(EEPROM.read(15) < 4)EEPROM.write(15, 255);
  if(EEPROM.read(30) < 4)EEPROM.write(30, 255);
  EEPROM.write(1000,255);
}

