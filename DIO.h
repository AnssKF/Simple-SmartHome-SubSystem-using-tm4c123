#ifndef _DIO_DRIVE_H_
#define _DIO_DRIVE_H_

#include "tm4c123gh6pm.h"
#include "Port_Driver.h"


typedef enum{
    STD_LOW, 
    STD_HIGH, 
}Dio_LevelType;

uint8_t DIO_ReadPort(uint8_t port_index, uint8_t pins_mask, uint8_t pins_level);
    /**
     * Return the value of the pins selected by pins_masks in the port selected by port_index
     */


void DIO_WritePort(uint8_t port_index, uint8_t pins_mask, Dio_LevelType pins_level);
    /**
     * Change the value of the pins selected by pins_masks in the port selected by port_index to input pins_level
     */



void DIO_FlipPort(uint8_t port_index, uint8_t pins_mask);
    /**
     *  Toggle the values of the pins selected by pins_masks in the port selected by port_index
     */

#endif