#include <main.h>
#include <elabot.h>



void setup() 
{
  Serial.begin(115200);


  Led built_in(LED_BUILTIN);
  Elabot billy;
  

  billy.led_on(LED_BUILTIN);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //Serial.print("Terminal série : test\r\n");
}