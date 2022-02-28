#include <wheels.h>
#include <main.h>

Wheels::Wheels()
{
    pinMode(RIGHT_WHEELS_EN, OUTPUT);
    pinMode(RIGHT_WHEELS_FORWARD, OUTPUT);
    pinMode(RIGHT_WHEELS_BACKWARD, OUTPUT);
    
    pinMode(LEFT_WHEELS_EN, OUTPUT);
    pinMode(LEFT_WHEELS_FORWARD, OUTPUT);
    pinMode(LEFT_WHEELS_BACKWARD, OUTPUT);
          
    ledcSetup(PWM_MOTOR1_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);
    ledcSetup(PWM_MOTOR1_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);

}

void Wheels::move(char moteur, char vitesse_pourcent)
{
    char vitesse_255 = map(vitesse_pourcent, 0, 100, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 255);

    switch (moteur)
    {
    
    case ALL_WHEELS_FORWARD:
        attach_detach_PWM(RIGHT_WHEELS_FORWARD, vitesse_255, 2);
        attach_detach_PWM(LEFT_WHEELS_FORWARD, vitesse_255, 2);
        break;
    
    case ALL_WHEELS_BACKWARD: 
        attach_detach_PWM(RIGHT_WHEELS_BACKWARD, vitesse_255, 2);
        attach_detach_PWM(LEFT_WHEELS_BACKWARD, vitesse_255, 2);
        break;

    case RIGHT_WHEELS_BACKWARD:
    case RIGHT_WHEELS_FORWARD:
    case LEFT_WHEELS_FORWARD:
    case LEFT_WHEELS_BACKWARD:
        attach_detach_PWM(moteur, vitesse_255, 1);
        break;



    default:
        break;
    }
}

void Wheels::stop_move(char moteur)
{
    char vitesse_255 = 0;
    switch (moteur)
    {
    case ALL_WHEELS_FORWARD:
        attach_detach_PWM(RIGHT_WHEELS_FORWARD, vitesse_255, 0);
        attach_detach_PWM(LEFT_WHEELS_FORWARD, vitesse_255, 0);
        break;
    
    case ALL_WHEELS_BACKWARD: 
        attach_detach_PWM(RIGHT_WHEELS_BACKWARD, vitesse_255, 0);
        attach_detach_PWM(LEFT_WHEELS_BACKWARD, vitesse_255, 0);
        break;

    case RIGHT_WHEELS_FORWARD:
    case RIGHT_WHEELS_BACKWARD:
    case LEFT_WHEELS_FORWARD:
    case LEFT_WHEELS_BACKWARD:
        attach_detach_PWM(moteur, vitesse_255, 0);
        break;

    default:
        break;
    }
}

void attach_detach_PWM(char moteur, char vitesse_255, char attach)
{
    /*
    Valeur possible pour attach : 
        0 : stop_move
        1 : move seulement 1 moteur
        2 : move les 2 moteurs
    */
    char attach_pin = moteur;
    char attach_chanel;
    char detach_pin;
    char enable_pin;

    switch (moteur)
    {
    case LEFT_WHEELS_FORWARD:
        enable_pin = LEFT_WHEELS_EN;
        detach_pin = LEFT_WHEELS_BACKWARD;
        attach_chanel = PWM_MOTOR1_CHANNEL;
        break;

    case LEFT_WHEELS_BACKWARD:
        enable_pin = LEFT_WHEELS_EN;
        detach_pin = LEFT_WHEELS_FORWARD;
        attach_chanel = PWM_MOTOR1_CHANNEL;
        break;
    
    case RIGHT_WHEELS_FORWARD:
        enable_pin = RIGHT_WHEELS_EN;
        detach_pin = RIGHT_WHEELS_BACKWARD;
        attach_chanel = PWM_MOTOR2_CHANNEL;
        break;
    
    case RIGHT_WHEELS_BACKWARD:
        enable_pin = RIGHT_WHEELS_EN;
        detach_pin = RIGHT_WHEELS_FORWARD;
        attach_chanel = PWM_MOTOR2_CHANNEL;
        break;

    default:
        break;
    }

    if (attach !=2)
    {
    digitalWrite(enable_pin, HIGH);

    if(attach == 1) ledcAttachPin(moteur, attach_chanel);
    else digitalWrite(attach_pin, LOW);

    ledcDetachPin(detach_pin);
    digitalWrite(detach_pin, LOW);
    ledcWrite(attach_chanel, vitesse_255);
    }
    else 
    {
        ledcAttachPin(moteur, PWM_MOTOR1_CHANNEL);
        ledcWrite(PWM_MOTOR1_CHANNEL, vitesse_255);

    }

}