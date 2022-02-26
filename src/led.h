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
#define LED_all     4
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
        void rgb_set_color(char led, char R, char G, char B);
        /*
            led = LED_D11, LED_D12, LED_D13, LED_D14 ou LED_all (pour affecter la couleur aux 4 leds)
            R, G, B correspodnent au pourcentage de rouge, vert ou bleu dans la led. 
        */
    
};

char convert_pourcent_to_charvalue(char value);
#endif