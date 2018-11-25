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
        msg = Serial.read();
        if(msg >= 0 && msg < 20)
        {
            key_state = msg;
            Serial.print(msg);
            OLED_Display();
        }
        else
        {
            Serial.print(-1);
        }
    }
}
