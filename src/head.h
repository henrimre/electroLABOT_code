#ifndef HEAD
#define HEAD

#include <ESP32Servo.h>
#include <main.h>

#define pin_servo       13
#define pin_ultrason    27
<<<<<<< HEAD
#define LEFT_FREE       1
#define RIGHT_FREE      2
#define NO_FREE         3
#define KEEP_GOING      0
#define STOP            1
#define PROBLEM         3
=======

>>>>>>> head_

class Head
{
    private : 
<<<<<<< HEAD
=======
        const char LEFT_FREE = 1;
        const char RIGHT_FREE = 2;
        const char NO_FREE = 3;
        const char KEEP_GOING = 4;
        const char STOP = 5;
>>>>>>> head_
    public : 
        Head();
        void move_head(int);
        double look();
        char look_around();
        char look_where_you_step(char); //regarde où tu mets les pieds ! 

};

#endif