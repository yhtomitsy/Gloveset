//***************************** Extract parameters from commands string **********************************************
void parseData(){
  initialize(); // clear all data in all variables before saving
  if(forSaving)motion = comands.substring(2,3)[0]; // check if the mode has motion control
  else motion = comands.substring(0,1)[0]; // check if the mode has motion control
  
  if (motion == 'Y'){ // motion control activated
    if(forSaving){
      selectPresetLocation();// set EEPROM initial address
      saveToEEPROM(3);
    }
    // get sensitivity
    sensitivity = 0; 
    String comandBuffer  = comands.substring(comands.indexOf("S",comands.indexOf("Y") )+1, comands.indexOf("H")-1);
    for (uint8_t i = 0; i < comandBuffer.length(); i++){
      sensitivity = (sensitivity*10) + (comandBuffer[i] - '0');
    }
    delay(10);
    if(forSaving)saveToEEPROM(sensitivity);
    
    
    // get the hand number
    hand  = comands.substring(comands.indexOf("H")+1, comands.indexOf("|"))[0];
    if(forSaving)saveToEEPROM(hand-'0');
  
    //get parameters of first sequence
    uint8_t startIndex = comands.indexOf("(");
    uint8_t stopIndex = comands.indexOf(")", startIndex);
    String firstMode = comands.substring(startIndex+1, stopIndex); // get commands for first sequence
    
    effect1 = firstMode.substring(firstMode.indexOf("E")+1, firstMode.indexOf(",", firstMode.indexOf("E")))[0]; // get effect of first sequence
    if(forSaving)saveToEEPROM(effect1 - '0');
    
    for (int i=0; i < firstMode.length(); i++){
      if (firstMode[i] == 'F'){
        getFingers(firstMode.substring(i, firstMode.indexOf("|", i)), 1); //get the order and number of fingers and colors of each finger
      }
    }
    firstMode = "";
     
    // get parameters of second sequence
    startIndex = comands.indexOf("(", stopIndex);
    stopIndex = comands.indexOf(")", startIndex);
    String secondMode = comands.substring(startIndex+1, stopIndex); // get commands for second sequence
    
    effect2 = secondMode.substring(secondMode.indexOf("E")+1, secondMode.indexOf(",", secondMode.indexOf("E")))[0]; // get effect of second sequence 
    if(forSaving){
      saveToEEPROM(effect2 - '0');
      recordPresetNumber(); // record the position of the latest saved preset   
    }
    
    for (int i=0; i < secondMode.length(); i++){
      if (secondMode[i] == 'F'){
        getFingers(secondMode.substring(i, secondMode.indexOf("|", i)), 2); //get the order and number of fingers and colors of each finger
      }
    }
    secondMode = ""; 
  }
  else { // motion is not activated
    if(forSaving)hand = comands.substring(2,3)[0]; // get value of hand
    else hand = comands.substring(0,1)[0]; // get value of hand
    if(forSaving){
      selectPresetLocation();// set EEPROM initial address
      saveToEEPROM(hand - '0');
    }
    
    effect1 = comands.substring(comands.indexOf("E")+1, comands.indexOf(",", comands.indexOf("E")))[0]; // get effect
    if(forSaving){
      saveToEEPROM(effect1 - '0');
      recordPresetNumber(); // record the position of the latest saved preset
    }
    
    for (int i=0; i < comands.length(); i++){
      if (comands[i] == 'F'){
        getFingers(comands.substring(i, comands.indexOf("\n", i)), 1); //get the order and number of fingers and colors of each finger
        break;
      }
    }    
  }
}

/*
 * get finger numbers
 */
void getFingers(String string, uint8_t mode){
  uint8_t fingerCount = 0; // holds number of times F appears in the comand string
  
  for (int i=0; i < string.length(); i++){
    if (string[i] == 'F'){
      fingers[fingerCount]= string.substring(i+1, i+2)[0]; // copy value of F to finger array
      if(forSaving)saveToEEPROM(fingers[fingerCount]-'0');
      
      if(mode == 1){
        uint8_t n = 0;
        if(fingers[fingerCount] == '1') n = 0;
        else if(fingers[fingerCount] == '2') n = 1;
        else if(fingers[fingerCount] == '3') n = 2;
        else if(fingers[fingerCount] == '4') n = 3;
        else if(fingers[fingerCount] == '0') n = 4;
        pattern1[n] = string.substring(i+4, string.indexOf(";", i+3))[0]; // get value of pattern
        if(forSaving)saveToEEPROM(pattern1[n]-'0');
      }
      else if(mode == 2){
        uint8_t n = 0;
        if(fingers[fingerCount] == '1') n = 0;
        else if(fingers[fingerCount] == '2') n = 1;
        else if(fingers[fingerCount] == '3') n = 2;
        else if(fingers[fingerCount] == '4') n = 3;
        else if(fingers[fingerCount] == '0') n = 4;
        pattern2[n] = string.substring(i+4, string.indexOf(";", i+3))[0]; // get value of pattern
        if(forSaving)saveToEEPROM(pattern2[n]-'0');
      }

      String colorString = string.substring(i+5, string.indexOf("|", i+5)); // get string that contains color RGB values
      parseColors1(colorString,fingers[fingerCount], mode); // get rgb values of the colors that belong to the finger
      fingerCount++; // increase count 
    }
  }
  string = "";
}

/*
 * get colors for first sequence
 */
void parseColors1(String string, char finger, uint8_t mode){
  //get semi collon count = number of colors in sequence
  uint8_t semiCount = 0;
  uint8_t arrayRow;
  
  //select the array colum that the rgb values will go to
  if(finger == '1') arrayRow = 0;
  else if(finger == '2') arrayRow = 1;
  else if(finger == '3') arrayRow = 2;
  else if(finger == '4') arrayRow = 3;
  else if(finger == '0') arrayRow = 4;

  
  
  for (int i=0; i < string.length(); i++){
    if (string[i] == ';')semiCount++;
  }
  if(forSaving)saveToEEPROM(semiCount);

  
  // get value of colors
  uint8_t startIndex = 0, stopIndex = 0;
  if (semiCount >= 1){
    startIndex = string.indexOf(";");
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][0],&g[arrayRow][0],&b[arrayRow][0],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 0, mode); //save rgb values in EEPROM
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][0],&g_[arrayRow][0],&b_[arrayRow][0],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 0, mode); //save rgb values in EEPROM
    }
  }
  if (semiCount >= 2){
    startIndex = stopIndex;
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][1],&g[arrayRow][1],&b[arrayRow][1],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 1, mode); //save rgb values in EEPROM
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][1],&g_[arrayRow][1],&b_[arrayRow][1],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 1, mode); //save rgb values in EEPROM
    }
  }
  if (semiCount >= 3){
    startIndex = stopIndex;
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][2],&g[arrayRow][2],&b[arrayRow][2],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 2, mode); //save rgb values in EEPROM      
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][2],&g_[arrayRow][2],&b_[arrayRow][2],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 2, mode); //save rgb values in EEPROM
    }
  }
  if (semiCount >= 4){
    startIndex = stopIndex;
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][3],&g[arrayRow][3],&b[arrayRow][3],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 3, mode); //save rgb values in EEPROM
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][3],&g_[arrayRow][3],&b_[arrayRow][3],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 3, mode); //save rgb values in EEPROM
    }
  }
  if (semiCount >= 5){
    startIndex = stopIndex;
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][4],&g[arrayRow][4],&b[arrayRow][4],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 4, mode); //save rgb values in EEPROM
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][4],&g_[arrayRow][4],&b_[arrayRow][4],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 4, mode); //save rgb values in EEPROM
    }
  }
  if (semiCount >= 6){
    startIndex = stopIndex;
    stopIndex = string.indexOf(";", startIndex+1);
    if (mode == 1){
      extractColors(&r[arrayRow][5],&g[arrayRow][5],&b[arrayRow][5],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 5, mode); //save rgb values in EEPROM
    }
    else if (mode == 2){
      extractColors(&r_[arrayRow][5],&g_[arrayRow][5],&b_[arrayRow][5],string.substring(startIndex, stopIndex));
      saveColors(arrayRow, 5, mode); //save rgb values in EEPROM
    }
  }
  
  if(finger == '0')duplicateColorValues(mode);
  
}

/*
 * save colors on EEPROM
 */
void saveColors(uint8_t i, uint8_t j, uint8_t mode){
  if(forSaving){
    if(mode == 2){
      saveToEEPROM2(r_[i][j]);
      saveToEEPROM2(g_[i][j]);
      saveToEEPROM2(b_[i][j]);
    }
    else if(mode == 1){
      saveToEEPROM2(r[i][j]);
      saveToEEPROM2(g[i][j]);
      saveToEEPROM2(b[i][j]);
    }
  }
}

/*
 * duplicate common colors to all 
 */
  void duplicateColorValues(uint8_t mode){
    if (mode == 1){
      for(uint8_t i = 0; i < 4; i++){
        pattern1[i] = pattern1[4]; // make all pattern values be equal
        for(uint8_t j = 0; j < 6; j++){
          r[i][j] = r[4][j];
          g[i][j] = g[4][j];
          b[i][j] = b[4][j];
        }
      }
    }
    else if (mode == 2){
      for(uint8_t i = 0; i < 4; i++){
        pattern2[i] = pattern2[4]; // make all pattern values be equal
        for(uint8_t j = 0; j < 6; j++){
          r_[i][j] = r_[4][j];
          g_[i][j] = g_[4][j];
          b_[i][j] = b_[4][j];
        }
      }
    }
  }

/*
 * extract rgb values from the string
 */
void extractColors(uint8_t *r, uint8_t *g, uint8_t *b, String color){
  *r = 0; // initialize r
  uint8_t startIndex = color.indexOf(";");
  uint8_t endIndex = color.indexOf(",", startIndex);
  String buff = color.substring(startIndex+1, endIndex);
  for (uint8_t i = 0; i < buff.length(); i++){
   *r = (*r*10) + (buff[i] - '0');
  } 
  *g = 0; //initialize g1
  startIndex = endIndex;
  endIndex = color.indexOf(",", startIndex+1);
  buff = color.substring(startIndex+1, endIndex);
  for (uint8_t i = 0; i < buff.length(); i++){
   *g = (*g*10) + (buff[i] - '0');
  }
  *b = 0; //initialize g1
  startIndex = endIndex;
  endIndex = color.indexOf("\n", startIndex+1);
  buff = color.substring(startIndex+1, endIndex);
  for (uint8_t i = 0; i < buff.length(); i++){
   *b = (*b*10) + (buff[i] - '0');
  }
}

