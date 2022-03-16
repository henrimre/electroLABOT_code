#include <self_driving.h>

double last_look;

void Self_driving::self_driving_ultrason(char vitesse_pourcent, char stop_distance)
{
    Serial.println("Self_driving");
        
    if(look_where_you_step(stop_distance) == KEEP_GOING)
    {
        Serial.println("\t KEEP GOING");
        move_head(90);
        //move(ALL_WHEELS_FORWARD,vitesse_pourcent);
        move(ALL_WHEELS_FORWARD, vitesse_pourcent);
    }
    
    else
    {   
        Serial.println("\t STOP");
        stop_move(ALL_WHEELS_FORWARD);
        /*
        switch (look_around())
        {
        case LEFT_FREE:
            Serial.println("\t \t LEFT_FREE");
            move(LEFT_WHEELS_BACKWARD, vitesse_pourcent);
            move(RIGHT_WHEELS_FORWARD, vitesse_pourcent);
            delay(1000);
            stop_move(LEFT_WHEELS_BACKWARD);
            stop_move(RIGHT_WHEELS_FORWARD);
            delay(1000);
            break;
        
        case RIGHT_FREE:
            Serial.println("\t \t RIGHT_FREE");
            move(LEFT_WHEELS_FORWARD, vitesse_pourcent);
            move(RIGHT_WHEELS_BACKWARD, vitesse_pourcent);
            delay(1000);
            stop_move(LEFT_WHEELS_FORWARD);
            stop_move(RIGHT_WHEELS_BACKWARD);
            delay(1000);
            break;

        case NO_FREE:
            Serial.println("\t \t NO FREE");
            move(ALL_WHEELS_FORWARD, vitesse_pourcent);
            delay(2000);
            break;
        default:
            Serial.println("default case switch self_driving");
            break;
        }
        */
    }


}