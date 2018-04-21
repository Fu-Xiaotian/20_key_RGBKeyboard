#ifndef __LED_H
#define __LED_H

void LED_Init(void);
bool LED_delay(unsigned long t);
void setone(int R, int G, int B, int n);
void clearone(int n);
void LED_AllClear(void);
void brightness_upload(void);
void All_bright(uint8_t R, uint8_t G, uint8_t B);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
void rainbowPoint(uint8_t wait);
uint32_t Wheel(byte WheelPos);

extern bool led_enable[20];
extern int led_brightness;

#define IF_LED_LAYER_CHANGE if(led_layer != old_led_layer){	old_led_layer = led_layer;	OLED_Display();	break;	}

#endif
