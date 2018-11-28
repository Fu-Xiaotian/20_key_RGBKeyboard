#include "RGBkeyboard.h"

void connect_init(void)
{
    Serial.begin(9600);
}

void connect_event(void)
{
    if(Serial.available() > 0)
    {
        int msg = 0;
        char str[10] = {0};
        msg = Serial.read();
        if(msg >= 0 && msg < 20)
        {
            //控制变量全清
		    OLED_flag = 0;
		    macro_flag = 0;
		    FN_flag = false;
            //设置按键层
            key_state = msg;
            //释放所有按键
		    NKROKeyboard.releaseAll();
		    Consumer.releaseAll();
            //回报设置成功消息
            sprintf(str,"a/%d@a",msg);
            Serial.print(str);
            OLED_Display();
        }
        else
        {
            Serial.print("a/ok@a");
        }
    }
}
