#include <main.h>
#include <elabot.h>

Elabot billy;

void setup() 
{
  Serial.begin(115200);  
  billy.rgb_set_color(LED_all, 0, 30, 0);

}

void loop() 
{
  billy.move(1,1);
}