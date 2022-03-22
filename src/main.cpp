#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;
int dutycycle = 0;

unsigned long time1, time2;


void setup() 
{
  Serial.begin(115200);  
  billy.rgb_set_color(LED_all, 30, 0, 15);

  billy.move_head(90);

}

void loop() 
{
  billy.self_driving_IR(10);
  //delay(400);
  //billy.move(RIGHT_WHEELS_FORWARD,10);
}