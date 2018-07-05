#ifndef __KEYSCAN_H
#define __KEYSCAN_H

bool KeyisPressed(char keyChar);
bool KeyisReleased(char keyChar);
void key_scan(void);

extern Keypad kpd;

#endif