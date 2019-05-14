#include "LCD.h"

void LCD_init(void)
{		
	  /*Initialize used ports*/
		Port_Init (PORTA);
		Port_Init (PORTB);
	
	  /* Set The Control Pins Direction to PORT_PIN_OUT */
		Port_SetPinDirection(PORTA,(1<<RS),PORT_PIN_OUT);
		Port_SetPinDirection(PORTA,(1<<RW),PORT_PIN_OUT);
		Port_SetPinDirection(PORTA,(1<<E),PORT_PIN_OUT);
 	
		#if eight_bitdata
			/* Set the Direction of the 8 Data pins to PORT_PIN_OUT */
		Port_SetPinDirection(PORTB,(1<<D0),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D1),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D2),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D3),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D4),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D5),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D6),PORT_PIN_OUT);
		Port_SetPinDirection(PORTB,(1<<D7),PORT_PIN_OUT);
		#else
			
			#ifdef Upper_Data_port
				/* Set The Direction of The Upper Pins to OP*/
				Port_SetPinDirection(PORTB,(1<<D4),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D5),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D6),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D7),PORT_PIN_OUT);
			#else
				/* Set The Direction of The LOWER Pins to OP*/
				Port_SetPinDirection(PORTB,(1<<D0),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D1),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D2),PORT_PIN_OUT);
				Port_SetPinDirection(PORTB,(1<<D3),PORT_PIN_OUT);
			#endif
		Send_instruction(Return_Home);
		#endif
		
		Send_instruction(Data_Set);
		Send_instruction(Display_on);
		Send_instruction(Clear_display);
}

void Send_instruction(uint8_t instruction)
	{
		/* RW, RS Should be 0 when Writing instructions to LCD */
		CLEAR_BIT(LCD_Control_reg_OP,RS);
		CLEAR_BIT(LCD_Control_reg_OP,RW);
		/* Delay of Address Set 60ns minimum */
		_delay_ms(1);
		/* Enable LCD E=1 */
		SET_BIT(LCD_Control_reg_OP,E);
		/* delay for processing PW min 450ns */
		_delay_ms(1); 
		#if eight_bitdata
		
			LCD_Data_Reg_OP = instruction;
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1); 
			/* disable LCD E=0 */
			CLEAR_BIT(LCD_Control_reg_OP,E);
			/* Data Hold delay Th = 10ns */ 
			_delay_ms(1); 
		#else 
			
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				LCD_Data_Reg_OP |= (instruction & 0xF0);
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				LCD_Data_Reg_OP |= ((instruction >> 4) & 0x0f);
			#endif
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1);
			/* disable LCD E=0 */
			CLEAR_BIT(LCD_Control_reg_OP,E);
			/* Data Hold delay Th = 10ns */
			_delay_ms(1);
			/* Enable LCD E=1 */
			SET_BIT(LCD_Control_reg_OP,E);
			/* delay for processing PW min 450ns */
			_delay_ms(1);
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				LCD_Data_Reg_OP |= ((instruction <<4) & 0xF0);
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				LCD_Data_Reg_OP |= ((instruction) & 0x0f);
			#endif
				/* Data set-up time delay  Tdsw = 195 ns */
				_delay_ms(1);
				/* disable LCD E=0 */
				CLEAR_BIT(LCD_Control_reg_OP,E);
				/* Data Hold delay Th = 10ns */
				_delay_ms(1);
		#endif
	}

	void swap(char *x , char *y) 
{ 
    char temp = *x; 
    *x = *y; 
    *y = temp; 
} 

char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}


char* itoa(int value, char* buffer, int base)
{	
	int n;
	int i;
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
  n = abs(value);

  i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}

void LCD_DisplayFloat(float data)
{	
		int i;
		int dataint;
		char * result1, *result2;
		//char * result3 ;
		dataint = (int) data;
	  itoa(data, result1, 10); //get the integer part
	  strcat (result1, ".");                   //append decimal point
	  i = data - dataint;       //subtract to get the decimals, and multiply by 100, approximating to nearest two decimals
	  itoa(i, result2, 10);                  //convert to a second string
	  strcat(result1, result2);               //and append to the first
	  LCD_DisplayString(result1);              //Display result
}

void LCD_DisplayInt(uint8_t data)
{
		/* String to hold the ascii result */
		char Result[17]; 
		 /* 10 for decimal */
		itoa(data,Result,10);
		/* Display The Result */
		LCD_DisplayString(Result);
}

void LCD_DisplayChar(uint8_t Data)
{
		/* RW  Should be 0  and RS should be 1 when Writing Data to LCD */
		SET_BIT(LCD_Control_reg_OP,RS);
		CLEAR_BIT(LCD_Control_reg_OP,RW);
		/* Delay of Address Set 60ns minimum */
		_delay_ms(1);
		/* Enable LCD E=1 */
		SET_BIT(LCD_Control_reg_OP,E);
		/* delay for processing PW min 450ns */
		_delay_ms(1);
		#if eight_bitdata
			LCD_Data_Reg_OP=Data;
		#else
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				/* Send MSB (4-bits )*/
				LCD_Data_Reg_OP |= (Data & 0xF0);
			
			#else /* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				/* Send MSB (4-bits )*/
				LCD_Data_Reg_OP |= ((Data >> 4) & 0x0f);
			#endif
				
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1);
			/* disable LCD E=0 */
			CLEAR_BIT(LCD_Control_reg_OP,E);
			/* Data Hold delay Th = 10ns */
			_delay_ms(1);
			/* Enable LCD E=1 */
			SET_BIT(LCD_Control_reg_OP,E); 
				
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				LCD_Data_Reg_OP |= ((Data <<4) & 0xF0);
				/* delay for processing PW min 450ns */
				_delay_ms(1);
			#else	/* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				LCD_Data_Reg_OP |= ((Data) & 0x0f);
			#endif
			
			#endif
		/* Data set-up time delay  Tdsw = 195 ns */
		_delay_ms(1);
		/* disable LCD E=0 */
		CLEAR_BIT(LCD_Control_reg_OP,E);						
		/* Data Hold delay Th = 10ns */
		_delay_ms(1);
}
void LCD_DisplayString(char * ptr)
	{
		while(*ptr != '\0')
		{
			LCD_DisplayChar(*ptr);
			ptr++;
		}
	}

void LCD_Clear(void)
	{
		/* Clear Screen */
		Send_instruction(Clear_display); 
	}

void LCD_Select_RowCol(uint8_t Row , uint8_t col)
	{
		uint8_t Address=0;
		
		switch(Row)
		{
			case 0:
					/* When Writing To LCD 1st Col The Base Address is 0x00 */
						Address=col | LCD_1ST_BASE;
						break;
			case 1:
					/* When Writing To LCD 2nd Col The Base Address is 0x40 */
						Address=col | LCD_2ND_BASE;
						break;
			case 2:
					/* When Writing To LCD 1st Col The Base Address is 0x10 */
						Address = col | LCD_3RD_BASE;
						break;
			case 3:
					/* When Writing To LCD 1st Col The Base Address is 0x50 */
						Address=col| LCD_4TH_BASE;
						break;		
		}
		
		Send_instruction(DDRAM_CONST|Address);
	}
	
void _delay_ms(unsigned long msec) {
    unsigned long count; // declare count down variable
 
    while (msec) {
        count = 15913;   // 15913 for simulation and 11934 for the real board
 
        while (count) {
            count--;     // when counting down is finished, it takes 0.999875ms
        }
        msec--;          // count down the number of milliseconds you want
    }
}

