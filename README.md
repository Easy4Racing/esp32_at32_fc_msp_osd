# esp32_at32_fc_msp_osd

## 更新记录
2023/5/8 修改：MSP2_SET_CUSTOM_OSD_INFO = 0x3008 <br>
2023/5/21 修改：增加osd_symbols.h; 便于使用BF的OSD图标来美化字符串

## 功能
调用MSP库，用来向AT32飞控发送MSP命令，以实现自定义显示OSD内容
![image](https://github.com/Easy4Racing/esp32_at32_fc_msp_osd/blob/main/images/IMG_20230521_112807.jpg)

## 说明
1. 需要更新AT固件，新固件即将支持新的MSP命令，该命令可显示自定义OSD信息。<br>
2. 可以调用BF的OSD图标进行格式化字符串，例：sprintf(custommsg, " %c%d%c%d", SYM_TOTAL_DISTANCE, cnt, SYM_SPEED, cnt_time)，但存在待解决的BUG, 即待显示的字符串前必须有个空格，否则首字母会被遗漏

## 开发环境
Arduino IDE
