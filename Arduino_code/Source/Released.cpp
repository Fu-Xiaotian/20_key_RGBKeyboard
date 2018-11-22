#include "RGBkeyboard.h"

/**
 * 按键抬起事件响应函数
 */
void Key_1_Released(void)
{
	if(led_layer == 1)
		{led_enable[0] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 1)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][0]);
		}
	}
}

void Key_2_Released(void)
{
	if(led_layer == 1)
		{led_enable[1] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 2)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][1]);
		}
	}
}

void Key_3_Released(void)
{
	if(led_layer == 1)
		{led_enable[2] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 3)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][2]);
		}
	}
}

void Key_4_Released(void)
{
	if(led_layer == 1)
		{led_enable[3] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 4)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][3]);
		}
	}
}

void Key_5_Released(void)
{
	if(led_layer == 1)
		{led_enable[4] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 52)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][4]);
		}
	}
}

void Key_6_Released(void)
{
	if(led_layer == 1)
		{led_enable[5] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 6)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][5]);
		}
	}
}

void Key_7_Released(void)
{
	if(led_layer == 1)
		{led_enable[6] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 7)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][6]);
		}
	}
}

void Key_8_Released(void)
{
	if(led_layer == 1)
		{led_enable[7] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 8)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][7]);
		}
	}
}

void Key_9_Released(void)
{
	if(led_layer == 1)
		{led_enable[8] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 9)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][8]);
		}
	}
}

void Key_10_Released(void)
{
	if(led_layer == 1)
		{led_enable[9] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 10)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][9]);
		}
	}
}

void Key_11_Released(void)
{
	if(led_layer == 1)
		{led_enable[10] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 11)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][10]);
		}
	}
}

void Key_12_Released(void)
{
	if(led_layer == 1)
		{led_enable[11] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 12)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][11]);
		}
	}
}

void Key_13_Released(void)
{
	if(led_layer == 1)
		{led_enable[12] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 13)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][12]);
		}
	}
}

void Key_14_Released(void)
{
	if(led_layer == 1)
		{led_enable[13] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 14)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][13]);
		}
	}
}

void Key_15_Released(void)
{
	if(led_layer == 1)
		{led_enable[14] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 15)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][14]);
		}
	}
}

void Key_16_Released(void)
{
	if(led_layer == 1)
		{led_enable[15] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 16)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][15]);
		}
	}
}

void Key_17_Released(void)
{
	if(led_layer == 1)
		{led_enable[16] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(key_layer[key_state][16] == KEY_FN)
				{FN_flag = false;}
			else
				{NKROKeyboard.release(key_layer[key_state][16]);}
		}
	}
}

void Key_18_Released(void)
{
	if(led_layer == 1)
		{led_enable[17] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 18)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][17]);
		}
	}
}

void Key_19_Released(void)
{
	if(led_layer == 1)
		{led_enable[18] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 19)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][18]);
		}
	}
}

void Key_20_Released(void)
{
	if(led_layer == 1)
		{led_enable[19] = false;}
	if(!led_set)
	{
		if(key_set)
		{
			key_set = false;
			OLED_Display();
		}
		else
		{
			if(macro_flag == 20)
			macro_flag = 0;
			NKROKeyboard.release(key_layer[key_state][19]);
		}
	}
}
