#ifndef SELF_DRIVING
#define SELF_DRIVING

#include <main.h>
#include <wheels.h>
#include <head.h>

class Self_driving : public Wheels, public Head
{
    private :

    public :
        void self_driving_ultrason(char, char);
};

#endif