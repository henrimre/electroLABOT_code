#include <wheels.h>
#include <main.h>
#include <string>

Wheels::Wheels()
{
    pinMode(RIGHT_WHEELS_EN, OUTPUT);
    pinMode(RIGHT_WHEELS_FORWARD, OUTPUT);
    pinMode(RIGHT_WHEELS_BACKWARD, OUTPUT);
    
    pinMode(LEFT_WHEELS_EN, OUTPUT);
    pinMode(LEFT_WHEELS_FORWARD, OUTPUT);
    pinMode(LEFT_WHEELS_BACKWARD, OUTPUT);
          
    ledcSetup(PWM_MOTOR1_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);
    ledcSetup(PWM_MOTOR2_CHANNEL, PWM_MOTOR_FREQ, PWM_MOTOR_RES);

}

void Wheels::move(char moteur, char vitesse_pourcent)
{
    char vitesse_255 = map(vitesse_pourcent, 0, 100, PWM_MOTOR_MIN_VALUE_DUTYCYCLE, 255);

    switch (moteur)
    {
    
    case ALL_WHEELS_FORWARD:
        Serial.println("two wheels forward");
        attach_detach_PWM(RIGHT_WHEELS_FORWARD, vitesse_255, 2);
        attach_detach_PWM(LEFT_WHEELS_FORWARD, vitesse_255, 2);     
        ////Serial.println("LEFT_WHEELS_FORWARD");   
        break;
    
    case ALL_WHEELS_BACKWARD: 
        Serial.println("two wheels backward");
        attach_detach_PWM(RIGHT_WHEELS_BACKWARD, vitesse_255, 2);
        attach_detach_PWM(LEFT_WHEELS_BACKWARD, vitesse_255, 2);
        break;

    case RIGHT_WHEELS_BACKWARD:
    case RIGHT_WHEELS_FORWARD:
    case LEFT_WHEELS_FORWARD:
    case LEFT_WHEELS_BACKWARD:
        Serial.println("one wheel");
        attach_detach_PWM(moteur, vitesse_255, 1);
        break;

    default:
        break;
    }
}

void Wheels::stop_move_2(char moteur)
{
    char vitesse_255 = 0;

    switch (moteur)
    {
    case ALL_WHEELS_STOP :
        digitalWrite(RIGHT_WHEELS_EN, LOW);
        digitalWrite(LEFT_WHEELS_EN, LOW);
        ledcDetachPin(LEFT_WHEELS_FORWARD);
        digitalWrite(LEFT_WHEELS_FORWARD, LOW);
        ledcDetachPin(LEFT_WHEELS_BACKWARD);
        digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
        ledcDetachPin(RIGHT_WHEELS_BACKWARD);
        digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        ledcDetachPin(RIGHT_WHEELS_FORWARD);
        digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
                
    case RIGHT_WHEELS_STOP:
        digitalWrite(RIGHT_WHEELS_EN, LOW);
        ledcDetachPin(RIGHT_WHEELS_FORWARD);
        ledcDetachPin(RIGHT_WHEELS_BACKWARD);
        digitalWrite(RIGHT_WHEELS_FORWARD, LOW);
        digitalWrite(RIGHT_WHEELS_BACKWARD, LOW);
        break;
    
    case LEFT_WHEELS_STOP:
        ledcDetachPin(LEFT_WHEELS_BACKWARD);
        ledcDetachPin(LEFT_WHEELS_FORWARD);
        digitalWrite(LEFT_WHEELS_EN, LOW);
        digitalWrite(LEFT_WHEELS_FORWARD, LOW);
        digitalWrite(LEFT_WHEELS_BACKWARD, LOW);
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
        Serial.println("ALL WHEELS FORWARD STOP");
        attach_detach_PWM(RIGHT_WHEELS_FORWARD, vitesse_255, 0);
        attach_detach_PWM(LEFT_WHEELS_FORWARD, vitesse_255, 0);
        break;
    
    case ALL_WHEELS_BACKWARD: 
        Serial.println("ALL WHEELS BACKWARD STOP");
        attach_detach_PWM(RIGHT_WHEELS_BACKWARD, vitesse_255, 0);
        attach_detach_PWM(LEFT_WHEELS_BACKWARD, vitesse_255, 0);
        break;

    case RIGHT_WHEELS_FORWARD:
    case RIGHT_WHEELS_BACKWARD:
    case LEFT_WHEELS_FORWARD:
    case LEFT_WHEELS_BACKWARD:
        Serial.println("ONE WHEEL STOP");
        attach_detach_PWM(moteur, vitesse_255, 0);
        break;

    default:
        break;
    }
}

void Wheels::run_elabot_run(char moteur, char vitesse_100, int retard)
{
    move(moteur, vitesse_100);
    delay(retard);
    stop_move(moteur);
}

void attach_detach_PWM (char moteur, char vitesse_255, char attach)
{
    ////Serial.println("attach_detach_pwm");
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
        Serial.println("switch left wheels forward");
        Serial.println("LEFT_WHEELS_FORWARD");
        enable_pin = LEFT_WHEELS_EN;
        detach_pin = LEFT_WHEELS_BACKWARD;
        attach_chanel = PWM_MOTOR1_CHANNEL;
        break;

    case LEFT_WHEELS_BACKWARD:
        Serial.println("switch left wheels backward");
        Serial.println("LEFT_WHEELS_BACKWARD");
        enable_pin = LEFT_WHEELS_EN;
        detach_pin = LEFT_WHEELS_FORWARD;
        attach_chanel = PWM_MOTOR1_CHANNEL;
        break;
    
    case RIGHT_WHEELS_FORWARD:
        Serial.println("switch right wheels forward");
        Serial.println("RIGHT_WHEELS_FORWARD");
        enable_pin = RIGHT_WHEELS_EN;
        detach_pin = RIGHT_WHEELS_BACKWARD;
        attach_chanel = PWM_MOTOR2_CHANNEL;
        break;
    
    case RIGHT_WHEELS_BACKWARD:
        Serial.println("switch right wheel backward");
        Serial.println("RIGHT_WHEELS_BACKWARD");
        enable_pin = RIGHT_WHEELS_EN;
        detach_pin = RIGHT_WHEELS_FORWARD;
        attach_chanel = PWM_MOTOR2_CHANNEL;
        break;

    default:
        Serial.println("switch default");
        break;
    }

    Serial.print("\t enable_pin : \t");
    Serial.print(int(enable_pin));
    Serial.print("\n\t detach_pin : \t");
    Serial.println(int(detach_pin));
    Serial.print("\t attach_chanel :\t");
    Serial.println(int(attach_chanel));

    if(attach!=2)
    {
        if(attach == 1) 
        {   
            Serial.println("one wheel move");
            ledcAttachPin(moteur, attach_chanel);
            digitalWrite(enable_pin, HIGH);
        }
        else 
        {
            Serial.println("wheel stop");
            digitalWrite(attach_pin, LOW);
            digitalWrite(enable_pin, LOW);
        }

        ledcDetachPin(detach_pin);
        Serial.print("\t detach_pin :\t");
        Serial.println(int(detach_pin));
        digitalWrite(detach_pin, LOW);
        ledcWrite(attach_chanel, vitesse_255);
    }

    else 
    {
        Serial.println("two wheels move");
        digitalWrite(enable_pin, HIGH);
        Serial.print("digitalWrite("),
        Serial.print(int(enable_pin));
        Serial.println(", HIGH);");
        //digitalWrite(LEFT_WHEELS_EN, HIGH);
        ledcAttachPin(moteur, PWM_MOTOR1_CHANNEL);
        Serial.print("ledcAttach("),
        Serial.print(int(moteur));
        Serial.println(", PWM_MOTOR1_CHANNEL);");
        //ledcAttachPin(LEFT_WHEELS_FORWARD, PWM_MOTOR1_CHANNEL);
        ledcWrite(PWM_MOTOR1_CHANNEL, vitesse_255);
    }

}