#include "tm4c123gh6pm.h"
#include "PWM.h"

int main(){
	PWM_Pin_Init(PORTA, PWM_PA6,PWM_DEV_BY_2, PWM_HIGH_ON_LOAD_LOW_ON_MATCH, 0xFFFC);
	
	while(1){
		PWM_Write(PWM_PA6,50,0xFFFC);
	
	}

}