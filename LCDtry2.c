
#include "LCDtry2.h"


void LCD_Init (void)
{
	
	 Port_Init(CTRL_PORT);
	 Port_Init(Data_PORT);
	
	Port_SetPinDirection(CTRL_PORT,RS,PORT_PIN_OUT);
	Port_SetPinDirection(CTRL_PORT,RW,PORT_PIN_OUT);
	Port_SetPinDirection(CTRL_PORT,E,PORT_PIN_OUT);

	Port_SetPinDirection(Data_PORT,PB0,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB1,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB2,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB3,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB4,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB5,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB6,PORT_PIN_OUT);
	Port_SetPinDirection(Data_PORT,PB7,PORT_PIN_OUT);



    LCD_Send_instruction(Display_ON_CURSOR_OFF);
    LCD_Send_instruction(Set_Two_Lines_Eight_Bits_Mode);
    LCD_Send_instruction(Clear_Display);

}

void LCD_Send_instruction(uint8_t command) 
{
	 CLEAR_BIT(LCD_Control_reg_OP,RS);  
	 CLEAR_BIT(LCD_Control_reg_OP,RW);  
	
	 _delay_ms(1);
	
	
	SET_BIT(LCD_Control_reg_OP,E);
	_delay_ms(1); 
	
	LCD_Data_Reg_OP = command;
	
	_delay_ms(1); 
	CLEAR_BIT(LCD_Control_reg_OP,E);
	_delay_ms(1); 
}

void LCD_Display_Char(uint8_t data)
{
	SET_BIT(LCD_Control_reg_OP,RS);
	CLEAR_BIT(LCD_Control_reg_OP,RW);   

	
	_delay_ms(1);
	SET_BIT(LCD_Control_reg_OP,E);
	
	
	_delay_ms(1);
	LCD_Data_Reg_OP = data;
	
	_delay_ms(1);
	CLEAR_BIT(LCD_Control_reg_OP,E);
	_delay_ms(1);


	
}

void LCD_Clear(void)
{
    /* Clear Screen */
    LCD_Send_instruction(Clear_Display); 
}

void LCD_Coursor_Position_On_Display (uint8_t Row , uint8_t col)
{
	uint8_t Address=0;
	
	switch(Row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}
	LCD_Send_instruction(Address | SET_CURSOR_LOCATION); 
}

void LCD_Display_string(char * Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_Display_Char(Str[i]);
		i++;
	}
}

void LCD_String_From_RowCOl (uint8_t row, uint8_t col, char * str)
{
  LCD_Coursor_Position_On_Display (row,col); 
	LCD_Display_string (str);

}

char* itoa ( uint16_t num, char* str, uint8_t base ) 
{ 	uint8_t temp;
	uint8_t start;
    uint8_t end;

    int i = 0;  
  
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return 0; 
    } 
  
    while (num != 0) 
    { 
        uint16_t rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
    str[i] = '\0';  
	start = 0; 
    end = i - 1; 
		
    while (start < end) 
    { temp = *(str+start);
			*(str+start) = *(str+end);
			*(str+end) = temp;
			
		    start++; 
      end--; 
    }
 return 0;
} 


void LCD_Display_Int(uint16_t data)
{	
  char  buff[16];
  itoa(data,buff,10);
  LCD_Display_string(buff);
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


