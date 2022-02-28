#include <servo_moteur.h>

Servo servo;

Head::Head()
{
    servo.attach(servo_pin);
}

void Head::move_head(int degrees)
{
    servo.write(degrees);
}