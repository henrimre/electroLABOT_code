#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;
int dutycycle = 0;


void setup() 
{
  Serial.begin(115200);

  //Led built_in(LED_BUILTIN);  

  //billy.led_on(LED_BUILTIN);
  
  billy.rgb_set_color(LED_all, 30, 0, 15);
  //billy.move_head(10);

  //servo2.attach(pin_servo);
  //servo2.write(10);
  //servo.attached(pin_servo);
  //billy.move_head(170);
  

/*
  billy.move(RIGHT_WHEELS_FORWARD, 10);
  billy.move(LEFT_WHEELS_FORWARD, 80);
*/
Serial.println();
Serial.println();
Serial.println();
Serial.println();
}

void loop() 
{
  Serial.println();
  Serial.println("Au début");
  billy.run_elabot_run(ALL_WHEELS_FORWARD, 40, 3000);
  billy.move(RIGHT_WHEELS_FORWARD, 20);
  billy.move(LEFT_WHEELS_BACKWARD, 20);
  delay(1500);
  billy.stop_move(RIGHT_WHEELS_FORWARD);
  billy.stop_move(LEFT_WHEELS_BACKWARD);
  billy.run_elabot_run(ALL_WHEELS_BACKWARD, 40, 3000);
}



// coucou Henri lolilol