#include <stdint.h>
#include "UART.h"
#include "../inc/tm4c123gh6pm.h"


#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit word length
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_CTL_UARTEN         0x00000001  // UART Enable


//------------UART_Init------------
// Initialize the UART for 115,200 baud rate (assuming 50 MHz UART clock),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// Input: none
// Output: none
void UART_Init(void) {
	SYSCTL_RCGCUART_R |= 0x01;            // activate UART0
	SYSCTL_RCGCGPIO_R |= 0x01;            // activate port A
	while ((SYSCTL_PRGPIO_R & 0x01) == 0) {};
	UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
	UART0_IBRD_R = 27;                    // IBRD = int(50,000,000 / (16 * 115,200)) = int(27.1267)
	UART0_FBRD_R = 8;                     // FBRD = int(0.1267 * 64 + 0.5) = 8
										  // 8 bit word length (no parity bits, one stop bit, FIFOs)
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R |= 0x301;                 // enable UART
	GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
	GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
										  // configure PA1-0 as UART
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) + 0x00000011;
	GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA
}

//------------UART_InChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
char UART_InChar(void) {
	while ((UART0_FR_R & UART_FR_RXFE) != 0);
	return((char)(UART0_DR_R & 0xFF));
}
//------------UART_OutChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART_OutChar(char data) {
	while ((UART0_FR_R & UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}


//------------UART_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void UART_OutString(char* pt) {
	while (*pt) {
		UART_OutChar(*pt);
		pt++;
	}
}

//------------UART_InUDec------------
// InUDec accepts ASCII input in unsigned decimal format
//     and converts to a 32-bit unsigned number
//     valid range is 0 to 4294967295 (2^32-1)
// Input: none
// Output: 32-bit unsigned number
// If you enter a number above 4294967295, it will return an incorrect value
// Backspace will remove last digit typed
uint32_t UART_InUDec(void) {
	uint32_t number = 0, length = 0;
	char character;
	character = UART_InChar();
	while (character != CR) { // accepts until <enter> is typed
  // The next line checks that the input is a digit, 0-9.
  // If the character is not 0-9, it is ignored and not echoed
		if ((character >= '0') && (character <= '9')) {
			number = 10 * number + (character - '0');   // this line overflows if above 4294967295
			length++;
			UART_OutChar(character);
		}
		// If the input is a backspace, then the return number is
		// changed and a backspace is outputted to the screen
		else if ((character == BS) && length) {
			number /= 10;
			length--;
			UART_OutChar(character);
		}
		character = UART_InChar();
	}
	return number;
}
