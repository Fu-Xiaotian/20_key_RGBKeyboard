#ifndef __OLED_H
#define __OLED_H

extern SSD1306AsciiWire oled;
extern int OLED_flag;

void OLED_Init(void);
void OLED_upload(void);
void OLED_Display(void);

#endif
