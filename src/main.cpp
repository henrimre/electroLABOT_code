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
  //billy.self_driving_ultrason(30, 25);
  billy.self_driving_IR(80);
  delay(200);
  //billy.stop_move(LEFT_WHEELS_STOP);
  //delay(1000);
  //billy.move(LEFT_WHEELS_FORWARD, 80);
  //delay(1000);
  //billy.stop_move(LEFT_WHEELS_STOP);
  //delay(1000);
  //billy.move(LEFT_WHEELS_FORWARD, 10);
  //delay(1000);

}