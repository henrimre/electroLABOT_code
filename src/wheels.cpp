#include <wheels.h>
#include <main.h>

Wheels::Wheels()
{
    //pinMode(RIGHT_WHEELS_EN, OUTPUT);
    pinMode(RIGHT_WHEELS_FORWARD, OUTPUT);
    pinMode(RIGHT_WHEELS_BACKWARD, OUTPUT);
    
   //pinMode(LEFT_WHEELS_EN, OUTPUT);
    pinMode(LEFT_WHEELS_FORWARD, OUTPUT);
    pinMode(LEFT_WHEELS_BACKWARD, OUTPUT);
          
    ledcSetup(PWM_MOTOR1_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);
    ledcSetup(PWM_MOTOR2_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);

    ledcAttachPin(LEFT_WHEELS_EN, PWM_MOTOR1_CHANNEL);
    ledcAttachPin(RIGHT_WHEELS_EN, PWM_MOTOR2_CHANNEL);

}

void Wheels::move(int16_t left_wheels_speed, int16_t right_wheels_speed)
{
    /*
        vitesse en %
        vitesse < 0 -> reculer 
        vitesse > 0 -> avancer
        vitesses = 0 -> arrêter

        PWM sur l'enable
    */
   
   if(previous_right_wheels_speed != left_wheels_speed)
   {    
        previous_left_wheels_speed = left_wheels_speed;
        if(left_wheels_speed !=0)
        {
            //Serial.println("Roue gauche avant");
            digitalWrite(LEFT_WHEELS_BACKWARD, left_wheels_speed <0);
            digitalWrite(LEFT_WHEELS_FORWARD, left_wheels_speed > 0);
            left_wheels_speed = map(left_wheels_speed, start_val_left_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
            ledcWrite(PWM_MOTOR1_CHANNEL, left_wheels_speed);
        }

        else
        {
            //Serial.print("Left wheels stop");
            digitalWrite(LEFT_WHEELS_FORWARD, LOW);
            digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
        }
       
   }

    if(previous_right_wheels_speed != right_wheels_speed)
    {
        previous_right_wheels_speed = right_wheels_speed;
        if(right_wheels_speed != 0)
        {
            digitalWrite(RIGHT_WHEELS_BACKWARD, right_wheels_speed < 0);
            digitalWrite(RIGHT_WHEELS_FORWARD, right_wheels_speed > 0);
            right_wheels_speed = map(right_wheels_speed, start_val_right_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
            ledcWrite(PWM_MOTOR2_CHANNEL, right_wheels_speed);
        }

        else 
        {
            digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
            digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        }
    }
}