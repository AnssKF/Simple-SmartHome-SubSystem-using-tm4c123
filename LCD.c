#include "LCD.h"
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

