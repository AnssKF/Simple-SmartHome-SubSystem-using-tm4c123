#ifndef __UART5_H__
#define	__UART5_H__

#include <stdint.h>
#include "tm4c123gh6pm.h"

void UART5_Init(void);

uint8_t UART5_Available(void);

uint8_t UART5_Read(void);

void UART5_Write(uint8_t data);

void UART5_sendString(const uint8_t *Str);

void UART5_receiveString(uint8_t *Str);


#endif // __UART5_H__
