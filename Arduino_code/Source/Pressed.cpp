#include "RGBkeyboard.h"

bool FN_flag = false;

/**
 * 按键按下事件响应函数
 */
void Key_1_Preased(void)
{
	if(led_layer == 1) //led照明控制
		{led_enable[0] = true;}

	if(!led_set) //如果不是灯光设置层
	{
		if(key_set)
		{
			key_state = 0;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 1;}
			else
				{NKROKeyboard.press(key_layer[key_state][0]);} //处理按键按下事件
		}
	}
	else //灯光设置专用层
	{
		led_brightness = 0;
	}
}

void Key_2_Preased(void)
{
	if(led_layer == 1)
		{led_enable[1] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 1;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 2;}
			else
				{NKROKeyboard.press(key_layer[key_state][1]);} //处理按键按下事件
		}
	}
	else
	{
		led_brightness = BRIGHTNESS;
	}
}

void Key_3_Preased(void)
{
	if(led_layer == 1)
		{led_enable[2] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 2;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 3;}
			else
				{NKROKeyboard.press(key_layer[key_state][2]);} //处理按键按下事件
		}
	}
	else
	{
		led_brightness = led_brightness - 16;
	}
}

void Key_4_Preased(void)
{
	if(led_layer == 1)
		{led_enable[3] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 3;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 4;}
			else
				{NKROKeyboard.press(key_layer[key_state][3]);} //处理按键按下事件
		}
	}
	else
	{
		led_brightness = led_brightness + 16;
	}
}

void Key_5_Preased(void)
{
	if(led_layer == 1)
		{led_enable[4] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 4;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 5;}
			else
				{NKROKeyboard.press(key_layer[key_state][4]);} //处理按键按下事件
		}
	}
	else
	{
		led_layer = 0;
		LED_AllClear();
	}
}

void Key_6_Preased(void)
{
	if(led_layer == 1)
		{led_enable[5] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 5;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 6;}
			else
				{NKROKeyboard.press(key_layer[key_state][5]);} //处理按键按下事件
		}
	}
	else
	{
		led_layer = 1;
		LED_AllClear();
	}
}

void Key_7_Preased(void)
{
	if(led_layer == 1)
		{led_enable[6] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 6;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 7;}
			else
				{NKROKeyboard.press(key_layer[key_state][6]);} //处理按键按下事件
		}
	}
	else
	{
		led_layer = 2;
		LED_AllClear();
	}
}

void Key_8_Preased(void)
{
	if(led_layer == 1)
		{led_enable[7] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 7;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 8;}
			else
				{NKROKeyboard.press(key_layer[key_state][7]);} //处理按键按下事件
		}
	}
	else
	{
		led_layer = 3;
		LED_AllClear();
	}
}

void Key_9_Preased(void)
{
	if(led_layer == 1)
		{led_enable[8] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 8;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 9;}
			else
				{NKROKeyboard.press(key_layer[key_state][8]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_10_Preased(void)
{
	if(led_layer == 1)
		{led_enable[9] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 9;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 10;}
			else
				{NKROKeyboard.press(key_layer[key_state][9]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_11_Preased(void)
{
	if(led_layer == 1)
		{led_enable[10] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 10;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 11;}
			else
				{NKROKeyboard.press(key_layer[key_state][10]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_12_Preased(void)
{
	if(led_layer == 1)
		{led_enable[11] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 11;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 12;}
			else
				{NKROKeyboard.press(key_layer[key_state][11]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_13_Preased(void)
{
	if(led_layer == 1)
		{led_enable[12] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 12;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 13;}
			else
				{NKROKeyboard.press(key_layer[key_state][12]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_14_Preased(void)
{
	if(led_layer == 1)
		{led_enable[13] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 13;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 14;}
			else
				{NKROKeyboard.press(key_layer[key_state][13]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_15_Preased(void)
{
	if(led_layer == 1)
		{led_enable[14] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 14;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 15;}
			else
				{NKROKeyboard.press(key_layer[key_state][14]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_16_Preased(void)
{
	if(led_layer == 1)
		{led_enable[15] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 15;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 16;}
			else
				{NKROKeyboard.press(key_layer[key_state][15]);} //处理按键按下事件
		}
	}
	else
	{
		
	}
}

void Key_17_Preased(void)
{
	if(led_layer == 1)
		{led_enable[16] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 16;
		}
		else
		{
			if(key_layer[key_state][16] == KEY_FN)
				{FN_flag = true;}
			else
				{NKROKeyboard.press(key_layer[key_state][16]);} //处理按键按下事件
		}
	}
	else
	{
		key_state = 0;
		OLED_Display();
	}
}

void Key_18_Preased(void)
{
	if(led_layer == 1)
		{led_enable[17] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 17;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 18;}
			else
				{NKROKeyboard.press(key_layer[key_state][17]);} //处理按键按下事件
		}
	}
	else
	{
		key_state = 1;
		OLED_Display();
	}
}

void Key_19_Preased(void)
{
	if(led_layer == 1)
		{led_enable[18] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 18;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 19;}
			else
				{NKROKeyboard.press(key_layer[key_state][18]);} //处理按键按下事件
		}
	}
	else
	{
		key_state = 2;
		OLED_Display();
	}
}

void Key_20_Preased(void)
{
	if(led_layer == 1)
		{led_enable[19] = true;}
	if(!led_set)
	{
		if(key_set)
		{
			key_state = 19;
		}
		else
		{
			if(FN_flag)
				{macro_flag = 20;}
			else
				{NKROKeyboard.press(key_layer[key_state][19]);} //处理按键按下事件
		}
	}
	else
	{
		led_brightness = BRIGHTNESS;
		key_state = 0;
		led_layer = 2;
		LED_AllClear();
	}
}
