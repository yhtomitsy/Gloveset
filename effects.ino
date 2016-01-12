//************************************ Effects *****************************************************

void rainbow(uint8_t wait) {
  uint16_t j;
  for(j=0; j<256; j++) {    
    if(motion == 'Y')if(changeMode())return;
    strip.setPixelColor(0, Wheel((0+j) & 255));
    //if(motion == 'Y')if(changeMode())return;
    strip1.setPixelColor(0, Wheel((0+j) & 255));
    //if(motion == 'Y')if(changeMode())return;
    strip2.setPixelColor(0, Wheel((0+j) & 255));
    //if(motion == 'Y')if(changeMode())return;
    strip3.setPixelColor(0, Wheel((0+j) & 255));
    
    if(motion == 'Y')if(changeMode())return;
    
    strip.show();
    strip1.show();
    strip2.show();
    strip3.show();
    if(motion == 'Y')if(changeMode())return;
    delay(wait);
    //if(motion == 'Y')if(changeMode())return;
  }
}

// Slightly different, this makes the rainbow equally distributed on all four fingers
void rainbowCycle(uint8_t wait) {
  uint16_t j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    if(motion == 'Y')if(changeMode())return;
    
    strip.setPixelColor(0, Wheel(((0 * 256 / 4) + j) & 255));
    strip.show();
    delay(wait);
    
    if(motion == 'Y')if(changeMode())return;
    
    strip1.setPixelColor(0, Wheel(((1 * 256 / 4) + j) & 255));
    strip1.show();
    delay(wait);
    
    if(motion == 'Y')if(changeMode())return;
    
    strip2.setPixelColor(0, Wheel(((2 * 256 / 4) + j) & 255));
    strip2.show();
    delay(wait);
    
    if(motion == 'Y')if(changeMode())return;
    
    strip3.setPixelColor(0, Wheel(((3 * 256 / 4) + j) & 255));
    strip3.show();
    delay(wait);
    
    if(motion == 'Y')if(changeMode())return;
  }
}

void accelerometer(){ 
  //getInterruptSource clears all triggered actions after returning value
  //so do not call again until you need to recheck for triggered actions
  interrupts = adxl.getInterruptSource();
  
  float current = millis()/1000;
  if ((current - timing) >= 1) sequence = 1; // if its been a second since activity trigger set sequence back to 1
  
  if(sequence == 1){
    gloveMoving = false;
    selectEffect(effect1); 
  }
  else if(sequence == 2){
    gloveMoving = true;
    selectEffect(effect2);
  }
}

void knightRiderMode4(){
  for (uint8_t i = 0; i < 6; i++){
    if(motion == 'Y')if(changeMode())return; // checks for change of motion
    if(i == 0){
      Clear();
      choosePattern(0,1);
      choosePattern(3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 1){
      choosePattern(3,8);
      choosePattern(0,8);
      choosePattern(1,1);
      choosePattern(2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 2){
      setColor(0,0,0,0);
      setColor(3,0,0,0);
      choosePattern(1,1);
      choosePattern(2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 3){
      choosePattern(1,8);
      choosePattern(2,8);
      choosePattern(0,1);
      choosePattern(3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 4){
      setColor(1,0,0,0);
      setColor(2,0,0,0);
      choosePattern(0,8);
      choosePattern(3,8);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 5){
      setColor(0,0,0,0);
      setColor(3,0,0,0);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(50);
    if(motion == 'Y')if(changeMode())return;
  }
  if(motion == 'Y')if(changeMode())return;
}
void knightRiderMode3(uint8_t wait){
  for (uint8_t i = 0; i < 6; i++){
    if(motion == 'Y')if(changeMode())return;
    if (i == 0){
      selectiveClear(i);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 1){
      setColor(0,0,0,0);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 2){
      setColor(1,0,0,0);
      choosePattern(i-2,1);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 3){
      setColor(2,0,0,0);
      setColor(0,0,0,0);
      choosePattern(i-2,1);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 4){
      setColor(3,0,0,0);
      setColor(1,0,0,0);
      choosePattern(i-2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 5){
      setColor(2,0,0,0);
      choosePattern(i-2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(wait);
  }
  if(motion == 'Y')if(changeMode())return;
  
  for (uint8_t i = 6; i >0; i--){
    if(motion == 'Y')if(changeMode())return;
    if (i == 1){
      setColor(1,0,0,0);
      choosePattern(i-1,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 2){
      setColor(2,0,0,0);
      setColor(0,0,0,0);  
      choosePattern(i-1,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 3){
      setColor(1,0,0,0);
      setColor(3,0,0,0);
      choosePattern(i-3,1);
      choosePattern(i-1,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 4){
      setColor(2,0,0,0);
      choosePattern(i-3,1);
      choosePattern(i-1,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 5){
      setColor(3,0,0,0);
      choosePattern(i-3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 6){
      choosePattern(i-3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(wait);
  }
  if(motion == 'Y')if(changeMode())return;
}
void knightRiderMode2(){
  for (uint8_t i = 0; i < 4; i++){
    if(motion == 'Y')if(changeMode())return;
    if(i == 0){
      Clear();
      choosePattern(i,1);
      choosePattern(3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 1){
      choosePattern(i-1,8);
      choosePattern(3,8);
      choosePattern(i,1);
      choosePattern(2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 2){
      setColor(0,0,0,0);
      setColor(3,0,0,0);
      choosePattern(1,8);
      choosePattern(2,8);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 3){
      setColor(1,0,0,0);
      setColor(2,0,0,0);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(10);
  }
  if(motion == 'Y')if(changeMode())return;
  delay(100);
  
  for (uint8_t i = 0; i < 4; i++){
    if(motion == 'Y')if(changeMode())return;
    if(i == 0){     
      choosePattern(1,1);
      choosePattern(2,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 1){
      choosePattern(i,8);
      choosePattern(2,8);
      choosePattern(i-1,1);
      choosePattern(3,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 2){
      setColor(1,0,0,0);
      setColor(2,0,0,0);
      choosePattern(0,8);
      choosePattern(3,8);
      if(motion == 'Y')if(changeMode())return;
    }
    else if(i == 3){
      setColor(0,0,0,0);
      setColor(3,0,0,0);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(10);
  }
  if(motion == 'Y')if(changeMode())return;
}

void knightRiderMode1(){
  for (uint8_t i = 0; i < 7; i++){
    if(motion == 'Y')if(changeMode())return;
    if (i == 0){
      selectiveClear(i);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 1){
      choosePattern(i-1,4);  
      choosePattern(i,1);
    }
    else if (i == 2){
      choosePattern(i-2,8);
      choosePattern(i-1,4);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 3){
      setColor(0,0,0,0);
      choosePattern(i-2,8);
      choosePattern(i-1,4);
      choosePattern(i,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 4){
      setColor(1,0,0,0);
      choosePattern(i-2,8);
      choosePattern(i-1,4);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 5){
      setColor(2,0,0,0);
      choosePattern(i-2,8);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 6){
      setColor(3,0,0,0);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(10);
  }
  if(motion == 'Y')if(changeMode())return;
  for (uint8_t i = 7; i >0; i--){
    if(motion == 'Y')if(changeMode())return;
    if (i == 1){
      setColor(0,0,0,0);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 2){
      setColor(1,0,0,0);
      choosePattern(i-2,8);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 3){
      setColor(2,0,0,0);
      choosePattern(i-2,8);
      choosePattern(i-3,4);  
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 4){
      setColor(3,0,0,0);
      choosePattern(i-2,8);
      choosePattern(i-3,4);
      choosePattern(i-4,1);
    }
    else if (i == 5){
      choosePattern(i-2,8);
      choosePattern(i-3,4);
      choosePattern(i-4,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 6){
      choosePattern(i-3,4);
      choosePattern(i-4,1);
      if(motion == 'Y')if(changeMode())return;
    }
    else if (i == 7){
      choosePattern(i-4,1);
      if(motion == 'Y')if(changeMode())return;
    }
    if(motion == 'Y')if(changeMode())return;
    delay(10);
  }
  if(motion == 'Y')if(changeMode())return;
}

//************************************ effect support ****************************************************

void selectiveClear(uint8_t finger){
  for (uint8_t i = 0; i < 4; i++){
    if(i != finger) setColor(i,0,0,0);
  }
}

void Clear(){
  for (uint8_t i = 0; i < 4; i++){
      setColor(i,0,0,0);
  }
}

void selectEffect(char effect){
  if (effect == '0'){
    choosePattern(4, 1);
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '1'){
    knightRiderMode1();
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '2'){
    knightRiderMode2();
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '3'){
    knightRiderMode3(effect3Delay);
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '4'){
    knightRiderMode4();
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '5'){
    rainbow(7);
    if(motion == 'Y')if(changeMode())return;
  }
  else if (effect == '6'){
    rainbowCycle(1);
    if(motion == 'Y')if(changeMode())return;
  }
  
}
