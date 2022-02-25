#include <elabot.h>

#ifndef LED
#define LED

class Led
{
    private : 

    public : 
        Led();
        Led(int pin_led);
        void led_off(int pin_led);
        void led_on(int pin_led);

};


#endif
