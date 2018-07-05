#ifndef __RGBKEYBOARD_H
#define __RGBKEYBOARD_H

#ifndef USBCON
#define USBCON
#endif

/*
包含库
 */
#include "HID-Project.h"
#include <Key.h>
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include <SchedulerARMAVR.h>

/*
包含个人函数
 */
#include "KeyScan.h"
#include "Pressed.h"
#include "Released.h"
#include "LED.h"
#include "OLED.h"
#include "macro.h"
#include "keydefine.h"
#include "Setting.h"

/*
声明函数
 */
void LED(void);
void MODE(void);
void button(void);
void loop2(void);

//用户不可更改的宏定义
#define MODE_KEY 9 //模式切换按键PIN
#define MAX_KEY_LAYER 3 //定义现有按键层数
#define LED_LAYER_ADD 0 //定义LED层状态储存地址
#define LED_BRIGHTNESS_ADD 2 //定义LED亮度存储地址
#define KEY_LAYER_ADD 4 //定义按键层设置储存地址
#define I2C_ADDRESS 0x3C //OLED通信地址

/*
变量声明
 */
extern Adafruit_NeoPixel strip;
//键盘层状态变量
extern int key_state;
//灯光控制层状态变量
extern bool def_set;
//灯光层状态变量
extern int led_layer;
//最后一次按键事件系统时间记录变量，用于计算键盘空闲时间
extern unsigned long last_press_systime;
//灯光显示休眠标志
extern bool oled_sleep;

#endif