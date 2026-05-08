#include <MPU6500.h>
#include <MPU6500_WE.h>
#include <Wire.h>
const int csPin = 10;  // Chip Select Pin
// const int mosiPin = 22;  // "MOSI" Pin
// const int misoPin = 21;  // "MISO" Pin
// const int sckPin = 16;  // SCK Pin
bool useSPI = false;
MPU6500_WE myMPU6500 = MPU6500_WE(&SPI, csPin, useSPI);
void setupMPU6500() {
  if(!myMPU6500.init()){
    Serial.println("MPU6500 does not respond");
  }

  Serial.println("Position you MPU6500 flat and don't move it - calibrating...");
  delay(1000);
  myMPU6500.autoOffsets();
  Serial.println("Done!");
}
int angleX = 0, angleY = 0, angleZ = 0;
int lastangleX = 0, lastangleY = 0, lastangleZ = 0;
void updateAngles() {
  xyzFloat gyr = myMPU6500.getAngles();
  angleX = (gyr.x + lastangleX)/2;
  angleY = (gyr.y + lastangleY)/2;
  angleZ = (gyr.z + lastangleZ)/2;
  lastangleX = gyr.x;
  lastangleY = gyr.y;
  lastangleZ = gyr.z;
}
void GetValues(int* values) {
    int temp = myMPU6500.getTemperature();
    values[0] = angleX;
    values[1] = angleY;
    values[2] = angleZ;
    values[3] = temp;
}