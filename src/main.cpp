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
  Serial.println();
  Serial.println();
  Serial.println("ALL WHEELS FORWARD");
  billy.move(ALL_WHEELS_BACKWARD, 20);
  //billy.self_driving_ultrason(30, 15);
  delay(1000);
  billy.stop_move_2(ALL_WHEELS_STOP);
  delay(1000);

  Serial.println();
  Serial.println();
  Serial.println("ALL WHEELS BACKWARD");

  billy.move(ALL_WHEELS_FORWARD, 20);
  delay(1000);
  billy.stop_move_2(ALL_WHEELS_STOP);
  delay(1000);

  /*
  time2 = millis();
  if(time2-time1 > 500){
    billy.self_driving_ultrason(30, 15);
    time1 = time2;
  }

  digitalWrite(LED_BUILTIN, digitalRead(LEFT_WHEELS_EN));
  billy.look_around();
  delay(1000);
*/
}