#include <main.h>
#include <led.h>

//Constructeur de la classe LED
/*
Led::Led(int pin_led)
{
    pinMode(pin_led, OUTPUT);
    
}
*/

Led::Led()
{
    
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