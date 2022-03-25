#ifndef WHEELS
#define WHEELS

//LEFT = moteur 1
#define LEFT_WHEELS_EN          5
#define LEFT_WHEELS_FORWARD     18 
#define LEFT_WHEELS_BACKWARD    19
#define LEFT_WHEELS_STOP        20

//RIGHT = moteur 2
#define RIGHT_WHEELS_EN         4   
#define RIGHT_WHEELS_FORWARD    17
#define RIGHT_WHEELS_BACKWARD   16
#define RIGHT_WHEELS_STOP       21

#define ALL_WHEELS_FORWARD      1
#define ALL_WHEELS_BACKWARD     2
#define ALL_WHEELS_STOP         3
#define ALL_WHEELS_DETACH       6

#define PWM_MOTOR1_CHANNEL  2
#define PWM_MOTOR2_CHANNEL  3
#define PWM_MOTOR_FREQ      3000
#define PWM_MOTOR_RES       8

#define PWM_MOTOR_MIN_VALUE_DUTYCYCLE   50

class Wheels
{
    private :

    public : 
        Wheels();
        void move(char moteur, char vitesse_100);
        void stop_move(char moteur);
        void run_elabot_run (char moteur, char vitesse_100, int delay);
};

void attach_detach_PWM(char moteur, char vitesse, char attach);

#endif