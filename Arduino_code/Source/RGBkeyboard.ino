#include "RGBkeyboard.h"

//最后一次按键事件系统时间记录变量，用于计算键盘空闲时间
unsigned long last_press_systime = 0;
//按键设置层状态变量
bool key_set = false;
//键盘层状态变量
int key_state = 0;
//默认值设置状态变量
bool led_set = false;
//灯光层状态变量
int led_layer = 0;
//灯光显示休眠标志
bool oled_sleep = false;
//定义mode按键
OneButton mode(MODE_KEY, true);

/**
 * @brief      初始化
 *
 * @return     无
 */
void setup()
{
	pinMode(MODE_KEY,INPUT);
	LED_Init();	//初始化RGB
	OLED_Init(); //初始化OLED
	connect_init(); //初始化串口上位机链接
	kpd.setDebounceTime(DEBOUNCETIME); //设置键盘消抖延时
	NKROKeyboard.begin(); //初始化键盘
	Consumer.begin(); //初始化多媒体控制器
	BootKeyboard.begin(); //初始化主机状态控制器
	Mouse.begin(); //初始化鼠标控制器，用于模拟鼠标点击功能
	strip.setBrightness(BRIGHTNESS);

	last_press_systime = millis(); //初始化系统时间

	EEPROM.get(LED_LAYER_ADD, led_layer); //读取用户设置
	EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);

	Scheduler.startLoop(loop2); //多线程使能
	Scheduler.startLoop(LED);

	mode.attachClick(short_button); //mode按键识别
	mode.attachPress(long_button);

	//OLED显示信息
	OLED_Display();
}

/**
 * @brief      主线程，扫描键盘，处理MODE按键事件
 *
 * @return     无
 */
void loop()
{
	key_scan(); //扫描按键按下与释放
	brightness_upload(); //更新led亮度
	OLED_upload(); //当进出宏时更新OLED显示

	mode.tick(); //监视独立按键
	yield();
}

/**
 * 线程2，用于处理宏以及响应上位机串口信息
 */
void loop2()
{
	Macro_Switch(); //宏响应函数

	connect_event(); //串口数据响应函数
	yield();
}

/**
 * 独立按键短按事件处理函数
 */
void short_button(void)
{
	if(!led_set)
	{
		//控制变量全清
		OLED_flag = 0;
		macro_flag = 0;
		FN_flag = false;
		//出入按键设置层
		key_set = true;
		//刷新设置
		OLED_Display();
		//释放所有按键
		NKROKeyboard.releaseAll();
		Consumer.releaseAll();
	}
	/*
	记录最后一次按键事件发生的时间
	 */
	last_press_systime = millis();
}

/**
 * 独立按键长按事件处理函数
 */
void long_button(void)
{
	if(!key_set)
	{
		//控制变量全清
		OLED_flag = 0;
		macro_flag = 0;
		FN_flag = false;
		if(led_set)
		{
			led_set = false;
			EEPROM.put(LED_LAYER_ADD, led_layer); //保存用户设置
			EEPROM.put(LED_BRIGHTNESS_ADD, led_brightness);
		}
		else
		{
			led_set = true;
			EEPROM.get(LED_LAYER_ADD, led_layer); //读取用户设置
			EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);
		}
		OLED_Display();
		//释放所有按键
		NKROKeyboard.releaseAll();
		Consumer.releaseAll();
	}
	/*
	记录最后一次按键事件发生的时间
	 */
	last_press_systime = millis();
}

/**
 * LED控制线程，用以控制灯效
 */
void LED(void)
{
	//若5min没有动作，则熄灭灯光进入节能模式
	if(millis() - last_press_systime >= SLEEP_TIME)
		{
			oled_sleep = true;
			led_brightness = 0;
			brightness_upload();
			All_bright(255, 255, 255);
			OLED_Display();
			while(1)
			{
				if(millis() - last_press_systime < SLEEP_TIME)
				{
					oled_sleep = false;
					OLED_Display();
					EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);
					brightness_upload();
					break;
				}
				Scheduler.delay(30);
			}
		}
	//灯效
	if(led_layer == 0)
		{All_bright(255, 255, 255);}
	if(led_layer == 1)
		{rainbowPoint(40);}
	if(led_layer == 2)
		{rainbow(40); }
	if(led_layer == 3)
		{rainbowCycle(40); }
	yield();
}
