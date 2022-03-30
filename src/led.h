#ifndef LED
#define LED

//#include <elabot.h>
#include <FastLED.h>

//Nombre de LED sur l'ELABOT
#define COLOR_ORDER GRB
const int NUM_LEDS = 4;
const int DATA_PIN = 32;
const int LED_D11  = 0;
const int LED_D12  = 1;
const int LED_D13  = 2;
const int LED_D14  = 3;
const int LED_all  = 4;

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