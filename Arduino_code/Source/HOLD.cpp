#include "RGBkeyboard.h"
/**
 * 按键按住事件响应函数
 */
void Key_1_HOLD(void)
{
	if(key_state == 0)
	{
		Keyboard.write(KEY_ESC);
		RUN_ONCE
	}
}

void Key_2_HOLD(void)
{
	
}

void Key_3_HOLD(void)
{
	
}

void Key_4_HOLD(void)
{
	
}

void Key_5_HOLD(void)
{
	
}

void Key_6_HOLD(void)
{
	
}

void Key_7_HOLD(void)
{

}

void Key_8_HOLD(void)
{
	// Serial.println("8 is HOLD");
}

void Key_9_HOLD(void)
{
	// Serial.println("9 is HOLD");
}

void Key_10_HOLD(void)
{
	// Serial.println("10 is HOLD");
}

void Key_11_HOLD(void)
{
	// Serial.println("11 is HOLD");
}

void Key_12_HOLD(void)
{
	// Serial.println("12 is HOLD");
}

void Key_13_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_LEFT_ALT);
		Keyboard.press(KEY_A);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_14_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_D);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_15_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_LEFT_SHIFT);
		Keyboard.press(KEY_Z);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_16_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_Z);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_17_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_X);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_18_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_C);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_19_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_V);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}

void Key_20_HOLD(void)
{
	if(key_state == 2)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_S);
		Keyboard.releaseAll();
		RUN_ONCE
	}
}
