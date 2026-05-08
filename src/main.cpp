#include <Arduino.h>
#include "MPU6500.h"
#include "display.h"
#include "buttonMatrix.h"
#include <Wire.h>
// put function declarations here:
void setup() {
  Serial.begin(9600);
  Wire.begin();
  setupMPU6500();
  setupDisplay();
}
int values[4];
unsigned long lastKeyboard = 0;
unsigned long lastDisplay = 0;
char key = -1;
char lastKey = '0';
void loop() {
  updateAngles();
  if (millis() - lastKeyboard >= 2) {
    lastKeyboard = millis();
    key = getkey();
    if(key != lastKey && key == '0' || key != lastKey && key == '1'){
      lastKey = key;
    }
    
  }
  // display кожні 200 мс
  if (millis() - lastDisplay >= 200) {
    GetValues(values);
    if(lastKey == '0'){
      displayData1(values);
    }
    else if(lastKey == '1'){
      displayData2(values);
    }
    lastDisplay = millis();
  }
}