//************************************ Patterns *****************************************************

void chroma(uint8_t i, uint8_t dim){
  if(sequence == 2){
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][0] == 0 && g_[i][0] == 0 && b_[i][0] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][0]/dim,g_[i][0]/dim,b_[i][0]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][0]/dim,g_[i][0]/dim,b_[i][0]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][1] == 0 && g_[i][1] == 0 && b_[i][1] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][1]/dim,g_[i][1]/dim,b_[i][1]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][1]/dim,g_[i][1]/dim,b_[i][1]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][2] == 0 && g_[i][2] == 0 && b_[i][2] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][2]/dim,g_[i][2]/dim,b_[i][2]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][2]/dim,g_[i][2]/dim,b_[i][2]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][3] == 0 && g_[i][3] == 0 && b_[i][3] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][3]/dim,g_[i][3]/dim,b_[i][3]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][3]/dim,g_[i][3]/dim,b_[i][3]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][4] == 0 && g_[i][4] == 0 && b_[i][4] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][4]/dim,g_[i][4]/dim,b_[i][4]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][4]/dim,g_[i][4]/dim,b_[i][4]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][5] == 0 && g_[i][5] == 0 && b_[i][5] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r_[i][5]/dim,g_[i][5]/dim,b_[i][5]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r_[i][5]/dim,g_[i][5]/dim,b_[i][5]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
  }
  else if(sequence == 1 || sequence == 0){
    if(motion == 'Y')if(changeMode())return;
    if(r[i][0] == 0 && g[i][0] == 0 && b[i][0] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r[j][0]/dim,g[j][0]/dim,b[j][0]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r[i][0]/dim,g[i][0]/dim,b[i][0]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][1] == 0 && g[i][1] == 0 && b[i][1] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r[j][1]/dim,g[j][1]/dim,b[j][1]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][1]/dim,g[i][1]/dim,b[i][1]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][2] == 0 && g[i][2] == 0 && b[i][2] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r[j][2]/dim,g[j][2]/dim,b[j][2]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r[i][2]/dim,g[i][2]/dim,b[i][2]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][3] == 0 && g[i][3] == 0 && b[i][3] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r[j][3]/dim,g[j][3]/dim,b[j][3]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r[i][3]/dim,g[i][3]/dim,b[i][3]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][4] == 0 && g[i][4] == 0 && b[i][4] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r[j][4]/dim,g[j][4]/dim,b[j][4]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r[i][4]/dim,g[i][4]/dim,b[i][4]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][5] == 0 && g[i][5] == 0 && b[i][5] == 0){
    }
    else{
      if (i == 4){
         for (uint8_t j = 0; j < 4; j++){
             setColor(j,r[j][5]/dim,g[j][5]/dim,b[j][5]/dim);
             if(motion == 'Y')if(changeMode())return;
         }
      }
      else{
        setColor(i,r[i][5]/dim,g[i][5]/dim,b[i][5]/dim);
      }
      delay(10);
    }
    if(motion == 'Y')if(changeMode())return;
  }
}

/*
 * procedure that selects patterns (strobe, dops, hyperstrobe, strobie)
 * i = number of fingers controlled 1,2,3,4. 5 represents all fingers at the same time
 * dim = dimming factor 
 * delayG = delay after glow
 * delayO = delay after fade
 */
void patternFrequency(uint8_t i, uint8_t dim, int delayG, int delayO){  
  if(sequence == 1 || sequence == 0){
    if(motion == 'Y')if(changeMode())return;
    if(r[i][0] == 0 && g[i][0] == 0 && b[i][0] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][0]/dim,g[j][0]/dim,b[j][0]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][0]/dim,g[i][0]/dim,b[i][0]/dim);
      }
      delay(delayG);
      
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][1] == 0 && g[i][1] == 0 && b[i][1] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][1]/dim,g[j][1]/dim,b[j][1]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][1]/dim,g[i][1]/dim,b[i][1]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][2] == 0 && g[i][2] == 0 && b[i][2] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][2]/dim,g[j][2]/dim,b[j][2]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][2]/dim,g[i][2]/dim,b[i][2]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][3] == 0 && g[i][3] == 0 && b[i][3] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][3]/dim,g[j][3]/dim,b[j][3]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][3]/dim,g[i][3]/dim,b[i][3]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][4] == 0 && g[i][4] == 0 && b[i][4] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][4]/dim,g[j][4]/dim,b[j][4]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][4]/dim,g[i][4]/dim,b[i][4]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r[i][5] == 0 && g[i][5] == 0 && b[i][5] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
           setColor(j,r[j][5]/dim,g[j][5]/dim,b[j][5]/dim);
           if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r[i][5]/dim,g[i][5]/dim,b[i][5]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
  }
  else if(sequence == 2){
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][0] == 0 && g_[i][0] == 0 && b_[i][0] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][0]/dim,g_[j][0]/dim,b_[j][0]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][0]/dim,g_[i][0]/dim,b_[i][0]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][1] == 0 && g_[i][1] == 0 && b_[i][1] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][1]/dim,g_[j][1]/dim,b_[j][1]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][1]/dim,g_[i][1]/dim,b_[i][1]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][2] == 0 && g_[i][2] == 0 && b_[i][2] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][2]/dim,g_[j][2]/dim,b_[j][2]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][2]/dim,g_[i][2]/dim,b_[i][2]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][3] == 0 && g_[i][3] == 0 && b_[i][3] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][3]/dim,g_[j][3]/dim,b_[j][3]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][3]/dim,g_[i][3]/dim,b_[i][3]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][4] == 0 && g_[i][4] == 0 && b_[i][4] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][4]/dim,g_[j][4]/dim,b_[j][4]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][4]/dim,g_[i][4]/dim,b_[i][4]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
    if(r_[i][5] == 0 && g_[i][5] == 0 && b_[i][5] == 0){
    }
    else{
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,r_[j][5]/dim,g_[j][5]/dim,b_[j][5]/dim);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,r_[i][5]/dim,g_[i][5]/dim,b_[i][5]/dim);
      }
      delay(delayG);
      if (i == 4){
        for (uint8_t j = 0; j < 4; j++){
          setColor(j,0,0,0);
          if(motion == 'Y')if(changeMode())return;
        }
      }
      else{
        setColor(i,0,0,0);
      }
      delay(delayO);
    }
    if(motion == 'Y')if(changeMode())return;
  }
}

//************************************ pattern support ****************************************************

void choosePattern(uint8_t i, uint8_t d){
  if (sequence == 0 || sequence == 1){
    if (pattern1[i] == '1'){
      effect3Delay = 10;
      patternFrequency(i, d, 5, 5); //strobe
    }
    else if (pattern1[i] == '2'){
      effect3Delay = 10;
      patternFrequency(i, d, 10, 10); //hyperstrobe
    }
    else if (pattern1[i] == '3'){
      effect3Delay = 40;
      patternFrequency(i, d, 1, 2); //dops
    }
    else if (pattern1[i] == '4'){
      effect3Delay = 40;
      patternFrequency(i, d, 1, 4); //strobie
    }
    else if (pattern1[i] == '5'){
      effect3Delay = 10;
      chroma(i,d);
    }
  }
  else if (sequence == 2){
    if (pattern2[i] == '1'){
      effect3Delay = 10;
      patternFrequency(i, d, 5, 5); //strobe
    }
    else if (pattern2[i] == '2'){
      effect3Delay = 10;
      patternFrequency(i, d, 10, 10); //hyperstrobe
    }
    else if (pattern2[i] == '3'){
      effect3Delay = 40;
      patternFrequency(i, d, 1, 2); //dops
    }
    else if (pattern2[i] == '4'){
      effect3Delay = 40;
      patternFrequency(i, d, 1, 4); //strobie
    }
    else if (pattern2[i] == '5'){
      effect3Delay = 10;
      chroma(i,d);
    }
  }
}

void setColor(uint8_t i, uint8_t r, uint8_t g, uint8_t b){
  if (i == 0)strip.setPixelColor(0, strip.Color(r,g,b));
  if (i == 1)strip1.setPixelColor(0, strip1.Color(r,g,b));
  if (i == 2)strip2.setPixelColor(0, strip2.Color(r,g,b));
  if (i == 3)strip3.setPixelColor(0, strip3.Color(r,g,b));
  
  if (i == 0)strip.show();
  if (i == 1)strip1.show();
  if (i == 2)strip2.show();
  if (i == 3)strip3.show();
}



// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
