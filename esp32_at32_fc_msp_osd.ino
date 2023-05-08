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
int cnt, cnt_time = 0;
void setup() {
  pinMode(RXD1, INPUT);
  Serial1.begin(SERIAL_SPEED, SERIAL_8N1, RXD1 , TXD1);
  msp.begin(Serial1);
}

void loop() {
  sprintf(custommsg, "Demo:%d %d", cnt, cnt_time);

  msp.command2(MSP2_SET_CUSTOM_OSD_INFO, &custommsg, sizeof(custommsg), 0);
  cnt = cnt + 1;
  cnt_time = cnt_time + 100;
  delay(1000);
}
