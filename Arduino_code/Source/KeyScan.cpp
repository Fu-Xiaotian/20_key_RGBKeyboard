#include "RGBkeyboard.h"

const byte ROWS = 4; //4行
const byte COLS = 5; //5列
char keys[ROWS][COLS] = {
{1,5,9,13,17},
{2,6,10,14,18},
{3,7,11,15,19},
{4,8,12,16,20}
};
byte rowPins[ROWS] = {21, 20, 19, 18}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {4, 5, 6, 7, 8}; //connect to the column pinouts of the kpd

//矩阵键盘识别类
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//非阻塞延时用计数器
unsigned long key_delay_time = 0;

/**
 * 扫描键盘上指定键值的键是否按下
 * @param  keyChar 键值
 * @return         布尔值
 */
bool KeyisPressed(char keyChar)
{
	for (byte i=0; i<20; i++) {
		if ( kpd.key[i].kchar == keyChar ) {
			if ( (kpd.key[i].kstate == PRESSED) && kpd.key[i].stateChanged )
				return true;
		}
	}
	return false;	// Not pressed.
}

/**
 * 扫描键盘上指定键值是否被释放
 * @param  keyChar 键值
 * @return         布尔值
 */
bool KeyisReleased(char keyChar)
{
	for (byte i=0; i<20; i++) {
		if ( kpd.key[i].kchar == keyChar ) {
			if ( (kpd.key[i].kstate == RELEASED) && kpd.key[i].stateChanged )
				return true;
		}
	}
	return false;	// Not released.
}

/**
 * 按键扫描函数
 */
void key_scan(void)
{
	if(kpd.getKeys())
	{
		/*
		记录最后一次按键事件发生的时间
		 */
		last_press_systime = millis();
		/*
		扫描按键按下
		 */
		if(KeyisPressed(1))
			{Key_1_Preased();}
		if(KeyisPressed(2))
			{Key_2_Preased();}
		if(KeyisPressed(3))
			{Key_3_Preased();}
		if(KeyisPressed(4))
			{Key_4_Preased();}
		if(KeyisPressed(5))
			{Key_5_Preased();}
		if(KeyisPressed(6))
			{Key_6_Preased();}
		if(KeyisPressed(7))
			{Key_7_Preased();}
		if(KeyisPressed(8))
			{Key_8_Preased();}
		if(KeyisPressed(9))
			{Key_9_Preased();}
		if(KeyisPressed(10))
			{Key_10_Preased();}
		if(KeyisPressed(11))
			{Key_11_Preased();}
		if(KeyisPressed(12))
			{Key_12_Preased();}
		if(KeyisPressed(13))
			{Key_13_Preased();}
		if(KeyisPressed(14))
			{Key_14_Preased();}
		if(KeyisPressed(15))
			{Key_15_Preased();}
		if(KeyisPressed(16))
			{Key_16_Preased();}
		if(KeyisPressed(17))
			{Key_17_Preased();}
		if(KeyisPressed(18))
			{Key_18_Preased();}
		if(KeyisPressed(19))
			{Key_19_Preased();}
		if(KeyisPressed(20))
			{Key_20_Preased();}

		/*
		扫描按键抬起
		 */
		if(KeyisReleased(1))
			{Key_1_Released();}
		if(KeyisReleased(2))
			{Key_2_Released();}
		if(KeyisReleased(3))
			{Key_3_Released();}
		if(KeyisReleased(4))
			{Key_4_Released();}
		if(KeyisReleased(5))
			{Key_5_Released();}
		if(KeyisReleased(6))
			{Key_6_Released();}
		if(KeyisReleased(7))
			{Key_7_Released();}
		if(KeyisReleased(8))
			{Key_8_Released();}
		if(KeyisReleased(9))
			{Key_9_Released();}
		if(KeyisReleased(10))
			{Key_10_Released();}
		if(KeyisReleased(11))
			{Key_11_Released();}
		if(KeyisReleased(12))
			{Key_12_Released();}
		if(KeyisReleased(13))
			{Key_13_Released();}
		if(KeyisReleased(14))
			{Key_14_Released();}
		if(KeyisReleased(15))
			{Key_15_Released();}
		if(KeyisReleased(16))
			{Key_16_Released();}
		if(KeyisReleased(17))
			{Key_17_Released();}
		if(KeyisReleased(18))
			{Key_18_Released();}
		if(KeyisReleased(19))
			{Key_19_Released();}
		if(KeyisReleased(20))
			{Key_20_Released();}
	}
}
