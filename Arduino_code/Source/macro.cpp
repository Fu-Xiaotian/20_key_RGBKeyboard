#include "RGBkeyboard.h"

//宏标志，0为无宏激活，1~20为对应按键宏激活
int macro_flag = 0;

void Macro_Switch(void)
{
	switch(macro_flag)
	{
		case 1 : Key_1_MARCO(); break;
		case 2 : Key_2_MARCO(); break;
		case 3 : Key_3_MARCO(); break;
		case 4 : Key_4_MARCO(); break;
		case 5 : Key_5_MARCO(); break;
		case 6 : Key_6_MARCO(); break;
		case 7 : Key_7_MARCO(); break;
		case 8 : Key_8_MARCO(); break;
		case 9 : Key_9_MARCO(); break;
		case 10 : Key_10_MARCO(); break;
		case 11 : Key_11_MARCO(); break;
		case 12 : Key_12_MARCO(); break;
		case 13 : Key_13_MARCO(); break;
		case 14 : Key_14_MARCO(); break;
		case 15 : Key_15_MARCO(); break;
		case 16 : Key_16_MARCO(); break;
		case 17 : Key_17_MARCO(); break;
		case 18 : Key_18_MARCO(); break;
		case 19 : Key_19_MARCO(); break;
		case 20 : Key_20_MARCO(); break;
	}
}

/**
 * 按键宏事件响应函数
 */
void Key_1_MARCO(void)
{
	if(key_state == 0)
	{
		NKROKeyboard.write(KEY_ESC);
		RUN_ONCE;
	}
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_B);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_2_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_ALT);
		NKROKeyboard.press(KEY_TAB);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_3_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_T);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_4_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_W);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_5_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_1);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_6_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_PAGE_UP);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_7_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_PAGE_DOWN);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_8_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_2);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_9_MARCO(void)
{
	if(key_state == 2)
	{
		Consumer.write(CONSUMER_CALCULATOR);
		RUN_ONCE;
	}
}

void Key_10_MARCO(void)
{
	if(key_state == 2)
	{
		Consumer.write(MEDIA_VOLUME_MUTE);
		RUN_ONCE;
	}
}

void Key_11_MARCO(void)
{
	if(key_state == 2)
	{
		Consumer.press(MEDIA_VOLUME_DOWN);
		while(macro_flag == 21)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_DOWN);
		RUN_ONCE;
	}
}

void Key_12_MARCO(void)
{
	if(key_state == 2)
	{
		Consumer.press(MEDIA_VOLUME_UP);
		while(macro_flag == 22)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_UP);
		RUN_ONCE;
	}
}

void Key_13_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_LEFT_ALT);
		NKROKeyboard.press(KEY_A);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_14_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_D);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_15_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_LEFT_SHIFT);
		NKROKeyboard.press(KEY_Z);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_16_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_Z);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_17_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_X);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_18_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_C);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_19_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_V);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}

void Key_20_MARCO(void)
{
	if(key_state == 2)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_S);
		NKROKeyboard.releaseAll();
		RUN_ONCE;
	}
}
