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
