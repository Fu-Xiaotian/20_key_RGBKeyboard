#include "RGBkeyboard.h"

/**
 * 按键释放事件响应函数
 * 输入：
 * 		按键编号
 * **/
void Key_N_Released(int KeyNum)
{
	if(led_layer == 1)
		{led_enable[KeyNum] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(key_layer[key_state][KeyNum] == KEY_FN)
				{FN_flag = false;}
			if(macro_flag == KeyNum)
			{
				macro_flag = 0;
				OLED_flag = 0;
			}
			NKROKeyboard.release(key_layer[key_state][KeyNum]);
		}
	}
}
