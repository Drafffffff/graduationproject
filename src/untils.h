#define CW 0
#define CCW 1
#define END 0x6B
void cleanSerial()
{
  while (Serial2.available() > 0)
  {
    Serial2.read();
  }
}
int read_pos(char id)
{
  int32_t signed value;
  char cmd[3] = {id,
                 0x36,
                 END};
  cleanSerial();
  Serial2.write(cmd, 3);
  char msg[6];
  int count = 0;
  Serial2.readBytesUntil(END, msg, 6);
  cleanSerial();
  //判断正负
  if ((msg[1] >> 4) > 8)
  {
    for (int i = 0; i < 4; i++)
    {
      value = (value << 8) | msg[i + 1];
    }
    value = value - 1;
    value = value;
    // Serial.print("n")
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      value = (value << 8) | msg[i + 1];
    }
  }
  float a = value / 182.44444;
  return int(a);
}

// void readSerial()
// {
//   char msg[20];
//   int count = 0;
//   while (Serial2.available() > 0)
//   {
//     char single = Serial2.read();
//     msg[count] = single;
//     count++;
//     if (single == END)
//     {
//       break;
//     }
//   }
//   if (count == 3)
//   {
//     return;
//   }
//   else if (count == 6)
//   {
//     Serial.print("sdfs");
//   }
// }
void move(int id = 0x01, int angle = 0, int speed = 10, char acc = 1)
{
  int dir;
  if (angle >= 0)
  {
    dir = CCW;
  }
  else
  {
    dir = CW;
  }
  int speedDir = (dir * 0x1000) | speed;
  char s1 = speedDir >> 8;
  char s2 = (speedDir & 0xFF);
  int step = int(abs(angle) * 8.888889);
  char step1 = (step & 0xFF0000) >> 16;
  char step2 = (step & 0x00FF00) >> 8;
  char step3 = step & 0x0000FF;
  char cmd[9] = {char(id), 0xFD, s1, s2, acc, step1, step2, step3, END};
  Serial2.write(cmd, 9);
  cleanSerial();
}

void angle2(char id, int angle, int speed = 10, char acc = 1)
{
  int cPos = read_pos(id);
  Serial.print("cPos:");
  Serial.println(cPos);
  int dPos = angle - cPos;
  Serial.print("dPos:");
  Serial.println(dPos);
  move(id, dPos, speed, acc);
}