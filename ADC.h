#ifndef ADC_H_
#define ADC_H_
#include "MACROS.h"
#include "Port_Driver.h"
#include "tm4c123gh6pm.h"


enum ADCn{ ADC0, ADC1 };

enum SEQn{ S0, S1, S2, S3 };


/*************************************************************** HIGH LEVEL FUNCTIONS ***************************************************************/

void ADC_Init( enum ADCn adcN, enum SEQn seqN, uint8_t SEQ_SEL_DIS_MUSK, uint32_t which_trigger, uint32_t CH_MUSK, uint32_t CTL_MUSK );// select ADCn, SEQn and PORT pins

void ADC_GPIO_PIN_CONFIG(uint32_t PIN_MUSK ,int port); /* initialize PORTE or A OR B to use their pins as channels */

void ADC0_SEQ_SEL_EN(uint32_t SEQ_SEL_EN_MUSK); // Enable the sequencer for ADC0 

void ADC1_SEQ_SEL_EN(uint32_t SEQ_SEL_EN_MUSK);// Enable the sequencer for ADC1 

void ADC0_TAKE_SAMPLE(uint8_t seq_musk);// Start a new conversion 

void ADC1_TAKE_SAMPLE(uint8_t seq_musk);// Start a new conversion 

float Tempreature_Value(uint32_t FIFOn); /* Get the Tempreature Value */


/*************************************************************** LOW LEVEL FUNCTIONS ***************************************************************/

void ADC_module(enum ADCn adcN ); //select which ADC

void ADC0_selec_DIS_SEQ(uint8_t SEQ_SEL_DIS_MUSK);//select seq for ADC0

void ADC1_selec_DIS_SEQ(uint8_t SEQ_SEL_DIS_MUSK);// select seq for ADC1

void ADC0_select_Trigger(uint32_t which_trigger);// Choose the software trigger for ADC0

void ADC1_select_Trigger(uint32_t which_trigger);// Choose the software trigger for ADC1

void ADC0_SEL_IN(uint32_t CH_MUSK, enum SEQn seqN); // Select ADC0 input , but if we not use it we should not use this function 

void ADC1_SEL_IN(uint32_t CH_MUSK,  enum SEQn seqN);// Select ADC1 input , but if we not use it we should not use this function 

void ADC0_SET_CTL(uint32_t CTL_MUSK, enum SEQn seqN); // Set ADC0 Control 

void ADC1_SET_CTL(uint32_t CTL_MUSK, enum SEQn seqN); // Set ADC1 Control 





#endif
