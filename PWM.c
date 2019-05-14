#include "PWM.h"

void PWM_Pin_Init(uint8_t port_index, PWM_PIN pwm_pin, PWM_DEVIDER pwm_devider, PWM_OUTPUT_STATE pwm_output_state, uint16_t load_value)
{

    // Initialize port
    Port_Init(port_index);

    switch (pwm_pin)
    {
        // ? PORT A
    case (PWM_PA6):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTA_AFSEL_R, PA6);
        SET_MASK(GPIO_PORTA_PCTL_R, GPIO_PA6_PCTL_PWM_MODULE1_GEN1_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G1_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PA7):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTA_AFSEL_R, PA7);
        SET_MASK(GPIO_PORTA_PCTL_R, GPIO_PA7_PCTL_PWM_MODULE1_GEN1_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G1_B, pwm_devider, pwm_output_state, load_value);
        break;

        // ? PORT B
    case (PWM_PB4):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTB_AFSEL_R, PB4);
        SET_MASK(GPIO_PORTB_PCTL_R, GPIO_PB4_PCTL_PWM_MODULE0_GEN1_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G1_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PB5):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTB_AFSEL_R, PB5);
        SET_MASK(GPIO_PORTB_PCTL_R, GPIO_PB5_PCTL_PWM_MODULE0_GEN1_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G1_B, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PB6):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTB_AFSEL_R, PB6);
        SET_MASK(GPIO_PORTB_PCTL_R, GPIO_PB6_PCTL_PWM_MODULE0_GEN0_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G0_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PB7):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTB_AFSEL_R, PB7);
        SET_MASK(GPIO_PORTB_PCTL_R, GPIO_PB7_PCTL_PWM_MODULE0_GEN0_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G0_B, pwm_devider, pwm_output_state, load_value);
        break;

        // ? PORT C
    case (PWM_PC4):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTC_AFSEL_R, PC4);
        SET_MASK(GPIO_PORTC_PCTL_R, GPIO_PC4_PCTL_PWM_MODULE0_GEN3_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G3_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PC5):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTC_AFSEL_R, PC5);
        SET_MASK(GPIO_PORTC_PCTL_R, GPIO_PC5_PCTL_PWM_MODULE0_GEN3_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G3_B, pwm_devider, pwm_output_state, load_value);
        break;

        // ? PORT D
    case (PWM_PD0_M0):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTD_AFSEL_R, PD0);
        SET_MASK(GPIO_PORTD_PCTL_R, GPIO_PD0_PCTL_PWM_MODULE0_GEN3_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G3_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PD0_M1):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTD_AFSEL_R, PD0);
        SET_MASK(GPIO_PORTD_PCTL_R, GPIO_PD0_PCTL_PWM_MODULE1_GEN0_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G0_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PD1_M0):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTD_AFSEL_R, PD1);
        SET_MASK(GPIO_PORTD_PCTL_R, GPIO_PD1_PCTL_PWM_MODULE0_GEN3_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G3_B, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PD1_M1):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTD_AFSEL_R, PD1);
        SET_MASK(GPIO_PORTD_PCTL_R, GPIO_PD1_PCTL_PWM_MODULE1_GEN0_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G0_B, pwm_devider, pwm_output_state, load_value);
        break;

        // ? PORT E
    case (PWM_PE4_M0):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTE_AFSEL_R, PE4);
        SET_MASK(GPIO_PORTE_PCTL_R, GPIO_PE4_PCTL_PWM_MODULE0_GEN2_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G2_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PE4_M1):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTE_AFSEL_R, PE4);
        SET_MASK(GPIO_PORTE_PCTL_R, GPIO_PE4_PCTL_PWM_MODULE1_GEN1_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G1_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PE5_M0):
        // SET Alternative function for this pin to be PWM
        SET_MASK(GPIO_PORTE_AFSEL_R, PE5);
        SET_MASK(GPIO_PORTE_PCTL_R, GPIO_PE5_PCTL_PWM_MODULE0_GEN2_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M0, PWM_G2_B, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PE5_M1):
        SET_MASK(GPIO_PORTE_AFSEL_R, PE5);
        SET_MASK(GPIO_PORTE_PCTL_R, GPIO_PE5_PCTL_PWM_MODULE1_GEN1_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G1_B, pwm_devider, pwm_output_state, load_value);
        break;

        // ? PORT F
    case (PWM_PF0):
        SET_MASK(GPIO_PORTF_AFSEL_R, PF0);
        SET_MASK(GPIO_PORTF_PCTL_R, GPIO_PF0_PCTL_PWM_MODULE1_GEN2_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G2_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PF1):
        SET_MASK(GPIO_PORTF_AFSEL_R, PF1);
        SET_MASK(GPIO_PORTF_PCTL_R, GPIO_PF1_PCTL_PWM_MODULE1_GEN2_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G2_B, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PF2):
        SET_MASK(GPIO_PORTF_AFSEL_R, PF2);
        SET_MASK(GPIO_PORTF_PCTL_R, GPIO_PF2_PCTL_PWM_MODULE1_GEN3_A_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G3_A, pwm_devider, pwm_output_state, load_value);
        break;
    case (PWM_PF3):
        SET_MASK(GPIO_PORTF_AFSEL_R, PF3);
        SET_MASK(GPIO_PORTF_PCTL_R, GPIO_PF3_PCTL_PWM_MODULE1_GEN3_B_M);

        // Init PWM generator for this pin
        PWM_Gen_Init(PWM_M1, PWM_G3_B, pwm_devider, pwm_output_state, load_value);
        break;

    default:
        break;
    }
}

void PWM_Gen_Init(PWM_MODULE pwm_module, PWM_GEN pwn_generator, PWM_DEVIDER pwm_devider, PWM_OUTPUT_STATE pwm_output_state, uint16_t load_value)
{
    SET_MASK(SYSCTL_RCGC0_R, 0x100000); //run mode clock ->pwm

    SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_EN_M);
    switch (pwm_devider)
    {
    case PWM_DEV_BY_2:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_2_M);
        break;
    case PWM_DEV_BY_4:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_4_M);
        break;
    case PWM_DEV_BY_8:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_8_M);
        break;
    case PWM_DEV_BY_16:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_16_M);
        break;
    case PWM_DEV_BY_32:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_32_M);
        break;
    case PWM_DEV_BY_64:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_64_M);
        break;

    default:
        SET_MASK(PWM_CLK_DEVIDER_CTL_R, PWM_CLK_DEVIDER_BY_64_M);
        break;
    }

    switch (pwm_module)
    {
    case PWM_M0:
        SET_MASK(PWM_SYSCTL_R, PWM_MODULE0_CLK_EN_M);
        switch (pwn_generator)
        {
        case PWM_G0_A:
            SET_MASK(PWM_MODULE0_GEN0_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN0_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN0_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN0_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN0_CTL_R, PWM_GEN0_CTL_EN_M);
            break;
        case PWM_G0_B:
            SET_MASK(PWM_MODULE0_GEN0_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN0_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN0_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN0_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN0_CTL_R, PWM_GEN0_CTL_EN_M);
            break;

        case PWM_G1_A:
            SET_MASK(PWM_MODULE0_GEN1_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN1_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN1_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN1_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN1_CTL_R, PWM_GEN1_CTL_EN_M);
            break;
        case PWM_G1_B:
            SET_MASK(PWM_MODULE0_GEN1_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN1_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN1_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN1_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN1_CTL_R, PWM_GEN1_CTL_EN_M);
            break;
        case PWM_G2_A:
            SET_MASK(PWM_MODULE0_GEN2_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN2_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN2_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN2_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN2_CTL_R, PWM_GEN2_CTL_EN_M);
            break;
        case PWM_G2_B:
            SET_MASK(PWM_MODULE0_GEN2_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN2_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN2_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN2_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN2_CTL_R, PWM_GEN2_CTL_EN_M);
            break;
        case PWM_G3_A:
            SET_MASK(PWM_MODULE0_GEN3_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN3_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN3_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN3_LOAD_R, load_value);
            break;
        case PWM_G3_B:
            SET_MASK(PWM_MODULE0_GEN3_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN3_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE0_GEN3_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE0_GEN3_LOAD_R, load_value);
            SET_MASK(PWM_MODULE0_GEN3_CTL_R, PWM_GEN3_CTL_EN_M);
            break;

        default:
            break;
        }
        break;

    case PWM_M1:
        SET_MASK(PWM_SYSCTL_R, PWM_MODULE1_CLK_EN_M);
        switch (pwn_generator)
        {
        case PWM_G0_A:
            SET_MASK(PWM_MODULE1_GEN0_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN0_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN0_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN0_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN0_CTL_R, PWM_GEN0_CTL_EN_M);
            break;
        case PWM_G0_B:
            SET_MASK(PWM_MODULE1_GEN0_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN0_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN0_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN0_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN0_CTL_R, PWM_GEN0_CTL_EN_M);
            break;

        case PWM_G1_A:
            SET_MASK(PWM_MODULE1_GEN1_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN1_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN1_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN1_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN1_CTL_R, PWM_GEN1_CTL_EN_M);
            break;
        case PWM_G1_B:
            SET_MASK(PWM_MODULE1_GEN1_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN1_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN1_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN1_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN1_CTL_R, PWM_GEN1_CTL_EN_M);
            break;
        case PWM_G2_A:
            SET_MASK(PWM_MODULE1_GEN2_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN2_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN2_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN2_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN2_CTL_R, PWM_GEN2_CTL_EN_M);
            break;
        case PWM_G2_B:
            SET_MASK(PWM_MODULE1_GEN2_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN2_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN2_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN2_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN2_CTL_R, PWM_GEN2_CTL_EN_M);
            break;
        case PWM_G3_A:
            SET_MASK(PWM_MODULE1_GEN3_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN3_A_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN3_A_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN3_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN3_CTL_R, PWM_GEN3_CTL_EN_M);
            break;
        case PWM_G3_B:
            SET_MASK(PWM_MODULE1_GEN3_CTL_R, 0x0);
            switch (pwm_output_state)
            {
            case PWM_HIGH_ON_LOAD_LOW_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN3_B_CTL_R, High_on_Load_Low_Match);
                break;
            case PWM_LOW_ON_LOAD_HIGH_ON_MATCH:
                SET_MASK(PWM_MODULE1_GEN3_B_CTL_R, Low_on_Load_High_Match);
                break;

            default:
                break;
            }
            SET_MASK(PWM_MODULE1_GEN3_LOAD_R, load_value);
            SET_MASK(PWM_MODULE1_GEN3_CTL_R, PWM_GEN3_CTL_EN_M);
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}


//duty_cycle in percentage

void PWM_Write(PWM_PIN pwm_pin,uint16_t duty_cycle,uint16_t load_value)
{
    if(pwm_pin==PWM_PA6)
    {
      PWM_MODULE1_GEN1_LOAD_R=load_value;  
     
        if(duty_cycle==100)
        {
         PWM_MODULE1_GEN1_CMPA_R=1;//100%//max
        }
        else if(duty_cycle==0)
        {
         PWM_MODULE1_GEN1_CMPA_R=load_value-1;//0%//min
        }
        else
        {
            PWM_MODULE1_GEN1_CMPA_R=(uint32_t)(load_value*((1-duty_cycle/100.0))-1);
        }
    }

    else if(pwm_pin==PWM_PA7)
    {
        PWM_MODULE1_GEN1_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN1_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN1_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN1_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else if(pwm_pin==PWM_PB4)
    {
        PWM_MODULE0_GEN1_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN1_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN1_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN1_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PB5)
    {
        PWM_MODULE0_GEN1_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN1_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN1_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN1_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PB6)
    {
        PWM_MODULE0_GEN0_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN0_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN0_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN0_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PB7)
    {
        PWM_MODULE0_GEN0_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN0_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN0_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN0_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PC4)
    {
        PWM_MODULE0_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN3_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PC5)
    {
        PWM_MODULE0_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN3_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else if(pwm_pin==PWM_PD0_M0)
    {
        PWM_MODULE0_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN3_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else if(pwm_pin==PWM_PD0_M1)
    {
        PWM_MODULE1_GEN0_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN0_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN0_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN0_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else if(pwm_pin==PWM_PD1_M0)
    {
        PWM_MODULE0_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN3_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PD1_M1)
    {
        PWM_MODULE1_GEN0_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN0_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN0_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN0_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PE4_M0)
    {
        PWM_MODULE0_GEN2_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN2_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN2_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN2_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin== PWM_PE4_M1)
    {
        PWM_MODULE1_GEN1_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN1_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN1_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN1_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin== PWM_PE5_M0)
    {
        PWM_MODULE0_GEN2_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE0_GEN2_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE0_GEN2_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE0_GEN2_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PE5_M1)
    {
        PWM_MODULE1_GEN1_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN1_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN1_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN1_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
      else  if(pwm_pin==PWM_PF0)
    {
        PWM_MODULE1_GEN2_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN2_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN2_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN2_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PF1)
    {
        PWM_MODULE1_GEN2_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN2_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN2_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN2_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PF2)
    {
        PWM_MODULE1_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
         PWM_MODULE1_GEN3_CMPA_R=1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
    else  if(pwm_pin==PWM_PF3)
    {
        PWM_MODULE1_GEN3_LOAD_R=load_value; 
      if(duty_cycle==100)
      {
        PWM_MODULE1_GEN3_CMPA_R =1;
      }
      else if(duty_cycle==0)
      {
         PWM_MODULE1_GEN3_CMPA_R=load_value-1;
      }
      else
      {
         PWM_MODULE1_GEN3_CMPA_R=(uint32_t)(load_value*(duty_cycle/100.0)-1);
      }
    }
}





