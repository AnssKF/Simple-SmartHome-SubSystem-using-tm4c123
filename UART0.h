#ifndef __UART_H__
#define	__UART_H__

#include <stdint.h>
#include "tm4c123gh6pm.h"

void UART0_Init(void);

uint8_t UART0_Available(void);

uint8_t UART0_Read(void);

void UART0_Write(uint8_t data);

void UART_sendString(const uint8_t *Str);

void UART0_receiveString(uint8_t *Str);


#endif // __UART_H__