#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"

#define TIVA 1

void SystemInit()
{
}

// UART5 ------------------------------
UART5_init(void);
void UART5_TX(char data);
char UART5_RX(void);


// UART7 ------------------------------
void UART7_Init(void);
void UART7_TX(char data);
char UART7_RX(void);



// main ------------------------------

// Globals ---------------------------
volatile char RX_char;

int main()
{

    PLL_Init();

    // UART7
    UART7_init();

    while (1)
    {
        UART7_TX('a');
    }

    return 0;
}

// -------------------------------------------


// -------------------------------------------
// UART5 -------------------------------------
#define UART5_CLK 80000000
#define UART5_BAUDRATE 9600
#define UART5_PE4_RX (1 << 4)
#define UART5_PE5_TX (1 << 5)

UART5_init(void)
{
    uint32_t dummy;
    // UART5 CLK
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R5;
    dummy = SYSCTL_RCGCUART_R;
    // PORTE clk
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
    dummy = SYSCTL_RCGCGPIO_R;

    // UART Config
    UART5_CTL_R = 0;
    UART5_IBRD_R = (int)(UART5_CLK / (16 * UART5_BAUDRATE));
    UART5_FBRD_R = (int)((((UART5_CLK / (16 * UART5_BAUDRATE)) - (int)(UART5_CLK / (16 * UART5_BAUDRATE))) * 64) + 0.5);
    UART5_CC_R = 0;
    UART5_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN); // 8bit + FIFO
    UART5_CTL_R |= (UART_CTL_TXE | UART_CTL_RXE | UART_CTL_UARTEN);

    // ENABLE AFSEL of PE4 PE5
    GPIO_PORTE_DEN_R |= (UART5_PE4_RX | UART5_PE5_TX);
    GPIO_PORTE_AFSEL_R |= (UART5_PE4_RX | UART5_PE5_TX);
    GPIO_PORTE_PCTL_R |= 0x00110000;
}

void UART5_TX(char data)
{
    while (UART5_FR_R & UART_FR_RXFF)
        ;
    UART5_DR_R = data;
}

char UART5_RX(void)
{
    while (UART5_FR_R & UART_FR_RXFE);
    return (char)UART5_DR_R;
}

// -------------------------------------------


// -------------------------------------------
// UART7 -------------------------------------
#define UART7_CLK 80000000
#define UART7_BAUDRATE 9600
#define UART7_PE0_RX (1 << 0)
#define UART7_PE1_TX (1 << 1)

void UART7_Init(void){
    uint32_t dummy;
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
    int i;
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
// -------------------------------------------

