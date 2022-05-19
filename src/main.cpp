#include "Arduino.h"
#include "untils.h"
#include "SoftwareSerial.h"
#include "stepperPin.h"
SoftwareSerial step1;
SoftwareSerial step2;
SoftwareSerial step3;
SoftwareSerial step4;
SoftwareSerial step5;
SoftwareSerial step6;
SoftwareSerial step7;
SoftwareSerial step8;
SoftwareSerial step9;
SoftwareSerial step10;
void setup()
{
  Serial.begin(57600);
  step1.begin(115200, SWSERIAL_8N1, STEPPER1_R, STEPPER1_T, false);
  step2.begin(115200, SWSERIAL_8N1, STEPPER2_R, STEPPER2_T, false);
  step3.begin(115200, SWSERIAL_8N1, STEPPER3_R, STEPPER3_T, false);
  step4.begin(115200, SWSERIAL_8N1, STEPPER4_R, STEPPER4_T, false);
  step5.begin(115200, SWSERIAL_8N1, STEPPER5_R, STEPPER5_T, false);
  step6.begin(115200, SWSERIAL_8N1, STEPPER6_R, STEPPER6_T, false);
  step7.begin(115200, SWSERIAL_8N1, STEPPER7_R, STEPPER7_T, false);
  step8.begin(115200, SWSERIAL_8N1, STEPPER8_R, STEPPER8_T, false);
  step9.begin(115200, SWSERIAL_8N1, STEPPER9_R, STEPPER9_T, false);
  step10.begin(115200, SWSERIAL_8N1, STEPPER10_R, STEPPER10_T, false);
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
