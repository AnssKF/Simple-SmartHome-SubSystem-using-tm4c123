#ifndef _UART5_H_
#define _UART5_H_

#include "stdint.h"

void UART5_init(void);

uint8_t UART5_Rx(void);

void UART5_Tx(uint8_t c);

#endif