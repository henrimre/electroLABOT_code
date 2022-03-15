#include <head.h>

Servo servo;

Head::Head()
{
    servo.attach(pin_servo);

}

void Head::move_head(int degrees)
{
    servo.write(degrees);
}

void Head::look_around()
{
    double distance_left_side = 0;
    double distance_right_side = 0;

    move_head(0);
    
}

double Head::look()
{
    uint32_t start_time = 0, stop_time = 0;
    double distance = 0;
    bool ancien_etat = 0;

    pinMode(pin_ultrason, OUTPUT);
    digitalWrite(pin_ultrason, HIGH);
    delayMicroseconds(2);

    vTaskSuspendAll();

    digitalWrite(pin_ultrason, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin_ultrason, LOW);

    pinMode(pin_ultrason, INPUT);

    start_time = micros();
    ancien_etat = digitalRead(pin_ultrason);
    while (ancien_etat == digitalRead(pin_ultrason) && ((micros() - start_time) < 40000));

    start_time = micros();

    ancien_etat = digitalRead(pin_ultrason);
    while(ancien_etat == digitalRead(pin_ultrason) && ((micros()-start_time) < 40000));
    
    stop_time = micros();

    xTaskResumeAll();

    distance = fabs(((stop_time - 40 - start_time) / 58.31));

    return distance < 500 ? distance : 501;
}



