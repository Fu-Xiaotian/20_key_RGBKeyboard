# RGB Keyboard V2.1版本
## 使用的库：
1.	HID-Project库：键盘USB功能主要支撑以及扩展
https://github.com/NicoHood/HID
2.	Keypad库：为矩阵键盘识别提供一些支持
https://github.com/Chris--A/Keypad
3.	Adafruit_NeoPixel库：驱动WS2811芯片驱动RGB LED，并提供一部分灯效
https://github.com/adafruit/Adafruit_NeoPixel
4.	EEPROM库：官方库，为用户设置存储提供支持
5.	Wire库：IIC通信库，未直接使用，仅为OLED显示库提供支持
6.	SSD1306Ascii & SSD1306AsciiWire库：OLED显示驱动库，可显示字符串
https://github.com/greiman/SSD1306Ascii
7.	SchedulerARMAVR库：Scoop库中为AVR单片机设计的多线程任务调度器库
https://github.com/fabriceo/SCoop
## 特性:
### V2.1
1.	修正了抬起其他按键使得当前按键宏失效的问题
### V2.0
1.	修改按键宏使能方案，17号按键在layer1&2层用作FN多功能组合键
2.	Layer1层按住FN键将使得下一次按下被引导进宏，宏也可以发送一个普通按键或者字符串
3.	Layer2层宏定义不再需要将按键定义为KEY_RESERVED，只需短按FN键即可起用
4.	为FN按键状态添加OLED显示
### V1.3
1.	添加了显示函数，可以通过简单修改一个变量值来控制最后一行显示的内容
2.	添加了新的显示更新方式，当显示控制变量改变时刷新屏幕
### V1.2
1.	修正LED灯效切换时延时的BUG
2.	添加LED亮度多级调节
3.	更换了灯效一和二
4.	优化了用户灯光设置存储
5.	小幅优化代码效率
### V 1.1
1.  删除了无效的代码，精简逻辑减少资源消耗
### V 1.0：
1.	使用Scoop库设计四个合作多线程
2.	可以定义死循环宏而不影响其他任务
3.	Layer1和layer2层按键使用数组设置方便快捷
4.	LED专用设置层，定义4种亮度，4种灯效，还有12个按键空余
5.	OLED目前可简单显示键盘状态
6.	Layer3专用宏定义层，可定义死循环宏
7.	layer2层可定义按住循环宏或单次宏
8.	layer1层仅可定义按键，为开机默认层
9.	用户可以设置LED灯效，并且该灯效掉电可保存，具有至少100，000次更改寿命
