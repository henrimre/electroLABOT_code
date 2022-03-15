#include <main.h>
#include <FastLED.h>
#include <elabot.h>

Servo servo2;

Elabot billy;

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
  
}

void loop() 
{
  
  Serial.println("billy.look_around");
  billy.look_around();

  //billy.move_head(90);
  //Serial.print("delay");
  //delay(2000);
  //Serial.print("Terminal série : test\r\n");

  //billy.rgb_blink(500);

 //Serial.println(billy.look());
 // delay(1000);
}