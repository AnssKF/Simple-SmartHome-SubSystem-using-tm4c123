#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "MACROS.h"
#include "PLL.h"

#include "Port_Driver.h"
#include "DIO.h"

#include "UART0.h"
#include "UART5.h"

#include "delay.h"

#include "ADC.h"

#define TIVA    2

void SystemInit()
{
}


/** PWM */
#define GPIO_PF2_M	0x04

void PWM_Init(void){
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_3_LOAD_R = 1250 - 1; // 1KHz
	PWM1_3_CMPA_R = 1248; // 0% Duty Cycle
	PWM1_3_CTL_R = PWM_0_CTL_ENABLE;	
	GPIO_PORTF_AFSEL_R |= GPIO_PF2_M;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	GPIO_PORTF_DIR_R |= GPIO_PF2_M;
	GPIO_PORTF_DEN_R |= GPIO_PF2_M;
	PWM1_ENABLE_R = PWM_ENABLE_PWM6EN; // M1PWM6 (PF2)
}

// Duty cycle as percentage
void PWM_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle == 100){
		PWM1_3_CMPA_R = 1;
	} else if(duty_cycle == 0) {
		PWM1_3_CMPA_R = 1248;
	}else {
		PWM1_3_CMPA_R = (uint16_t)(1250 * (1 - (duty_cycle / 100.0)) - 1);
	}
}
/** ./PWM */

/** ADC -- PE3 */
#define ADC0_SS0_PRI 			0x3
#define ADC0_SS1_PRI 			(0x2 << 4)
#define ADC0_SS2_PRI 			(0x1 << 8)
#define ADC0_SS3_PRI 			(0x0 << 12)
#define ADC0_ACTSS_SS3 		0x8
#define ADC0_EMUX_SS3			(0x0 << 12) // Processor Trigger
#define ADC0_SSMUX3				0x0					// AIN0 (PE3)
#define ADC0_SSCTL3_IE0		(0x1 << 2)
#define ADC0_SSCTL3_END0	(0x1 << 1)
#define ADC0_PSSI_SS3			(0x1 << 3)
#define ADC0_RIS_INR3			(0x1 << 3)
#define GPIO_PE3_M				(0x1 << 3)
#define ADC_RESOLUTION	(3.3 / 4096)

void ADC0_Init(void){
	SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	ADC0_SSPRI_R = (ADC0_SS3_PRI | ADC0_SS2_PRI | ADC0_SS1_PRI | ADC0_SS0_PRI);
	ADC0_ACTSS_R &= ~ADC0_ACTSS_SS3;
	ADC0_EMUX_R = (ADC0_EMUX_R&0x0FFF) | ADC0_EMUX_SS3;
	ADC0_SSMUX3_R = ADC0_SSMUX3;
	ADC0_SSCTL3_R |= (ADC0_SSCTL3_IE0 | ADC0_SSCTL3_END0);
	ADC0_ACTSS_R |= ADC0_ACTSS_SS3;
	GPIO_PORTE_DIR_R &= ~GPIO_PE3_M;
	GPIO_PORTE_AFSEL_R |= GPIO_PE3_M;
  GPIO_PORTE_DEN_R &= ~GPIO_PE3_M;
  GPIO_PORTE_AMSEL_R |= GPIO_PE3_M;
}

void ADC0_SS3_In(uint16_t *data){
	ADC0_PSSI_R = ADC0_PSSI_SS3;
	while((ADC0_RIS_R&ADC0_RIS_INR3)!=ADC0_RIS_INR3);
	*data = ADC0_SSFIFO3_R&0xFFF;
	ADC0_ISC_R = ADC0_RIS_INR3;
}
/** ./ADC */

volatile uint8_t recieved_char;
volatile uint16_t AIN0_DValue;
volatile float	AIN0_AValue;

int main()
{
    PLL_Init();
    ADC0_Init();

    PWM_Init();

    while (1)
    {   
        ADC0_SS3_In(&AIN0_DValue); // get didital value of temp
		AIN0_AValue = AIN0_DValue * ADC_RESOLUTION; // analog value of temp

        PWM_SetDutyCycle((AIN0_AValue*100)/3.3); // map analog value between 0 - 100% duty cycle
    }
    

    return 0;
}