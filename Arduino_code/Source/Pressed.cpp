#include "RGBkeyboard.h"

bool FN_flag = false;

/**
 * 按键按下事件响应函数
 * 输入：
 * 		按键编号（按键编号从0开始，其对应的控制数组均从0开始，对应宏变量也从0开始）
 * **/
void Key_N_Preased(int KeyNum)
{
	if(led_layer == 1) //led照明控制
		{led_enable[KeyNum] = true;} //led控制数组

	if(!led_set) //如果不是灯光设置层
	{
		if(key_set)
		{
			key_state = KeyNum;
		}
		else
		{
			if(key_layer[key_state][KeyNum] == KEY_FN)
				{FN_flag = true;}
			else if(FN_flag)
				{macro_flag = KeyNum;}
			else
				{NKROKeyboard.press(key_layer[key_state][KeyNum]);} //处理按键按下事件
		}
	}
	else //灯光设置专用层
	{
		Led_layer_pressed(KeyNum);
	}
}

/**
 * 灯光设置专用层时按键按下响应函数
 * 输入：
 * 		按键编号
 * */
void Led_layer_pressed(int KeyNum)
{
	switch(KeyNum)
	{
		case 0 :
		{
			led_brightness = 0;
			break;
		}
		case 1 :
		{
			led_brightness = BRIGHTNESS;
			break;
		}
		case 2 :
		{
			led_brightness = led_brightness - 16;
			break;
		}
		case 3 :
		{
			led_brightness = led_brightness + 16;
			break;
		}
		case 4 :
		{
			led_layer = 0;
			LED_AllClear();
			break;
		}
		case 5 :
		{
			led_layer = 1;
			LED_AllClear();
			break;
		}
		case 6 :
		{
			led_layer = 2;
			LED_AllClear();
			break;
		}
		case 7 :
		{
			led_layer = 3;
			LED_AllClear();
			break;
		}
		default : break;
	}
}
