#include "RGBkeyboard.h"

//最后一次按键事件系统时间记录变量，用于计算键盘空闲时间
unsigned long last_press_systime = 0;
//独立按键识别变量
int old_key_flag = 0;
int key_flag = 0;
//键盘层状态变量
int key_state = 0;
//默认值设置状态变量
bool def_set = false;
//灯光层状态变量
int led_layer = 0;
//灯光显示休眠标志
bool oled_sleep = false;

/**
 * @brief      初始化
 *
 * @return     无
 */
void setup()
{
	Serial.begin(9600);
	Serial.println("begin");
	pinMode(MODE_KEY,INPUT);
	LED_Init();	//初始化RGB
	OLED_Init(); //初始化OLED
	kpd.setDebounceTime(DEBOUNCETIME); //设置键盘消抖延时
	NKROKeyboard.begin(); //初始化键盘
	Consumer.begin(); //初始化多媒体控制器
	BootKeyboard.begin(); //初始化主机状态控制器
	strip.setBrightness(BRIGHTNESS);

	last_press_systime = millis(); //初始化系统时间

	EEPROM.get(LED_LAYER_ADD, led_layer); //读取用户设置
	EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);
	EEPROM.get(KEY_LAYER_ADD, key_state);

	Scheduler.startLoop(loop2); //多线程使能
	Scheduler.startLoop(LED);
	Scheduler.startLoop(MODE);


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
	button(); //处理模式按键事件
	brightness_upload(); //更新led亮度
	OLED_upload(); //当进出宏时更新OLED显示
	
	yield();
}

/**
 * 线程2，用于处理宏
 */
void loop2()
{
	Macro_Switch();
	yield();
}

/**
 * 独立按键事件处理函数
 */
void button(void)
{
	if(key_flag <20 &&key_flag >1)
	{
		if(!def_set)
		{
			//控制变量全清
			OLED_flag = 0;
			macro_flag = 0;
			FN_flag = false;
			key_flag = 0;
			key_state ++;
			if(key_state >= MAX_KEY_LAYER)
			{
				key_state = 0;
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
	else if(key_flag >= 20)
	{
		//控制变量全清
		OLED_flag = 0;
		macro_flag = 0;
		key_flag = 0;
		FN_flag = false;
		if(def_set)
		{
			def_set = false;
			EEPROM.put(LED_LAYER_ADD, led_layer); //保存用户设置
			EEPROM.put(LED_BRIGHTNESS_ADD, led_brightness);
			EEPROM.put(KEY_LAYER_ADD, key_state);
		}
		else
		{
			def_set = true;
			EEPROM.get(LED_LAYER_ADD, led_layer); //读取用户设置
			EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);
			EEPROM.get(KEY_LAYER_ADD, key_state);
		}
		OLED_Display();
		//释放所有按键
		NKROKeyboard.releaseAll();
		Consumer.releaseAll();
		/*
		记录最后一次按键事件发生的时间
		 */
		last_press_systime = millis();
	}
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

/**
 * 模式按键扫描线程
 */
void MODE(void)
{
	//独立按键识别函数
	
	int flag = digitalRead(MODE_KEY);
	if (flag == 0)
	  	{old_key_flag ++;}
	else
		{
			if(old_key_flag != 0)
				{key_flag = old_key_flag;}
			old_key_flag = 0;
		}
	Scheduler.delay(20);
	yield();
}
