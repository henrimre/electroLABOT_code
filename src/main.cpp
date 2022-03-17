#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;
int dutycycle = 0;


void setup() 
{
  Serial.begin(115200);
  
  billy.rgb_set_color(LED_all, 0, 15, 2);

}

void loop() 
{

}