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
 * OLED显示函数
 */
void OLED_Display(void)
{
	if(oled_sleep)
	{
		oled.clear();
	}
	else
	{
		oled.clear();
		if(old_lock_flag & LED_CAPS_LOCK)
		{
			oled.print("CAPS:ON ");
		}
		else
		{
			oled.print("CAPS:OFF");
		}
		if(old_lock_flag & LED_NUM_LOCK)
		{
			oled.println(" NUM :ON ");
		}
		else
		{
			oled.println(" NUM :OFF");
		}
		oled.print("LED :");
		oled.print(led_layer + 1);
		oled.print("   BRI :");
		oled.println(led_brightness/16);
		oled.print("KEY :");
		if(FN_flag)
		{
			oled.print(key_state + 1);
			oled.println("   FN Enable");
		}
		else
		{
			oled.println(key_state + 1);
		}
		if(led_set)
		{
			oled.println("LED SETING");
		}
		else
		{
			switch(OLED_flag)
			{
				case 1 :
					oled.println("AUTO HUAKAN");
				break;
			}
		}
	}
}
