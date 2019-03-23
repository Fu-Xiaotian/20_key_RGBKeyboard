#ifndef __PRESSED_H
#define __PRESSED_H

void Key_N_Preased(int KeyNum);
void Led_layer_pressed(int KeyNum);

#define KEY_FN KEY_RESERVED
#define KEY_MACRO KEY_ERROR_ROLLOVER

extern bool FN_flag;

#endif
