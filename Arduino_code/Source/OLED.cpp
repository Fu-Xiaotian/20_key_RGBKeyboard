#include "RGBkeyboard.h"

//OLED显示标志
int OLED_flag = 0;
int old_OLED_flag = 0;
bool old_FN_flag = false;
uint8_t old_lock_flag = 0;

//OLED驱动类
SSD1306AsciiWire oled;

/**
 * OLED初始化函数
 */
void OLED_Init(void)
{
	Wire.begin();
	Wire.setClock(400000L);
	oled.begin(&Adafruit128x32, I2C_ADDRESS);
	oled.setFont(font5x7);
	oled.clear();
}

/**
 * OLED更新函数，当OLED_flag变量变化时更新显示
 */
void OLED_upload(void)
{
	//判断OLED_flag变动
	if(OLED_flag != old_OLED_flag)
	{
		old_OLED_flag = OLED_flag;
		OLED_Display();
	}
	//判断FN_flag变动
	if(FN_flag != old_FN_flag)
	{
		old_FN_flag = FN_flag;
		OLED_Display();
	}
	//判断主机状态改动
	uint8_t lock_flag = BootKeyboard.getLeds();
	if(lock_flag != old_lock_flag)
	{
		old_lock_flag = lock_flag;
		OLED_Display();
	}
}

/**
 * OLED显示函数，每行固定显示18个字符
 */
void OLED_Display(void)
{
	if(oled_sleep) //若键盘长时间闲置，则息屏
	{
		oled.clear();
	}
	else
	{
		oled.clear(); //清屏
		// 组织第一行键盘状态显示
		if(old_lock_flag & LED_CAPS_LOCK)
		{
			oled.print("CAPS:ON-");
		}
		else
		{
			oled.print("CAPS:OFF");
		}
		if(old_lock_flag & LED_NUM_LOCK)
		{
			oled.println("  NUM :ON-");
		}
		else
		{
			oled.println("  NUM :OFF");
		}
		// 组织第二行照明状态显示
		oled.print("LED :");
		oled.print(led_layer + 1);
		oled.print("--  BRI :");
		oled.print(led_brightness/16);
		oled.println("--");
		// 组织第三行按键层显示
		oled.print("KEY :");
		if(FN_flag)
		{
			oled.print(key_state + 1);
			oled.println("--  FnEnable");
		}
		else
		{
			oled.print(key_state + 1);
			if(key_state < 9)
				{oled.print("--  ");}
			else
				{oled.print("-  ");}
			switch(key_state) //根据键盘层不同，在第三行第二格位置显示一些默认信息
			{
				case 0 : 
					oled.print("MAC :");
					oled.println(get_macro_delay());
				break;
				default :
					oled.println("--------");
			}
		}
		// 组织第四行设置、宏状态显示
		if(led_set)
		{
			oled.println("---LED SETTING----");
		}
		else if(key_set)
		{
			oled.println("---KEY SETTING----");
		}
		else
		{
			switch(OLED_flag) //根据显示标志的不同，在第四行显示一些信息
			{
				case 1 :
					oled.println("---AUTO CTRL+E----");
				break;
				case 2 :
					oled.println("----AUTO FIRE-----");
				break;
				default :
					oled.println("------------------");
			}
		}
	}
}
