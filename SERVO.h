#ifndef _SERVO_H_
#define _SERVO_H_

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Port_Driver.h"
#include "PWM.h"

#define SERVO_PORT  PORTF
#define SERVO_PIN_M PF5   

typedef enum{
    SETVO_CLKWISE,
    SERVO_CCLKWISE
}SERVO_DIRECTION;

void SERVO_Init();

void SERVO_Rotate(uint8_t rotate_degree, SERVO_DIRECTION direction);

#endif