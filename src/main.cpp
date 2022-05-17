#include "Arduino.h"
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
}
void move(int id);
void loop() {
  if (Serial2.available()) {
    int inByte = Serial2.read();
    Serial.write(inByte);
  }

 if (Serial.available()) {
   int inByte = Serial.read();
   Serial2.write(inByte);
 }

  move(0x01);
}

void move(int id) {
  //id
  Serial2.write(id);
  // commd
  Serial2.write(0xFD);
  //dir
  Serial2.write(0x00);
  //speed
  Serial2.write(0xAA);
  //acc
  Serial2.write(0x03);
  //value
  // char pos[3] = [0x00,0x01,0x64];
  // Serial2.write(pos,3);
}