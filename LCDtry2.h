



#include "delay.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Port_Driver.h"
#include "DIO.h"
//-----------------------test1pins----------------------
//used ports
#define RS                 PA5   
#define RW                 PA6   
#define E                  PA7   
#define Data_PORT          PORTB
#define CTRL_PORT          PORTA

//------------------------test2pins----------------------
/*
#define RS                 PE0   
#define RW                 PE1   
#define E                  PE2   
#define Data_PORT          PORTB
#define CTRL_PORT          PORTE

*/

//-----------------------------------------------

#define RW_WRITE           0x0
#define RW_READ            0x1

#define RS_COMMAND          0x0
#define RS_DATA             0x1


#define LCD_Control_reg_DIR GPIO_PORTA_DIR_R
#define LCD_Control_reg_OP  GPIO_PORTA_DATA_R

#define LCD_Data_Reg_DIR GPIO_PORTB_DIR_R
#define LCD_Data_Reg_OP	GPIO_PORTB_DATA_R

//commands

#define Clear_Display                   0x01
#define Display_ON_CURSOR_OFF           0x0C //1100
#define Display_ON_CURSOR_ON            0x0E
#define SET_CURSOR_LOCATION             0x80
#define Set_Two_Lines_Eight_Bits_Mode   0x38
#define increment_cursor                0x06               
#define decrement_cursor                0x04   

void LCD_Init (void);

void LCD_Send_instruction (uint8_t command);

void LCD_Display_Char (uint8_t data);

void LCD_Display_string (char * str);

void LCD_Coursor_Position (uint8_t row, uint8_t col);

void LCD_String_From_RowCOl (uint8_t row, uint8_t col,char * str);

void LCD_Display_Int(uint16_t data);

void LCD_Clear(void);

void _delay_ms(unsigned long msec);

char* itoa ( uint16_t num, char* str, uint8_t base ) ;



