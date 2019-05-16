#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "MACROS.h"
#include "Port_Driver.h"
#include "DIO.h"
#include "delay.h"
#include "ADC.h"
#include "LCD.h"
#include "PLL.h"
#include "PWM.h"
#include "UART0.h"
#include "UART5.h"

// ADC def ----------------------------
#define ADCn ADC0
#define SEQn S3
#define SEQ_SEL_DIS_MUSK 0x08 //disable S3
#define which_trigger 0x00 // Processor trigger 
#define CH_MUSK 0x00 // Input from channal 0 ( PE3 )
#define CTL_MUSK 0x04 // bit0->Not diff(0) , bit1-> sample cont.(0) ,bit2-> set flag(1) , bit3-> accept from ch.(0) // 0100   
#define PORTn PORTE
#define input_Pin 0x08
#define seq_musk_enable 0x08
#define transaction 0x08
#define Reg_val ADC0_SSFIFO3_R




#define TIVA 1

void SystemInit() {}

volatile char rx_char;
volatile uint8_t temp_value;
volatile uint8_t pot_value;

int main()
{
    PLL_Init();
    UART5_Init();

    while (1)
    {
        if (TIVA == 1)
        {
            // Push btns
            Port_Init(PORTF);
            Port_SetPinDirection(PORTF, (PF0 | PF4), PORT_PIN_OUT);
            Port_SetPinPullUp(PORTF, (PF0 | PF4), 1);

            ADC_Init( ADCn ,  SEQn , SEQ_SEL_DIS_MUSK , which_trigger , CH_MUSK, CTL_MUSK );
            ADC_GPIO_PIN_CONFIG(input_Pin ,PORTn);
            ADC0_SEQ_SEL_EN(seq_musk_enable);

            while (1)
            {
                if (!DIO_ReadPort(PORTF, PF0))
                {
                    // PF0 pressed
                    UART5_Write('A');
                }
                else if(!DIO_ReadPort(PORTF, PF0)) 
                {
                    // PF4 pressed
                    UART5_Write('B');
                }

                // POT value send ----------
                // pot adc read
                // pot_value = 1;
                // UART5_Write('P');
                // UART5_Write(pot_value);

                // Temp value send ----------
                ADC0_TAKE_SAMPLE(transaction);
                temp_value = Tempreature_Value(Reg_val);
                UART5_Write('T');
                UART5_Write(temp_value);

            }
        }
        else if (TIVA == 2)
        {
            PWM_Pin_Init(PORTC, PWM_PC4, PWM_DEV_BY_64, High_on_Load_Low_Match, (1250 - 1));
            LCD_init();

            while (1)
            {
                rx_char = UART5_Read();

                if(rx_char == 'A')
                {
                    // SERVO CW
                }

                else if(rx_char == 'B')
                {
                    // SERVO CCW
                }

                else if(rx_char == 'T')
                {
                    temp_value = UART5_Read();
                    // LCD
                    LCD_DisplayChar(temp_value);
                }

                else if(rx_char == 'P')
                {
                    pot_value = UART5_Read();
                    // LED PWM -- max pot value is 3.3 min value is 0
                    PWM_Write(PWM_PC4, ((pot_value*100)/3.3));
                }
            }
        }
    }

    return 0;
}