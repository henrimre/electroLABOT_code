#include <main.h>
#include <led.h>

//Constructeur de la classe LED
/*
Led::Led(int pin_led)
{
    pinMode(pin_led, OUTPUT);
    
}
*/

bool led_state = false;
unsigned long previous_millis = 0;
unsigned long current_millis;

char led_d11 = 0x000000;
char led_d12 = 0x000000;
char led_d13 = 0x000000;
char led_d14 = 0x000000;

Led::Led()
{
    FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds,NUM_LEDS);
}

Led::Led(int pin_led)
{
    pinMode(pin_led,OUTPUT);
}

void Led::led_off(int pin_led)
{
    digitalWrite(pin_led, LOW);
}

void Led::led_on(int pin_led)
{
    digitalWrite(pin_led, HIGH);
}

void Led::rgb_blink(unsigned long blink_time)
{
    current_millis = millis();
    
    if((current_millis - previous_millis) >= blink_time)
    {
        Serial.print("Toogle led");
        previous_millis = millis();

        for (int i = 0; i < 4; i++)
        {
            if(led_state == true) leds[i] = 0x000000;
            else leds[i] = CRGB::Tomato;
        }

        FastLED.show();
        
        if(led_state == true) led_state = false;
        else led_state = true;
    }
    
}

