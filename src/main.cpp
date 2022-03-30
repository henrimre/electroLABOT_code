#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;


void setup() 
{
  Serial.begin(115200);
  billy.rgb_set_color(LED_all, 30, 0, 15);
}

void loop() 
{
  billy.move(1,1);
}