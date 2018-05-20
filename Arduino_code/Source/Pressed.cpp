#include "RGBkeyboard.h"

bool FN_flag = false;

/**
 * 按键按下事件响应函数
 */
void Key_1_Preased(void)
{
	if(led_layer == 1)
		{led_enable[0] = true;}
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 : //按键层一
				if(FN_flag)
					macro_flag = 1;
				else
					NKROKeyboard.press(key_layer_1[0]); //处理按键按下事件
			break;
			case 1 : //按键层二
				if(FN_flag)
					macro_flag = 1; //如果FN曾被按下过则使能此按键的宏
				else
					NKROKeyboard.press(key_layer_2[0]); //否则处理相应按键
			break;
			case 2 : //按键层三
				if(macro_flag == 0) //切换按键宏标志
					{macro_flag = 1;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 2;
				else
				NKROKeyboard.press(key_layer_1[1]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 2;
				else
					NKROKeyboard.press(key_layer_2[1]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 2;}
				else
					{macro_flag = 0;}
			break;
		}
	}
	else
	{
		led_brightness = 32;
	}
}

void Key_3_Preased(void)
{
	if(led_layer == 1)
		{led_enable[2] = true;}
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 3;
				else
				NKROKeyboard.press(key_layer_1[2]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 3;
				else
					NKROKeyboard.press(key_layer_2[2]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 3;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 4;
				else
				NKROKeyboard.press(key_layer_1[3]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 4;
				else
					NKROKeyboard.press(key_layer_2[3]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 4;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 5;
				else
				NKROKeyboard.press(key_layer_1[4]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 5;
				else
					NKROKeyboard.press(key_layer_2[4]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 5;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 6;
				else
				NKROKeyboard.press(key_layer_1[5]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 6;
				else
					NKROKeyboard.press(key_layer_2[5]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 6;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 7;
				else
				NKROKeyboard.press(key_layer_1[6]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 7;
				else
					NKROKeyboard.press(key_layer_2[6]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 7;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 8;
				else
				NKROKeyboard.press(key_layer_1[7]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 8;
				else
					NKROKeyboard.press(key_layer_2[7]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 8;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 9;
				else
				NKROKeyboard.press(key_layer_1[8]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 9;
				else
					NKROKeyboard.press(key_layer_2[8]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 9;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 10;
				else
				NKROKeyboard.press(key_layer_1[9]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 10;
				else
					NKROKeyboard.press(key_layer_2[9]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 10;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 11;
				else
				NKROKeyboard.press(key_layer_1[10]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 11;
				else
					NKROKeyboard.press(key_layer_2[10]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 11;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 12;
				else
				NKROKeyboard.press(key_layer_1[11]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 12;
				else
					NKROKeyboard.press(key_layer_2[11]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 12;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 13;
				else
				NKROKeyboard.press(key_layer_1[12]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 13;
				else
					NKROKeyboard.press(key_layer_2[12]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 13;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 14;
				else
				NKROKeyboard.press(key_layer_1[13]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 14;
				else
					NKROKeyboard.press(key_layer_2[13]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 14;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 15;
				else
				NKROKeyboard.press(key_layer_1[14]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 15;
				else
					NKROKeyboard.press(key_layer_2[14]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 15;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 16;
				else
				NKROKeyboard.press(key_layer_1[15]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 16;
				else
					NKROKeyboard.press(key_layer_2[15]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 16;}
				else
					{macro_flag = 0;}
			break;
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
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				FN_flag = true;
			break;
			case 1 :
				FN_flag = !FN_flag;
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 17;}
				else
					{macro_flag = 0;}
			break;
		}
	}
	else
	{
		
	}
}

void Key_18_Preased(void)
{
	if(led_layer == 1)
		{led_enable[17] = true;}
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 18;
				else
				NKROKeyboard.press(key_layer_1[17]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 18;
				else
					NKROKeyboard.press(key_layer_2[17]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 18;}
				else
					{macro_flag = 0;}
			break;
		}
	}
	else
	{
		
	}
}

void Key_19_Preased(void)
{
	if(led_layer == 1)
		{led_enable[18] = true;}
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 19;
				else
				NKROKeyboard.press(key_layer_1[18]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 19;
				else
					NKROKeyboard.press(key_layer_2[18]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 19;}
				else
					{macro_flag = 0;}
			break;
		}
	}
	else
	{
		
	}
}

void Key_20_Preased(void)
{
	if(led_layer == 1)
		{led_enable[19] = true;}
	if(led_state == 0)
	{
		switch(key_state)
		{
			case 0 :
				if(FN_flag)
					macro_flag = 20;
				else
				NKROKeyboard.press(key_layer_1[19]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 20;
				else
					NKROKeyboard.press(key_layer_2[19]);
			break;
			case 2 :
				if(macro_flag == 0)
					{macro_flag = 20;}
				else
					{macro_flag = 0;}
			break;
		}
	}
	else
	{
		
	}
}
