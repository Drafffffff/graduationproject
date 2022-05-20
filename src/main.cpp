#include "Arduino.h"
#include "untils.h"
int stepper_pos[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200);
}

void loop()
{
  if (Serial.available())
  {
    int inByte = Serial.read();
    Serial2.write(inByte);
  }
  if (Serial2.available())
  {
    int inByte = Serial2.read();
    Serial.write(inByte);
  }
  // for (int i = 0; i < 360; i += 10)
  // {
  //   angle2(0x02, i, 10, 1);
  //   delay(400);
  // }
  // delay(400);
  // Serial.print("read_pos(0x02):");
  // Serial.println(read_pos(0x02));
}
