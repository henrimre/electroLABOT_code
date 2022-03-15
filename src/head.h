#ifndef HEAD
#define HEAD

#include <ESP32Servo.h>
#include <main.h>

#define pin_servo       13
#define pin_ultrason    27
#define LEFT_FREE       1
#define RIGHT_FREE      2
#define NO_FREE         3

class Head
{
    private : 

    public : 
        Head();
        void move_head(int degres);
        double look();
        char look_around();

};

#endif