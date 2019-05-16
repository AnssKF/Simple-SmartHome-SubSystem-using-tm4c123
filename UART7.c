#include "UART7.h"

void UART7_Init(void){
    int i;
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4
    while (!(SYSCTL_RCGCUART_R & SYSCTL_RCGCUART_R7));
    
    UART7_CTL_R = 0;
    UART7_CC_R = 0;
    UART7_IBRD_R = (int)(UART7_CLK / (16 * UART7_BAUDRATE));
    UART7_FBRD_R = (int)((((UART7_CLK / (16 * UART7_BAUDRATE)) - (int)(UART7_CLK / (16 * UART7_BAUDRATE))) * 64) + 0.5);
    UART7_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART7_CTL_R = (UART_CTL_TXE | UART_CTL_RXE | UART_CTL_UARTEN);

    GPIO_PORTE_DEN_R |= (UART7_PE0_RX | UART7_PE1_TX);
    GPIO_PORTE_AFSEL_R |= (UART7_PE0_RX | UART7_PE1_TX);
    GPIO_PORTE_PCTL_R |= 0x00000011;

    // simple delay waiting output to be stable
    for (i = 0; i < 100000; i++);
}

void UART7_TX(char data){
    while (UART7_FR_R & UART_FR_TXFF);
    UART7_DR_R = data;
}

char UART7_RX(void){
    while (UART7_FR_R & UART_FR_RXFE);
    return (char)UART7_DR_R;
}