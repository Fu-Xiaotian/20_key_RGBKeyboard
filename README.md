# RGB Keyboard V2.3版本

## Profile：
使用Pro micro（ATMEGA32U4）作为主控制作的20键全宏定义键盘，具有RGB功能，单引脚控制WS2811/WS2812 RGB灯带，可以定义矩阵键盘及RGB控制IO。

具有三个不同定义的按键层，四个平行线程来分别处理按键、宏、RGB灯效以及保留功能按键。每层均可定义普通按键以及宏按键。

可以使用IIC总线与SSD1306控制的OLED显示屏通信，实现键盘状态显示。

## Library：
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

## Version History:

### V2.3
1.	优化了led设置的代码来试图提高运行速度
2.	修正了FN键按住时进入LED设置导致FN一直使能的问题
3.	层2的17号按键可以定义为其他按键了，也可以继续作为FN使用
4.	取消了HOLD文件，HOLD命名，解决了历史遗留问题

### V2.2
1.	优化了一部分代码体积
2.	添加了五分钟无动作自动关闭LED节能以及OLED保护功能

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

## Layer1 & layer2层普通按键定义方式

若要定义layer1和layer2层的按键，只需打开*keydefine.cpp*，对照*键值表.txt*文件更改数组即可。

**注意：17号位置定义的普通按键无效，因其已经被FN多功能键强制占用**

**注意：自V2.3以后，层2可以识别17号位置定义是否为FN键，故层2可以定义为其他按键**

# 变量与硬件编号定义
### 按键号定义：
按键号1~20，自左到右，自上到下，Z字型排列。

### 层变量定义：
*key_state*值为0~2，使用mode按键自加，由*RGBkeyboard.h*文件中MAX_KEY_LAYER宏定义限定最大值为2。

### 宏使能标志定义：
*macro_flag*变量定义了宏使能标志，此值用于在键盘扫描线程和宏专用线程中传递某个按键是否应当启用宏。取值0到20，值0禁用宏，1~20使能对应按键的宏。因此**同时只能激活一个宏！！**

*FN_flag*变量定义了FN键使能标志，用于在FN键按下时改变键盘行为。

### LED号定义：
LED号0~19，与按键号同样排序。

### LED相关变量：
*led_state*取值为true或false，指示键盘模式（false）或者灯效设置模式（true）。

*led_layer*取值为int，目前定义为0，1，2，3，分别代表四种灯效。

# 宏定义
若需要定义按键宏，则需要编辑*marco.cpp*文件，当按键层一二中FN按键被按下时，其余对应按键按下或者按键层三对应按键按下后，程序会开始执行对用的*Key_n_MARCO*函数。由此可见，程序逻辑中三个按键层使用了同一个函数来执行宏功能，因此在配置宏的时候**必须使用if(key_state == 层数-1)逻辑来限制宏在那一层执行**

本程序在头文件中定义了RUN_ONCE语句以便于定义宏时直接设定宏的单次运行，为保证程序安全**所有只执行一次的按键宏都应在宏最后或宏开始使用本语句**

程序逻辑在设计时，按键事件仅作为进入宏函数的引导，尽管宏运行中可以继续识别宏按键，宏函数也必须执行一遍以后才可以重新检测宏引导标志进入新的宏函数。因此若不在每次宏结束后清空宏函数，可能会导致任务堆积和极高的键盘延时。FN键采用了与宏引导类似的设计，当FN键把按键引导进去宏后，FN键便不起效了。

同时因为上述程序设计，程序需要特别的结构来实现普通按键的按下与抬起功能，下面的例子介绍了实现方法。这个结构也带来一定的优点，使得宏具备了自动重复功能，而不必反复按下按键来激活宏。

### 例子：
``` cpp
void Key_20_MARCO(void)
{
	if(key_state == 0) //第一层，ESC键按下抬起组合
	{
		NKROKeyboard.press(KEY_ESC);
		while(macro_flag == 20)
			{Scheduler.delay(50);}
		NKROKeyboard.release(KEY_ESC);
	}
	if(key_state == 1) //第二层，当按键按下时重复发送‘e’，此时无需按住FN键
	{
		while(macro_flag == 20)
		{
			NKROKeyboard.press(KEY_E);
			NKROKeyboard.release(KEY_E);
		}
	}
	if(key_state == 2) //第三层，按下按键保存文件，单次运行
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_S);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}
```
