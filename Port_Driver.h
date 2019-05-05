#ifndef _PORT_DRIVE_
#define _PORT_DRIVE_

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "MACROS.h"

// PORT INDEX
#define     PORTA 0
#define     PORTB 1
#define     PORTC 2
#define     PORTD 3
#define     PORTE 4
#define     PORTF 5

// PORTA PINS MASK
#define     PA0 0x01
#define     PA1 0x02
#define     PA2 0x04
#define     PA3 0x08
#define     PA4 0x10
#define     PA5 0x20
#define     PA6 0x40
#define     PA7 0x80

// PORTB PINS MASK
#define     PB0 0x01
#define     PB1 0x02
#define     PB2 0x04
#define     PB3 0x08
#define     PB4 0x10
#define     PB5 0x20
#define     PB6 0x40
#define     PB7 0x80

// PORTC PINS MASK
#define     PC0 0x01
#define     PC1 0x02
#define     PC2 0x04
#define     PC3 0x08
#define     PC4 0x10
#define     PC5 0x20
#define     PC6 0x40
#define     PC7 0x80

// PORTD PINS MASK
#define     PD0 0x01
#define     PD1 0x02
#define     PD2 0x04
#define     PD3 0x08
#define     PD4 0x10
#define     PD5 0x20
#define     PD6 0x40
#define     PD7 0x80

// PORTE PINS MASK
#define     PE0 0x01
#define     PE1 0x02
#define     PE2 0x04
#define     PE3 0x08
#define     PE4 0x10
#define     PE5 0x20
#define     PE6 0x40
#define     PE7 0x80

// PORTF PINS MASK
#define     PF0 0x01
#define     PF1 0x02
#define     PF2 0x04
#define     PF3 0x08
#define     PF4 0x10
#define     PF5 0x20
#define     PF6 0x40
#define     PF7 0x80

typedef enum {
    PORT_PIN_IN, PORT_PIN_OUT
} Port_PinDirection;



void Port_Init(uint8_t port_index);
    /**
     * Initialize port based on selected port_index (0 to 5) by enabling the clock, unlocking the port, and making the selected mode digital
     */

void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirection pins_direction);
    /**
     * Change the direction of the selected pins by pins_mask in the port selected by port_index
     */

void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable);
    /**
     * If enable is 1, the selected pins by pins_mask in the port selected by port_index will be connected to internal pull-up resistor.
     * If enable is 0, the selected pins by pins_mask in the port selected by port_index will be not be connected to internal pull-up resistor.
     */

void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable);
    /**
     * If enable is 1, the selected pins by pins_mask in the port selected by port_index will be connected to internal pull-down resistor.
     * If enable is 0, the selected pins by pins_mask in the port selected by port_index will be not be connected to internal pull-down resistor.
     */

#endif
