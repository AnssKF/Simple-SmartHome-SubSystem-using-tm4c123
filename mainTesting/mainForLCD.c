#include "LCDtry2.h"


void SystemInit (void)
{
	
}

int main(){
    uint8_t Address=0;
    uint8_t data =0x41;


    LCD_Init();
    LCD_Send_instruction(Clear_Display);
    while (1)
    {
        LCD_Send_instruction(Address | SET_CURSOR_LOCATION);
        LCD_Display_Char(data);
    }
    

}