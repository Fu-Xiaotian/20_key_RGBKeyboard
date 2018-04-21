#ifndef __KEYSCAN_H
#define __KEYSCAN_H

bool KeyisPressed(char keyChar);
bool KeyisReleased(char keyChar);
void key_scan(void);
bool keyscan_delay(unsigned long t);

extern Keypad kpd;

#endif