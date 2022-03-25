#ifndef SELF_DRIVING
#define SELF_DRIVING

#include <main.h>
#include <wheels.h>
#include <head.h>

#define IR_SENSOR_1     26
#define IR_SENSOR_2     14
#define IR_threshold    1000
class Self_driving : public Wheels, public Head
{
    private :
        uint16_t ir_sens_2_value;
        uint16_t ir_sens_1_value;
    public :
        Self_driving();
        void self_driving_ultrason(char, char);
        void self_driving_IR(char);
};

void average_IR(int[]);
#endif