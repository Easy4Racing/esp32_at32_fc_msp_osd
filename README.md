# esp32_at32_fc_msp_osd
#### 功能
调用MSP库，用来向AT32飞控发送MSP命令，以实现自定义显示OSD内容
#### 说明
1. 需要等AT32的固件更新，新固件即将支持新的MSP命令，该命令可显示自定义OSD信息。<br>
2. 待AT32固件新增该功能后，修改改库文件MSP.h中MSP2_COMMON_SET_CUSTOM_MSG的ID，该ID由AT32的固件确定
#### 开发环境
Arduino IDE
