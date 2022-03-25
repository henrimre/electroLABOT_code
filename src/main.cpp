#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;
int dutycycle = 0;


void setup() 
{
  Serial.begin(115200);
  billy.rgb_set_color(LED_all, 30, 0, 15);
}

void loop() 
{
  billy.move(30,-30);
  delay(2000);
  billy.move(-30,30);
  delay(2000);
}