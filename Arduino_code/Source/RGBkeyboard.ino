#include "RGBkeyboard.h"

//非阻塞延时记录变量
unsigned long systime = 0;
//独立按键识别变量
int old_key_flag = 0;
int key_flag = 0;
//键盘层状态变量
int key_state = 0;
//灯光控制层状态变量
int led_state = 0;
//灯光层状态变量
int led_layer = 0;

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
	Keyboard.begin(); //初始化键盘
	strip.setBrightness(BRIGHTNESS);

	systime = millis();

	EEPROM.get(LED_LAYER_ADD, led_layer); //读取用户设置
	EEPROM.get(LED_BRIGHTNESS_ADD, led_brightness);

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
 * 独立按键扫描用非阻塞延时
 */
bool __delay_ms(unsigned long t)
{
	unsigned long time = millis();
	if(time - systime > t)
		{
			systime = time;
			return true;
		}
	else
		{return false;}
}

/**
 * 独立按键事件处理函数
 */
void button(void)
{
	if(key_flag <25 &&key_flag >1)
	{
		macro_flag = 0;
		FN_flag = false;
		key_flag = 0;
		key_state ++;
		if(key_state >= MAX_KEY_LAYER)
		{
			key_state = 0;
		}
		OLED_Display();
		Keyboard.releaseAll();
	}
	else if(key_flag >= 25)
	{
		macro_flag = 0;
		key_flag = 0;
		led_state ++;
		if(led_state > 1)
		{
			led_state = 0;
			EEPROM.put(LED_LAYER_ADD, led_layer); //保存用户设置
			EEPROM.put(LED_BRIGHTNESS_ADD, led_brightness);
		}
		OLED_Display();
		Keyboard.releaseAll();
	}
}

/**
 * LED控制线程，用以控制灯效
 */
void LED(void)
{
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
	if(__delay_ms(20))
	{
		int flag = digitalRead(MODE_KEY);
		if (flag == 0)
	  		{old_key_flag ++;}
	  	else
	  		{
	  			if(old_key_flag != 0)
	  				{key_flag = old_key_flag;}
	  			old_key_flag = 0;
	  		}
	}
	yield();
}
