#include "RGBKeyboard.h"

unsigned long led_delay_time = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, 10, NEO_RGB + NEO_KHZ800);
bool led_enable[20] = {false};

int old_led_layer = 0;
int led_brightness = BRIGHTNESS;
int old_led_brightness = BRIGHTNESS;


/**
 * LED初始化函数
 */
void LED_Init(void)
{
	strip.begin();
  	strip.show();
}

/**
 * 设置一个像素点
 * @param R 红色
 * @param G 绿色
 * @param B 蓝色
 * @param n 像素点编号
 */
void setone(int R, int G, int B, int n)
{
	strip.setPixelColor(n, strip.Color(R, G, B));
	strip.show();
}

/**
 * 清除一个像素点
 * @param n 像素点编号
 */
void clearone(int n)
{
	setone(0,0,0,n);
}

/**
 * 清空LED灯
 */
void LED_AllClear(void)
{
	for(int i = 0; i < 20; i++)
	{
		led_enable[i] = false;
	}
	for(int i = 0; i < 20; i++)
	{
		strip.setPixelColor(i, strip.Color(0, 0, 0));
		strip.show();
	}
}

/**
 * 当led_brightness变量改变时更新亮度
 */
void brightness_upload(void)
{
	if(led_brightness >= 128)
		{led_brightness = 128;}
	if(led_brightness <= 0)
		{led_brightness = 0;}
	if(led_brightness != old_led_brightness)
	{
		old_led_brightness = led_brightness;
		strip.setBrightness(led_brightness);
		OLED_Display();
	}
}

/**
 * 设置灯光全亮
 * @param R 红
 * @param G 绿
 * @param B 蓝
 */
void All_bright(uint8_t R, uint8_t G, uint8_t B)
{
	for(int i = 0; i < strip.numPixels(); i++)
	{
		strip.setPixelColor(i, strip.Color(R, G, B));
	}
	strip.show();
}

/**
 * 单色渐变填充
 * @param c    颜色
 * @param wait 等待时间
 */
void colorWipe(uint32_t c, uint8_t wait)
{
	for(uint16_t i=0; i<strip.numPixels(); i++) 
	{
		IF_LED_LAYER_CHANGE
    	strip.setPixelColor(i, c);
    	strip.show();
    	Scheduler.delay(wait);
  	}
}

/**
 * 同步彩虹灯效
 * @param wait 间隔时间
 */
void rainbow(uint8_t wait) 
{
	uint16_t i, j;

  	for(j=0; j<256; j++) 
  	{
  		IF_LED_LAYER_CHANGE
    	for(i=0; i<strip.numPixels(); i++) 
    	{
      		strip.setPixelColor(i, Wheel((i+j) & 255));
    	}
    	strip.show();
    	Scheduler.delay(wait);
  	}
}

/**
 * 流动彩虹灯效
 * @param wait 等待间隔
 */
void rainbowCycle(uint8_t wait)
{
	uint16_t i, j;

  	for(j=0; j<256*5; j++) 
  	{ // 5 cycles of all colors on wheel
  		IF_LED_LAYER_CHANGE
    	for(i=0; i< strip.numPixels(); i++) {
      	strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    Scheduler.delay(wait);
  }
}

void rainbowPoint(uint8_t wait)
{
	uint16_t i, j;

  	for(j=0; j<256; j++) 
  	{ // 5 cycles of all colors on wheel
    IF_LED_LAYER_CHANGE
    for(i=0; i< strip.numPixels(); i++) 
    {
    	if(led_enable[i])
      		strip.setPixelColor(i, Wheel((i+j) & 255));
      	else
      		clearone(i);
    }
    strip.show();
    Scheduler.delay(wait);
  	}
}

/**
 * 彩虹灯效运算支持函数
 * @param  WheelPos [description]
 * @return          [description]
 */
uint32_t Wheel(byte WheelPos) 
{
	WheelPos = 255 - WheelPos;
	if(WheelPos < 85) 
	{
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	if(WheelPos < 170) 
	{
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
	WheelPos -= 170;
	return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
