#include "RGBkeyboard.h"
/**
 * 按键按住事件响应函数
 */
void Key_1_HOLD(void)
{
	if(key_state == 0)
	{
		NKROKeyboard.write(KEY_ESC);
		RUN_ONCE
	}
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_B);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_2_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_ALT);
		NKROKeyboard.press(KEY_TAB);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_3_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_T);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_4_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_W);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_5_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_1);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_6_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_PAGE_UP);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_7_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_PAGE_DOWN);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_8_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_2);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_9_HOLD(void)
{
	if(key_state == 1)
	{
		Consumer.write(CONSUMER_CALCULATOR);
		RUN_ONCE
	}
}

void Key_10_HOLD(void)
{
	if(key_state == 1)
	{
		Consumer.write(MEDIA_VOLUME_MUTE);
		RUN_ONCE
	}
}

void Key_11_HOLD(void)
{
	if(key_state == 1)
	{
		Consumer.press(MEDIA_VOLUME_DOWN);
		while(macro_flag == 11)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_DOWN);
		RUN_ONCE
	}
}

void Key_12_HOLD(void)
{
	if(key_state == 1)
	{
		Consumer.press(MEDIA_VOLUME_UP);
		while(macro_flag == 12)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_UP);
		RUN_ONCE
	}
}

void Key_13_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_LEFT_ALT);
		NKROKeyboard.press(KEY_A);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_14_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_D);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_15_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_LEFT_SHIFT);
		NKROKeyboard.press(KEY_Z);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_16_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_Z);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_17_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_X);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_18_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_C);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_19_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_V);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_20_HOLD(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_LEFT_CTRL);
		NKROKeyboard.press(KEY_S);
		NKROKeyboard.releaseAll();
		RUN_ONCE
	}
}
