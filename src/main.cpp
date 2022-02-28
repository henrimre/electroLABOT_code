#include <main.h>
#include <elabot.h>
#include <FastLED.h>

Elabot billy;
int dutycycle = 0;


void setup() 
{
  Serial.begin(115200);

  Led built_in(LED_BUILTIN);  

  billy.led_on(LED_BUILTIN);
  
  billy.rgb_set_color(LED_all, 30, 0, 15);

/*
  billy.move(RIGHT_WHEELS_FORWARD, 10);
  billy.move(LEFT_WHEELS_FORWARD, 80);
*/
Serial.println();
Serial.println();
Serial.println();
Serial.println();

billy.move(ALL_WHEELS_FORWARD, 40);
}

void loop() 
{
  
  delay(3000);
  billy.stop_move(ALL_WHEELS_FORWARD);
  delay(3000);
  billy.move(ALL_WHEELS_FORWARD, 40);

}