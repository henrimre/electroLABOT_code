#ifndef WHEELS
#define WHEELS

//LEFT = moteur 1
#define LEFT_WHEELS_EN         5
#define LEFT_WHEELS_FORWARD    18 
#define LEFT_WHEELS_BACKWARD   19

//RIGHT = moteur 2
#define RIGHT_WHEELS_EN         4   
#define RIGHT_WHEELS_FORWARD    17
#define RIGHT_WHEELS_BACKWARD   16

#define ALL_WHEELS_FORWARD      1
#define ALL_WHEELS_BACKWARD     2
#define ALL_WHEELS_STOP         3
#define ALL_WHEELS_DETACH       6



class Wheels
{
    private :
        const int PWM_MOTOR1_CHANNEL = 2;
        const int PWM_MOTOR2_CHANNEL = 3;
        const int PWM_MOTOR_FREQ = 3000;
        const int PWM_MOTOR_RES = 8;

        const int PWM_MOTOR_MIN_VALUE_DUTYCYCLE = 60;
        int previous_left_wheels_speed = 0;
        int previous_right_wheels_speed = 0;
        const int max_val_wheels_speed = 200;
        const int start_val_right_wheels_speed = 0;
        const int start_val_left_wheels_speed = 0;


    public : 
        Wheels();
        void move(int roue_droite, int roue_gauche);
};

void attach_detach_PWM(char moteur, char vitesse, char attach);

#endif