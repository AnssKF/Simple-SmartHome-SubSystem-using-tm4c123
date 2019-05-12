#include "ADC.h"
/**** steps
* Enable control clock to ADC and GPIO Module by choosing which ADC mode
* Choose & Disable the sample Sequencer
* Choose the software Trigger
* Select ADC INPUT or temperatur Sensor Mode
* Set ADC control
* if interrupt is used we will make a mask for it
* configuration GPIO
* Enable seq
* Start a new conversion
* WaiT & Read
* ****/
void ADC_Init( enum ADCn adcN, enum SEQn seqN, uint32_t SEQ_SEL_DIS_MUSK, uint32_t which_trigger, uint32_t CH_MUSK, uint32_t CTL_MUSK )
{
		ADC_module(adcN);
	if( adcN == 0 )
		{
			ADC0_selec_DIS_SEQ( SEQ_SEL_DIS_MUSK );
			ADC0_select_Trigger( which_trigger );
			ADC0_SEL_IN( CH_MUSK, seqN );
			ADC0_SET_CTL( CTL_MUSK, seqN );
		}
		else if(adcN == 1)
		{
			ADC1_selec_DIS_SEQ(SEQ_SEL_DIS_MUSK);
			ADC1_select_Trigger(which_trigger);
			ADC1_SEL_IN( CH_MUSK, seqN );
			ADC1_SET_CTL( CTL_MUSK, seqN );
		}
}


void ADC_module(enum ADCn adcN){
	//enable the clock of which ADC
	switch (adcN)
    { //switch case for defining which ADC
    case 0:
        SYSCTL_RCGCADC_R |= (1 << 0);
				 break;
		case 1:
				SYSCTL_RCGCADC_R |= (1 << 1);
				break;
		default :
			{
				 SYSCTL_RCGCADC_R |= (1 << 0);
				 SYSCTL_RCGCADC_R |= (1 << 1);
			}
			 break;
		}
		
}



void ADC0_SEQ_SEL_EN(uint32_t SEQ_SEL_EN_MUSK)
{ //enable the seq for ADC0
     ADC0_ACTSS_R |= SEQ_SEL_EN_MUSK; 
}    

void ADC1_SEQ_SEL_EN(uint32_t SEQ_SEL_EN_MUSK)
{ //enable the seq for ADC1
     ADC1_ACTSS_R |= SEQ_SEL_EN_MUSK;
}

void ADC0_SET_CTL(uint32_t CTL_MUSK, enum SEQn seqN)
	{
	switch (seqN)
  {
    case 0:
			ADC0_SSCTL0_R |= CTL_MUSK;
      break;
    case 1:
      ADC0_SSCTL1_R |= CTL_MUSK;
      break;
    case 2:
      ADC0_SSCTL2_R |= CTL_MUSK;
      break;
    case 3:
      ADC0_SSCTL3_R |= CTL_MUSK;
      break;
    }
}

void ADC1_SET_CTL(uint32_t CTL_MUSK, enum SEQn seqN)
	{
	switch (seqN)
  {
    case 0:
			ADC1_SSCTL0_R |= CTL_MUSK;
      break;
    case 1:
      ADC1_SSCTL1_R |= CTL_MUSK;
      break;
    case 2:
      ADC1_SSCTL2_R |= CTL_MUSK;
      break;
    case 3:
      ADC1_SSCTL3_R |= CTL_MUSK;
      break;
    }
}

void ADC_GPIO_PIN_CONFIG(uint32_t PIN_MUSK ,int port){
	switch(port) 
		{
			case 1:
				{ //port B
					GPIO_PORTB_AFSEL_R |=PIN_MUSK;//enable alternating function
					GPIO_PORTB_DEN_R &=~PIN_MUSK; //diable digital mode
					GPIO_PORTB_AMSEL_R |= PIN_MUSK; //enable analog function
				}
				break;
			case 3:
				{//port D
				GPIO_PORTD_AFSEL_R |=PIN_MUSK;//enable alternating function
				GPIO_PORTD_DEN_R &=~PIN_MUSK; //diable digital mode
				GPIO_PORTD_AMSEL_R |= PIN_MUSK; //enable analog function
				}
				break;
			case 4:
				{ //port E
				GPIO_PORTE_AFSEL_R |=PIN_MUSK;//enable alternating function
				GPIO_PORTE_DEN_R &=~PIN_MUSK; //diable digital mode
				GPIO_PORTE_AMSEL_R |= PIN_MUSK; //enable analog function
				}
				break;
	}
}


void ADC0_TAKE_SAMPLE(uint32_t seq_musk)   
{/* Start a new conversion */
			ADC0_PSSI_R |= seq_musk;
}

void ADC1_TAKE_SAMPLE(uint32_t seq_musk)
{/* Start a new conversion */
	
	ADC1_PSSI_R |= seq_musk;
}
