#define UART7_CLK 80000000
#define UART7_BAUDRATE 9600
#define UART7_PE0_RX (1 << 0)
#define UART7_PE1_TX (1 << 1)

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "Port_Driver.h"
#include "DIO.h"