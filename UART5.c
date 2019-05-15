#include "uart.h"

#include "DIO.h"

void UART5_Init(void){
	SYSCTL_RCGCUART_R |= 0x20; //provide clock to uart5
	SYSCTL_RCGCGPIO_R |= 0x10; //enable clock to PORTE
	//UART5 initialaization
	UART0_CTL_R =0; //disable UART5
	UART0_IBRD_R = 520;    //int (80MHZ/16*9600)
    UART0_FBRD_R = 53;     
	// UART0_IBRD_R = 104;    
    // UART0_FBRD_R = 11;
	UART0_CC_R = 0;   //enable system clock as uart clock 
	UART0_LCRH_R = 0x70; //no parity,enable FIFO,width=8bit,1-stop bit
    UART5_CTL_R=0x301; //enable UART5,TXE and RXE
  //GPIO config
    GPIO_PORTE_AMSEL_R=0;    //disable analog function 
    GPIO_PORTE_AFSEL_R=0x30; //use PE5 and PE4 alternate function 
    GPIO_PORTE_PCTL_R=0x00110000; //configure PE%,PE4 fot UART5
    GPIO_PORTE_DEN_R=0x30;    // make PE5,PE4 as digital
}

uint8_t UART5_Available(void){
	return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART5_Read(void){
	while(UART5_Available() != 1);     //wait untill RXFE=0 (FIFO full)
	return (uint8_t)(UART5_DR_R&0xFF); //retrun data (first 8-bit)
}

void UART5_Write(uint8_t data){
	while((UART5_FR_R&UART_FR_TXFF) == 1);
	UART5_DR_R = data;

	DIO_WritePort(PORTB,PB2,STD_HIGH);
}
void UART5_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART5_Write(Str[i]);
		i++;
	}
}
void UART5_receiveString(uint8_t *Str)

{
	uint8_t i = 0;
	Str[i] = UART5_Read();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART5_Read();
	}
	Str[i] = '\0';
}
