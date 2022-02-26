#ifndef LED
#define LED

//#include <elabot.h>
#include <FastLED.h>

//Nombre de LED sur l'ELABOT
#define NUM_LEDS    4 
#define DATA_PIN    32
#define LED_D11     0
#define LED_D12     1
#define LED_D13     2
#define LED_D14     3
#define COLOR_ORDER GRB


class Led
{
    private : 
        void rgb_init();
        CRGB leds[NUM_LEDS];


    public : 
        Led();
        Led(int pin_led);

        void led_off(int pin_led);
        void led_on(int pin_led);

        void rgb_blink(unsigned long blink_time);
        void rgb_set_color(char led, int R, int G, int B);
    
};

#endif