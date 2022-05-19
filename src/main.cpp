#include "Arduino.h"
#include "untils.h"
#include"SoftwareSerial.h"
void setup()
{
  Serial.begin(57600);
  Serial2.begin(38400);
}

void loop()
{
  // if (Serial2.available())
  // {
  //   int inByte = Serial2.read();
  //   Serial.write(inByte);
  // }
  //   if (Serial.available())
  // {
  //   int inByte = Serial.read();
  //   Serial2.write(inByte);
  // }


  for (int i = 0; i < 360; i += 10)
  {

    angle2(0x02, i, 100, 0);
    delay(100);  
  }
    for (int i = 360; i > 0; i -= 10)
  {

    angle2(0x02, i, 100, 0);
    delay(100);  
  }
  //     Serial.print("read_pos(0x02):");
  //   Serial.println(read_pos(0x02));

  // delay(400);
  
}
