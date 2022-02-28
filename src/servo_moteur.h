#ifndef SERVO_MOTEUR
#define SERVO_MOTEUR

#include <ESP32Servo.h>

#define servo_pin   13

class Head
{
    private : 

    public : 
    Head();
    void move_head(int degres);

};

#endif