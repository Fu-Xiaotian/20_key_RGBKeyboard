#include "RGBkeyboard.h"

/*****************************
 * 使用 
 * NKROKeyboard.press() 键盘按下
 * NKROKeyboard.release() 键盘释放
 * NKROKeyboard.print() 输出字符串
 * Scheduler.delay() 延时毫秒数
 * RUN_ONCE; 使得宏仅进行一次
 * while(macro_flag == 12) {Scheduler.delay(50);} 中间插入此语句使得宏按下一直有效
 * Mouse.click() 模拟鼠标左键按下
 * Mouse.click(MOUSE_RIGHT) 模拟鼠标右键按下
 * Consumer.press() 多媒体控制器按键按下
 * Consumer.release() 多媒体控制器按键释放
 * *****************************/

//宏标志，负为无宏激活，0~19为对应按键宏激活
int macro_flag = -1;
long delay_time = 300;

/**
 * 返回宏延时数据
 */
long get_macro_delay(void)
{
	return delay_time;
}

/**
 * 宏引导函数
 */
void Macro_Switch(void)
{
	switch(macro_flag)
	{
		case 0 : Key_0_MARCO(); break;
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
	}
}

/**
 * 按键宏事件处理函数
 */
void Key_0_MARCO(void)
{
	if(key_state == 0)
	{
		Consumer.write(MEDIA_VOLUME_MUTE);
		RUN_ONCE;
	}
	if(key_state == 1)
	{
		NKROKeyboard.write(KEY_F1);
		RUN_ONCE;
	}
}

void Key_1_MARCO(void)
{
	if(key_state == 0)
	{
		Consumer.press(MEDIA_VOLUME_DOWN);
		while(macro_flag == 2)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_DOWN);
		RUN_ONCE;
	}
	if(key_state == 1)
	{
		NKROKeyboard.write(KEY_F2);
		RUN_ONCE;
	}
}

void Key_2_MARCO(void)
{
	if(key_state == 0)
	{
		Consumer.press(MEDIA_VOLUME_UP);
		while(macro_flag == 3)
			{Scheduler.delay(50);}
		Consumer.release(MEDIA_VOLUME_UP);
		RUN_ONCE;
	}
	if(key_state == 1)
	{
		NKROKeyboard.write(KEY_F3);
		RUN_ONCE;
	}
}

void Key_3_MARCO(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.write(KEY_F4);
		RUN_ONCE;
	}
}

void Key_4_MARCO(void)
{
	if(key_state == 1)
	{
		OLED_flag = 2;
		Mouse.click();
		Scheduler.delay(delay_time);
	}
}

void Key_5_MARCO(void)
{
	
}

void Key_6_MARCO(void)
{

}

void Key_7_MARCO(void)
{

}

void Key_8_MARCO(void)
{
	
}

void Key_9_MARCO(void)
{
	
}

void Key_10_MARCO(void)
{
	
}

void Key_11_MARCO(void)
{
	if(key_state == 1)
	{	
		delay_time = delay_time - 50;
		if(delay_time <= 50)
		{delay_time = 50;}
		RUN_ONCE;
	}
}

void Key_12_MARCO(void)
{
	
}

void Key_13_MARCO(void)
{

}

void Key_14_MARCO(void)
{

}

void Key_15_MARCO(void)
{
	if(key_state == 1)
	{	
		delay_time = delay_time + 50;
		if(delay_time >= 500)
		{delay_time = 500;}
		RUN_ONCE;
	}
}

void Key_16_MARCO(void)
{
	//不可用
}

void Key_17_MARCO(void)
{
	if(key_state == 1)
	{
		NKROKeyboard.press(KEY_RETURN);
		NKROKeyboard.release(KEY_RETURN);
		RUN_ONCE;
	}
}

void Key_18_MARCO(void)
{

}

void Key_19_MARCO(void)
{
	NKROKeyboard.press(KEY_ESC);
	while(macro_flag == 20)
		{Scheduler.delay(50);}
	NKROKeyboard.release(KEY_ESC);
}
