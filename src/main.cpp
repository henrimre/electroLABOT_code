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

  billy.move(ALL_WHEELS_FORWARD, 25);

}

void loop() 
{

  billy.move(ALL_WHEELS_FORWARD, 25);
  Serial.println("move All wheels forward");
  delay(2000);
  billy.stop_move(ALL_WHEELS_FORWARD);
  Serial.println("stop All wheels backward");
  delay(2000);
  billy.move(ALL_WHEELS_BACKWARD, 50);
  Serial.println("move All wheel backward");
  delay(2000);
  billy.stop_move(ALL_WHEELS_BACKWARD);
  Serial.println("stop All wheel backward");
  delay(2000);

}