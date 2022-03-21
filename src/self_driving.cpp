#include <self_driving.h>

double last_look;

 Self_driving::Self_driving()
 {
     pinMode(IR_SENSOR_1, INPUT);
     pinMode(IR_SENSOR_2, INPUT);
     digitalWrite(LED_BUILTIN, HIGH);
 }

void Self_driving::self_driving_ultrason(char vitesse_pourcent, char stop_distance){
    Serial.println("Self_driving");
        
    if(look_where_you_step(stop_distance) == KEEP_GOING)
    {
        //Serial.println("\t KEEP GOING");
        move_head(90);
        move(ALL_WHEELS_FORWARD, vitesse_pourcent);
    }
    
    else
    {   
        //Serial.println("\t STOP");
        stop_move(ALL_WHEELS_STOP);
        delay(1000);
        
        switch (look_around())
        {
        case LEFT_FREE:
            Serial.println("\t \t LEFT_FREE");
            move(LEFT_WHEELS_BACKWARD, vitesse_pourcent);
            move(RIGHT_WHEELS_FORWARD, vitesse_pourcent);
            delay(1000);
            stop_move(LEFT_WHEELS_STOP);
            stop_move(RIGHT_WHEELS_STOP);
            delay(1000);
            break;
        
        case RIGHT_FREE:
            Serial.println("\t \t RIGHT_FREE");
            move(LEFT_WHEELS_FORWARD, vitesse_pourcent);
            move(RIGHT_WHEELS_BACKWARD, vitesse_pourcent);
            delay(1000);
            stop_move(LEFT_WHEELS_STOP);
            stop_move(RIGHT_WHEELS_STOP);
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
        
    }

}

void Self_driving::self_driving_IR(char vitesse_pourcent)
{
    ir_sens_1_value = analogRead(IR_SENSOR_1);
    ir_sens_2_value = analogRead(IR_SENSOR_2);
    Serial.print("ir_sens_1 \t \t ir_sens_2 \n");
    Serial.print(ir_sens_1_value);
    Serial.print("\t \t");
    Serial.print(ir_sens_2_value);
    Serial.println();

    //faire une moyenne sur les dernières valeurs

    if (ir_sens_2_value > IR_threshold)
    {
        //aller à droite 
        Serial.println("Aller à droite");
        move(LEFT_WHEELS_FORWARD, vitesse_pourcent/2);
        delay(200);

    }

    else if (ir_sens_1_value > IR_threshold)
    {
        //aller à gauche 
        Serial.println("Aller à gauche");
        move(RIGHT_WHEELS_FORWARD, vitesse_pourcent/2);
        delay(500);
    }
    else 
    {
        move(RIGHT_WHEELS_FORWARD, vitesse_pourcent);
        move(LEFT_WHEELS_FORWARD, vitesse_pourcent);
    }

    //couleur claire : petite valeur
    //couleur foncé  : grande valeur


}