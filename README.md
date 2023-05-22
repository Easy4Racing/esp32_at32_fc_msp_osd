# esp32_at32_fc_msp_osd

## 更新记录
2023/5/8 修改：MSP2_SET_CUSTOM_OSD_INFO = 0x3008 <br>
2023/5/8 Modified：MSP2_SET_CUSTOM_OSD_INFO = 0x3008 <br>

2023/5/21 修改：增加osd_symbols.h; 便于使用BF的OSD图标来美化字符串 <br>
2023/5/21 Added：osd_symbols.h file for using BF OSD symbol to format the string.

## 功能
调用MSP库，用来向AT32飞控发送MSP命令，以实现自定义显示OSD内容 <br>
Call MSP library to send MSP command to AT32 flight control to realize customized display of OSD content.
![image](https://github.com/Easy4Racing/esp32_at32_fc_msp_osd/blob/main/images/IMG_20230521_112807.jpg)

## 说明
1. 需要更新AT32飞控的固件，新固件支持新的MSP命令(该功能可能仍然处于测试状态)，该命令可显示自定义OSD信息。<br>
The AT32FC firmware needs to be updated, and the new firmware support the new MSP command (The function may still be in the test state), which can display custom OSD information. <br>
2. 可以调用BF的OSD图标进行格式化字符串，例：sprintf(custommsg, " %c%d%c%d", SYM_TOTAL_DISTANCE, cnt, SYM_SPEED, cnt_time)，但存在待解决的BUG, 即待显示的字符串前必须有个空格，否则首字母会被遗漏. <br>
Call osd_symbols.h using BF OSD symbol to format the string, eg: sprintf(custommsg, " %c%d%c%d", SYM_TOTAL_DISTANCE, cnt, SYM_SPEED, cnt_time). However, there is a BUG to be solved, that is there must be a space before the string to be displayed, otherwise the first letter will be omitted.

## 开发环境
Arduino IDE
