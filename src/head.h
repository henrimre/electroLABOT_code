#ifndef HEAD
#define HEAD

#include <ESP32Servo.h>

#define pin_servo       13
#define pin_ultrason    27

class Head
{
    private : 

    public : 
    Head();
    void move_head(int degres);
    double look();
    void look_around();

};

#endif