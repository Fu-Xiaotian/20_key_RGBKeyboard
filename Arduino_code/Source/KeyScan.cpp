#include "RGBkeyboard.h"

const byte ROWS = 4; //4行
const byte COLS = 5; //5列
char keys[ROWS][COLS] = {
{0,4,8,12,16},
{1,5,9,13,17},
{2,6,10,14,18},
{3,7,11,15,19}
}; //定义按键编号，编号定义时应当从0开始，顺序定义，不应空格
#define MAX_KEY_NUM 19 //按键编号最大值，决定后面循环的次数
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
	for (byte i=0; i<=MAX_KEY_NUM; i++) {
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
	for (byte i=0; i<=MAX_KEY_NUM; i++) {
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
		for(int KeyNum = 0; KeyNum <= MAX_KEY_NUM; KeyNum++)
		{
			if(KeyisPressed(KeyNum))
			{
				Key_N_Preased(KeyNum);
			}
		}

		/*
		扫描按键抬起
		 */
		for(int KeyNum = 0; KeyNum <= MAX_KEY_NUM; KeyNum++)
		{
			if(KeyisReleased(KeyNum))
			{
				Key_N_Released(KeyNum);
			}
		}
	}
}
