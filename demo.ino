/*
    2023/04/27
    调用MSP库，用来测试飞控的新版固件，是否支持MSP命令输入
    需要：
      改库文件MSP.h中MSP2_COMMON_SET_CUSTOM_MSG的ID
*/
#include "src/lib_msp/MSP.h"

#define RXD1 27
#define TXD1 12
#define SERIAL_SPEED 115200

MSP msp;
char custommsg[30];
int lap, lap_time = 0;
void setup() {
  pinMode(RXD1, INPUT);
  Serial1.begin(SERIAL_SPEED, SERIAL_8N1, RXD1 , TXD1);
  msp.begin(Serial1);
}

void loop() {
  //strcpy(custommsg, "LAPTIMER");
  sprintf(custommsg, "Lap:%d %d", lap, lap_time);

  msp.command2(MSP2_COMMON_SET_CUSTOM_MSG, &custommsg, sizeof(custommsg), 0);
  lap = lap + 1;
  lap_time = lap_time + 10;
  delay(1000);
}
