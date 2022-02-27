#include <main.h>
#include <elabot.h>
#include <FastLED.h>

Elabot billy;

void setup() 
{
  Serial.begin(115200);

  Led built_in(LED_BUILTIN);  

  billy.led_on(LED_BUILTIN);
  
  billy.rgb_set_color(LED_all, 30, 0, 15);
  
}

void loop() 
{
  //Serial.print("Terminal série : test\r\n");

  //billy.rgb_blink(500);
}