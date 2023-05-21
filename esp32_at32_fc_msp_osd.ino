/*
    2023/04/27
    调用MSP库，用来测试飞控的新版固件，是否支持MSP命令输入
    需要：
      改库文件MSP.h中MSP2_COMMON_SET_CUSTOM_MSG的ID
*/
#include "src/lib_msp/MSP.h"
#include "src/osd_symbols.h"

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
  sprintf(custommsg, " %c%d%c%d", SYM_TOTAL_DISTANCE, cnt, SYM_SPEED, cnt_time); //待解决的BUG, 前缀必须有个空格，否则首字母漏掉

  msp.command2(MSP2_SET_CUSTOM_OSD_INFO, &custommsg, sizeof(custommsg), 0);
  cnt = cnt + 1;
  cnt_time = cnt_time + 5;
  delay(1000);
}
