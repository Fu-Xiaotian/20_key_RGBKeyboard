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
#include "HOLD.h"
#include "LED.h"
#include "OLED.h"
#include "macro.h"
#include "keydefine.h"

/*
声明函数
 */
void LED(void);
void MODE(void);
void button(void);
void loop2(void);

//define
#define HOLD_DELAY 1000 //定义按住重复的间隔，全键盘共用
#define MODE_KEY 9 //模式切换按键PIN
#define MAX_KEY_LAYER 3 //定义现有按键层数
#define LED_LAYER_ADD 0 //定义LED层状态储存地址
#define LED_BRIGHTNESS_ADD 2 //定义LED亮度存储地址
#define BRIGHTNESS 32 //默认灯光亮度
#define I2C_ADDRESS 0x3C //OLED通信地址

/*
变量声明
 */
extern Adafruit_NeoPixel strip;
//键盘层状态变量
extern int key_state;
//灯光控制层状态变量
extern bool led_set;
//灯光层状态变量
extern int led_layer;
//最后一次按键事件系统时间记录变量，用于计算键盘空闲时间
extern unsigned long last_press_systime;
//灯光显示休眠标志
extern bool oled_sleep;

#endif