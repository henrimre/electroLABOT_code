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

void Wheels::move(int left_wheels_speed, int right_wheels_speed)
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
        if(left_wheels_speed > 0)
        {
            previous_left_wheels_speed = left_wheels_speed;
            //Serial.println("Roue gauche avant");
            left_wheels_speed = map(left_wheels_speed, start_val_left_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
            ledcWrite(PWM_MOTOR1_CHANNEL, left_wheels_speed);
            digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
            digitalWrite(LEFT_WHEELS_FORWARD, HIGH);
            
        }

        else if(left_wheels_speed < 0)
        {
            previous_left_wheels_speed = left_wheels_speed;
            //Serial.println("Roue gauche arrière");
            left_wheels_speed = 0-left_wheels_speed;
            left_wheels_speed = map(left_wheels_speed, start_val_left_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
            //Serial.print("left_wheels_speed :");
            //Serial.println(left_wheels_speed);
            ledcWrite(PWM_MOTOR1_CHANNEL, left_wheels_speed);
            digitalWrite(LEFT_WHEELS_FORWARD, LOW);
            digitalWrite(LEFT_WHEELS_BACKWARD, HIGH);
            
        }

        else if(left_wheels_speed == 0)
        {
            //Serial.print("Left wheels stop");
            digitalWrite(LEFT_WHEELS_FORWARD, LOW);
            digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
            previous_left_wheels_speed = left_wheels_speed;
        }
   }

if(previous_right_wheels_speed != right_wheels_speed)
{
    if(right_wheels_speed > 0)
    {
        previous_right_wheels_speed = right_wheels_speed;
        //Serial.println("Right wheels forward");
        right_wheels_speed = map(right_wheels_speed, start_val_right_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
        ledcWrite(PWM_MOTOR2_CHANNEL, right_wheels_speed);
        digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        digitalWrite(RIGHT_WHEELS_FORWARD, HIGH);
        
    }

    else if(right_wheels_speed < 0)
    {
        previous_right_wheels_speed = right_wheels_speed;
        //Serial.println("Right wheel backward");
        right_wheels_speed = 0-right_wheels_speed;
        //Serial.println(right_wheels_speed);
        right_wheels_speed = map(right_wheels_speed, start_val_right_wheels_speed, max_val_wheels_speed, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 4096);
        ledcWrite(PWM_MOTOR2_CHANNEL, right_wheels_speed);
        //Serial.print("right_wheels_speed :");
        //Serial.print(right_wheels_speed);
        digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
        digitalWrite(RIGHT_WHEELS_BACKWARD, HIGH);
       
    }

    else if(right_wheels_speed == 0)
    {
        //Serial.println("Right wheels stop");
        digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
        digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        previous_right_wheels_speed = right_wheels_speed;
    }
}

}