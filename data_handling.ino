/*
 * clear all data in variables
 */
void initialize(){
  hand = ' ';
  motion = ' ';
  effect1 = ' ';
  effect2 = ' ';
  
  for(uint8_t i = 0; i < 4; i++){
    fingers[i] = {' '};
  }
  
  for(uint8_t i = 0; i < 5; i++){
    pattern1[i] = {' '};
    for(uint8_t j = 0; j < 6; j++){
       r[i][j] = 0;
       g[i][j] = 0;
       b[i][j] = 0;
    }
  }
  for(uint8_t i = 0; i < 5; i++){
    pattern2[i] = {' '};
    for(uint8_t j = 0; j < 6; j++){
       r_[i][j] = 0;
       g_[i][j] = 0;
       b_[i][j] = 0;
    }
  }
}

/*
 * convert int to char
 */
char toChar(int x){
  char b[2];   //declaring character array
  String str;  //declaring string 
  str=String(x); //converting integer into a string
  str.toCharArray(b,2);
  return b[0];
}

void displayValues(){
  Serial.print(F("Effect1: "));Serial.println(effect1);
      Serial.print(F("Effect2: "));Serial.println(effect2);
      Serial.print(F("Hand: ")); Serial.println(hand);
      Serial.print(F("Motion: ")); Serial.println(motion);
      Serial.print(F("Sensitivity: ")); Serial.println(sensitivity);
      
      for(uint8_t i = 0; i < 5; i++){
        Serial.print(F("Finger")); Serial.println(i+1);
        for(uint8_t j = 0; j < 6; j++){
          Serial.print(r[i][j]);Serial.print(F(","));Serial.print(g[i][j]);Serial.print(F(","));Serial.print(b[i][j]);Serial.println();
        }
        Serial.println();
      }
      Serial.println(F("========================================================="));
      for(uint8_t i = 0; i < 5; i++){
        Serial.print(F("Finger_")); Serial.println(i+1);
        for(uint8_t j = 0; j < 6; j++){
          Serial.print(r_[i][j]);Serial.print(F(","));Serial.print(g_[i][j]);Serial.print(F(","));Serial.print(b_[i][j]);Serial.println();
        }
        Serial.println();
      }
      Serial.print(F("pattern 1: "));
      for(uint8_t i = 0; i < 5; i++){
        Serial.print(pattern1[i]);//Serial.print(F("\t"));
      }
      Serial.println();
      Serial.print(F("pattern 2: "));
      for(uint8_t i = 0; i < 5; i++){
        Serial.print(pattern2[i]);//Serial.print(F("\t"));
      }
      Serial.println();
      Serial.print(F("fingers: "));
      for(uint8_t i = 0; i < 4; i++){
        Serial.print(fingers[i]);//Serial.print(F("\t"));
      }
}

