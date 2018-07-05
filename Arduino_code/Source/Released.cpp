#include "RGBkeyboard.h"

/**
 * 按键抬起事件响应函数
 */
void Key_1_Released(void)
{
	if(led_layer == 1)
		{led_enable[0] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 1)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[0]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[0]);
			break;
			case 2 :
				
			break;
		}
}

void Key_2_Released(void)
{
	if(led_layer == 1)
		{led_enable[1] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 2)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[1]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[1]);
			break;
			case 2 :
				
			break;
		}
}

void Key_3_Released(void)
{
	if(led_layer == 1)
		{led_enable[2] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 3)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[2]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[2]);
			break;
			case 2 :
				
			break;
		}
}

void Key_4_Released(void)
{
	if(led_layer == 1)
		{led_enable[3] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 4)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[3]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[3]);
			break;
			case 2 :
				
			break;
		}
}

void Key_5_Released(void)
{
	if(led_layer == 1)
		{led_enable[4] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 5)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[4]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[4]);
			break;
			case 2 :
				
			break;
		}
}

void Key_6_Released(void)
{
	if(led_layer == 1)
		{led_enable[5] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 6)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[5]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[5]);
			break;
			case 2 :
				
			break;
		}
}

void Key_7_Released(void)
{
	if(led_layer == 1)
		{led_enable[6] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 7)
				OLED_flag = 0;
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[6]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[6]);
			break;
			case 2 :
				
			break;
		}
}

void Key_8_Released(void)
{
	if(led_layer == 1)
		{led_enable[7] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 8)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[7]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[7]);
			break;
			case 2 :
				
			break;
		}
}

void Key_9_Released(void)
{
	if(led_layer == 1)
		{led_enable[8] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 9)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[8]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[8]);
			break;
			case 2 :
				
			break;
		}
}

void Key_10_Released(void)
{
	if(led_layer == 1)
		{led_enable[9] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 10)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[9]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[9]);
			break;
			case 2 :
				
			break;
		}
}

void Key_11_Released(void)
{
	if(led_layer == 1)
		{led_enable[10] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 11)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[10]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[10]);
			break;
			case 2 :
				
			break;
		}
}

void Key_12_Released(void)
{
	if(led_layer == 1)
		{led_enable[11] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 12)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[11]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[11]);
			break;
			case 2 :
				
			break;
		}
}

void Key_13_Released(void)
{
	if(led_layer == 1)
		{led_enable[12] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 13)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[12]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[12]);
			break;
			case 2 :
				
			break;
		}
}

void Key_14_Released(void)
{
	if(led_layer == 1)
		{led_enable[13] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 14)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[13]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[13]);
			break;
			case 2 :
				
			break;
		}
}

void Key_15_Released(void)
{
	if(led_layer == 1)
		{led_enable[14] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 15)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[14]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[14]);
			break;
			case 2 :
				
			break;
		}
}

void Key_16_Released(void)
{
	if(led_layer == 1)
		{led_enable[15] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 16)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[15]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[15]);
			break;
			case 2 :
				
			break;
		}
}

void Key_17_Released(void)
{
	if(led_layer == 1)
		{led_enable[16] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				//FN键占用
				FN_flag = false;
			break;
			case 1 :
				if(key_layer_2[16] == KEY_FN)
					//FN键占用
					{;}
				else
					{NKROKeyboard.release(key_layer_2[16]);}
			break;
			case 2 :
				//媒体键占用
			break;
		}
}

void Key_18_Released(void)
{
	if(led_layer == 1)
		{led_enable[17] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 18)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[17]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[17]);
			break;
			case 2 :
				//媒体键占用
			break;
		}
}

void Key_19_Released(void)
{
	if(led_layer == 1)
		{led_enable[18] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 19)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[18]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[18]);
			break;
			case 2 :
				//媒体键占用
			break;
		}
}

void Key_20_Released(void)
{
	if(led_layer == 1)
		{led_enable[19] = false;}
	if(!def_set)
	switch(key_state)
		{
			case 0 :
				if(macro_flag == 20)
				macro_flag = 0;
				NKROKeyboard.release(key_layer_1[19]);
			break;
			case 1 :
				if(FN_flag)
					macro_flag = 0;
				else
					NKROKeyboard.release(key_layer_2[19]);
			break;
			case 2 :
				//媒体键占用
			break;
		}
}
