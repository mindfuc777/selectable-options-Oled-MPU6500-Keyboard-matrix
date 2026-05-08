#include "display.h"
#include "MPU6500.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setupDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
}
void displayData1(int* values) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Gyro"));

  display.print(F("x: "));
  display.println(values[0]);

  display.print(F("y: "));
  display.println(values[1]);

  display.print(F("z: "));
  display.println(values[2]);
  display.display();
}
void displayData2(int* values) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Temp: "));
  display.println(values[3]);
  display.display();
}