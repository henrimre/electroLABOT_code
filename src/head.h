#ifndef HEAD
#define HEAD

#include <ESP32Servo.h>
#include <main.h>

#define pin_servo       13
#define pin_ultrason    27


class Head
{
    private : 
        const char LEFT_FREE = 1;
        const char RIGHT_FREE = 2;
        const char NO_FREE = 3;
        const char KEEP_GOING = 4;
        const char STOP = 5;
    public : 
        Head();
        void move_head(int degres);
        double look();
        char look_around();
        char look_where_you_step(); //regarde où tu mets les pieds ! 

};

#endif