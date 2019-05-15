#include "SERVO.h"



void SERVO_Init(){

}


void SERVO_Rotate(uint8_t rotate_degree, SERVO_DIRECTION direction)
{
    int alpha =90;
    int DC = 0; 
    if ( direction == 0 )
     DC = ((alpha+30/18)+10);
        
    else
     DC = ((alpha-30/18)+10);

    PWM_Write(SERVO_PIN_M ,  DC);
}