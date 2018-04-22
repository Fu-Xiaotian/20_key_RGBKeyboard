#include "RGBKeyboard.h"

//宏标志，0为无宏激活，1~20为对应按键宏激活
int macro_flag = 0;

void Macro_Switch(void)
{
	switch(macro_flag)
	{
		case 1 : Key_1_HOLD(); break;
		case 2 : Key_2_HOLD(); break;
		case 3 : Key_3_HOLD(); break;
		case 4 : Key_4_HOLD(); break;
		case 5 : Key_5_HOLD(); break;
		case 6 : Key_6_HOLD(); break;
		case 7 : Key_7_HOLD(); break;
		case 8 : Key_8_HOLD(); break;
		case 9 : Key_9_HOLD(); break;
		case 10 : Key_10_HOLD(); break;
		case 11 : Key_11_HOLD(); break;
		case 12 : Key_12_HOLD(); break;
		case 13 : Key_13_HOLD(); break;
		case 14 : Key_14_HOLD(); break;
		case 15 : Key_15_HOLD(); break;
		case 16 : Key_16_HOLD(); break;
		case 17 : Key_17_HOLD(); break;
		case 18 : Key_18_HOLD(); break;
		case 19 : Key_19_HOLD(); break;
		case 20 : Key_20_HOLD(); break;
	}
}
