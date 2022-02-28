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
    
}

void Wheels::move(char moteur, char vitesse_pourcent)
{
    char vitesse_255 = map(vitesse_pourcent, 0, 100, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 255);

    // Enable des moteurs
    if (moteur == RIGHT_WHEELS_BACKWARD || moteur == RIGHT_WHEELS_FORWARD) digitalWrite(RIGHT_WHEELS_EN, HIGH);
    
    else if (moteur == LEFT_WHEELS_BACKWARD || moteur == LEFT_WHEELS_FORWARD) digitalWrite(LEFT_WHEELS_EN, HIGH);
    
    else
    {
        digitalWrite(RIGHT_WHEELS_EN, HIGH);
        digitalWrite(LEFT_WHEELS_EN, HIGH);
    }

    //Mise en marche des moteurs
    if (moteur == ALL_WHEELS_FORWARD)
    {
        /*
        digitalWrite(RIGHT_WHEELS_FORWARD, HIGH);
        digitalWrite(LEFT_WHEELS_FORWARD, HIGH);
        */
       ledcAttachPin(RIGHT_WHEELS_FORWARD, PWM_MOTOR1_CHANNEL);
       ledcAttachPin(LEFT_WHEELS_FORWARD, PWM_MOTOR1_CHANNEL);
    }

    else if (moteur == ALL_WHEELS_BACKWARD)
    {
        /*
        digitalWrite(RIGHT_WHEELS_BACKWARD, HIGH);
        digitalWrite(LEFT_WHEELS_BACKWARD, HIGH);
        */
       ledcAttachPin(RIGHT_WHEELS_BACKWARD, PWM_MOTOR1_CHANNEL);
       ledcAttachPin(LEFT_WHEELS_BACKWARD, PWM_MOTOR1_CHANNEL);
    }

    else
    {
        ledcAttachPin(moteur, PWM_MOTOR1_CHANNEL);
    }

        ledcSetup(PWM_MOTOR1_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);
        ledcWrite(PWM_MOTOR1_CHANNEL, vitesse_255);
    

}

void Wheels::stop_move(char moteur)
{
    // Disable des moteurs
    if (moteur = RIGHT_WHEELS_BACKWARD || moteur == RIGHT_WHEELS_FORWARD) ledcWrite(PWM_MOTOR1_CHANNEL, 0);
    else if (moteur == LEFT_WHEELS_BACKWARD || moteur == LEFT_WHEELS_FORWARD) digitalWrite(LEFT_WHEELS_EN, LOW);
    else
    {
        digitalWrite(RIGHT_WHEELS_EN, LOW);
        digitalWrite(LEFT_WHEELS_EN, LOW);
    }

    //Mise en marche des moteurs
    if(moteur == ALL_WHEELS_FORWARD)
    {
        digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
        digitalWrite(LEFT_WHEELS_FORWARD, LOW);
    }
    else if (moteur == ALL_WHEELS_BACKWARD)
    {
        digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
    }
}