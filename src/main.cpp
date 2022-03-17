#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;
int dutycycle = 0;
char hue = 0;

void setup() 
{
  Serial.begin(115200);
  
  //billy.led_rainbow();

}

void loop() 
{
   billy.led_rainbow(hue++);
   delay(20);
}