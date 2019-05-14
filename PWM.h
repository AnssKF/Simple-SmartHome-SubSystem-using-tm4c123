/**
 * PWM Driver
 * 
 * 
 * We have 2 modules MODULE0/1 each module contain 4 generators each generator can drive 2 PWM signals
 * 
 * */

#ifndef _PWM_H_
#define _PWM_H_

    #include <stdint.h>
    #include "tm4c123gh6pm.h"

    #include "Port_Driver.h"

    /** Regidter mapping **/

    // CLK enable
    #define PWM_SYSCTL_R                                SYSCTL_RCGCPWM_R
    #define PWM_MODULE0_CLK_EN_M                        SYSCTL_RCGCPWM_R0
    #define PWM_MODULE1_CLK_EN_M                        SYSCTL_RCGCPWM_R1

    // Module enable
    #define PWM_MODULE0_GEN0_CTL_R                      PWM0_0_CTL_R
    #define PWM_MODULE0_GEN1_CTL_R                      PWM0_1_CTL_R
    #define PWM_MODULE0_GEN2_CTL_R                      PWM0_2_CTL_R
    #define PWM_MODULE0_GEN3_CTL_R                      PWM0_3_CTL_R
    
    #define PWM_MODULE1_GEN0_CTL_R                      PWM1_0_CTL_R
    #define PWM_MODULE1_GEN1_CTL_R                      PWM1_1_CTL_R
    #define PWM_MODULE1_GEN2_CTL_R                      PWM1_2_CTL_R
    #define PWM_MODULE1_GEN3_CTL_R                      PWM1_3_CTL_R

    #define PWM_GEN0_CTL_EN_M                           PWM_0_CTL_ENABLE
    #define PWM_GEN1_CTL_EN_M                           PWM_1_CTL_ENABLE
    #define PWM_GEN2_CTL_EN_M                           PWM_2_CTL_ENABLE
    #define PWM_GEN3_CTL_EN_M                           PWM_3_CTL_ENABLE


    // Output Enable    -- mask valid for module 0 or 1
    #define PWM_MODULE0_EN_R                            PWM0_ENABLE_R
    #define PWM_MODULE1_EN_R                            PWM1_ENABLE_R

    #define PWM_GEN0_A_EN_M                             0x01
    #define PWM_GEN0_B_EN_M                             0x02
    #define PWM_GEN1_A_EN_M                             0x04
    #define PWM_GEN1_B_EN_M                             0x08
    #define PWM_GEN2_A_EN_M                             0x10
    #define PWM_GEN2_B_EN_M                             0x20
    #define PWM_GEN3_A_EN_M                             0x40
    #define PWM_GEN3_B_EN_M                             0x80
    
    // CLK devider
    #define PWM_CLK_DEVIDER_CTL_R                       SYSCTL_RCC_R
    #define PWM_CLK_DEVIDER_EN_M                        SYSCTL_RCC_USEPWMDIV
    #define PWM_CLK_DEVIDER_BY_2_M                      SYSCTL_RCC_PWMDIV_2
    #define PWM_CLK_DEVIDER_BY_4_M                      SYSCTL_RCC_PWMDIV_4
    #define PWM_CLK_DEVIDER_BY_8_M                      SYSCTL_RCC_PWMDIV_8
    #define PWM_CLK_DEVIDER_BY_16_M                     SYSCTL_RCC_PWMDIV_16
    #define PWM_CLK_DEVIDER_BY_32_M                     SYSCTL_RCC_PWMDIV_32
    #define PWM_CLK_DEVIDER_BY_64_M                     SYSCTL_RCC_PWMDIV_64


    //Generator Control 0x0 Do nothing. 0x1 Invert pwmB. 0x2 Drive pwmB Low. 0x3 Drive pwmB High.
    #define PWM_MODULE0_GEN0_A_CTL_R                 PWM0_0_GENA_R
    #define PWM_MODULE0_GEN0_B_CTL_R                 PWM0_0_GENB_R

    #define PWM_MODULE0_GEN1_A_CTL_R                 PWM0_1_GENA_R
    #define PWM_MODULE0_GEN1_B_CTL_R                 PWM0_1_GENB_R

    #define PWM_MODULE0_GEN2_A_CTL_R                 PWM0_2_GENA_R
    #define PWM_MODULE0_GEN2_B_CTL_R                 PWM0_2_GENB_R

    #define PWM_MODULE0_GEN3_A_CTL_R                 PWM0_3_GENA_R
    #define PWM_MODULE0_GEN3_B_CTL_R                 PWM0_3_GENB_R
    
    #define PWM_MODULE1_GEN0_A_CTL_R                 PWM1_0_GENA_R
    #define PWM_MODULE1_GEN0_B_CTL_R                 PWM1_0_GENB_R

    #define PWM_MODULE1_GEN1_A_CTL_R                 PWM1_1_GENA_R
    #define PWM_MODULE1_GEN1_B_CTL_R                 PWM1_1_GENB_R

    #define PWM_MODULE1_GEN2_A_CTL_R                 PWM1_2_GENA_R
    #define PWM_MODULE1_GEN2_B_CTL_R                 PWM1_2_GENB_R

    #define PWM_MODULE1_GEN3_A_CTL_R                 PWM1_3_GENA_R
    #define PWM_MODULE1_GEN3_B_CTL_R                 PWM1_3_GENB_R

    #define PWM_GEN_CTL_DONOTHING_M                     0x0 // Do nothing
    #define PWM_GEN_CTL_INVERT_M                        0x1 // Invert PWM
    #define PWM_GEN_CTL_DRIVE_LOW_M                     0x2 // Drive Low
    #define PWM_GEN_CTL_DRIVE_HIGH_M                    0x3 // Drive High
    //register values
    #define High_on_Load_Low_Match                      0x8D
    #define Low_on_Load_High_Match                      0xD8 //not sure :'

    // Load reg
    #define PWM_MODULE0_GEN0_LOAD_R                     PWM0_0_LOAD_R
    #define PWM_MODULE0_GEN1_LOAD_R                     PWM0_1_LOAD_R
    #define PWM_MODULE0_GEN2_LOAD_R                     PWM0_2_LOAD_R
    #define PWM_MODULE0_GEN3_LOAD_R                     PWM0_3_LOAD_R

    #define PWM_MODULE1_GEN0_LOAD_R                     PWM1_0_LOAD_R
    #define PWM_MODULE1_GEN1_LOAD_R                     PWM1_1_LOAD_R
    #define PWM_MODULE1_GEN2_LOAD_R                     PWM1_2_LOAD_R
    #define PWM_MODULE1_GEN3_LOAD_R                     PWM1_3_LOAD_R

    // Compare reg          
    #define PWM_MODULE0_GEN0_CMPA_R                     PWM0_0_CMPA_R
    #define PWM_MODULE0_GEN0_CMPB_R                     PWM0_0_CMPB_R

    #define PWM_MODULE0_GEN1_CMPA_R                     PWM0_1_CMPA_R
    #define PWM_MODULE0_GEN1_CMPB_R                     PWM0_1_CMPB_R

    #define PWM_MODULE0_GEN2_CMPA_R                     PWM0_2_CMPA_R
    #define PWM_MODULE0_GEN2_CMPB_R                     PWM0_2_CMPB_R

    #define PWM_MODULE0_GEN3_CMPA_R                     PWM0_3_CMPA_R
    #define PWM_MODULE0_GEN3_CMPB_R                     PWM0_3_CMPB_R

    #define PWM_MODULE1_GEN0_CMPA_R                     PWM1_0_CMPA_R
    #define PWM_MODULE1_GEN0_CMPB_R                     PWM1_0_CMPB_R

    #define PWM_MODULE1_GEN1_CMPA_R                     PWM1_1_CMPA_R
    #define PWM_MODULE1_GEN1_CMPB_R                     PWM1_1_CMPB_R

    #define PWM_MODULE1_GEN2_CMPA_R                     PWM1_2_CMPA_R
    #define PWM_MODULE1_GEN2_CMPB_R                     PWM1_2_CMPB_R

    #define PWM_MODULE1_GEN3_CMPA_R                     PWM1_3_CMPA_R
    #define PWM_MODULE1_GEN3_CMPB_R                     PWM1_3_CMPB_R


    // GPIO - All Valid PWM pins
    #define GPIO_PA6_PCTL_PWM_MODULE1_GEN1_A_M          GPIO_PCTL_PA6_M1PWM2
    #define GPIO_PA7_PCTL_PWM_MODULE1_GEN1_B_M          GPIO_PCTL_PA7_M1PWM3

    #define GPIO_PB4_PCTL_PWM_MODULE0_GEN1_A_M          GPIO_PCTL_PB4_M0PWM2
    #define GPIO_PB5_PCTL_PWM_MODULE0_GEN1_B_M          GPIO_PCTL_PB5_M0PWM3
    #define GPIO_PB6_PCTL_PWM_MODULE0_GEN0_A_M          GPIO_PCTL_PB6_M0PWM0
    #define GPIO_PB7_PCTL_PWM_MODULE0_GEN0_B_M          GPIO_PCTL_PB7_M0PWM1

    #define GPIO_PC4_PCTL_PWM_MODULE0_GEN3_A_M          GPIO_PCTL_PC4_M0PWM6
    #define GPIO_PC5_PCTL_PWM_MODULE0_GEN3_B_M          GPIO_PCTL_PC5_M0PWM7

    #define GPIO_PD0_PCTL_PWM_MODULE0_GEN3_A_M          GPIO_PCTL_PD0_M0PWM6
    #define GPIO_PD0_PCTL_PWM_MODULE1_GEN0_A_M          GPIO_PCTL_PD0_M1PWM0
    #define GPIO_PD1_PCTL_PWM_MODULE0_GEN3_B_M          GPIO_PCTL_PD1_M0PWM7
    #define GPIO_PD1_PCTL_PWM_MODULE1_GEN0_B_M          GPIO_PCTL_PD1_M1PWM1

    #define GPIO_PE4_PCTL_PWM_MODULE0_GEN2_A_M          GPIO_PCTL_PE4_M0PWM4
    #define GPIO_PE4_PCTL_PWM_MODULE1_GEN1_A_M          GPIO_PCTL_PE4_M1PWM2
    #define GPIO_PE5_PCTL_PWM_MODULE0_GEN2_B_M          GPIO_PCTL_PE5_M0PWM5
    #define GPIO_PE5_PCTL_PWM_MODULE1_GEN1_B_M          GPIO_PCTL_PE5_M1PWM3

    #define GPIO_PF0_PCTL_PWM_MODULE1_GEN2_A_M          GPIO_PCTL_PF0_M1PWM4
    #define GPIO_PF1_PCTL_PWM_MODULE1_GEN2_B_M          GPIO_PCTL_PF1_M1PWM5
    #define GPIO_PF2_PCTL_PWM_MODULE1_GEN3_A_M          GPIO_PCTL_PF2_M1PWM6
    #define GPIO_PF3_PCTL_PWM_MODULE1_GEN3_B_M          GPIO_PCTL_PF3_M1PWM7
    
    #define PWM0EN                                      0x1
    #define PWM1EN                                      0x2
    #define PWM2EN                                      0x4
    #define PWM3EN                                      0x8
    #define PWM4EN                                      0x10
    #define PWM5EN                                      0x20
    #define PWM6EN                                      0x40
    #define PWM7EN                                      0x80

    typedef enum{
        PWM_M0,
        PWM_M1
    }PWM_MODULE;

    typedef enum{
        /**
         *  Selects PWM generator
         * */
        PWM_G0_A,
        PWM_G0_B,
        PWM_G1_A,
        PWM_G1_B,
        PWM_G2_A,
        PWM_G2_B,
        PWM_G3_A,
        PWM_G3_B,
    }PWM_GEN;

    typedef enum{
        PWM_DEV_BY_2,
        PWM_DEV_BY_4,
        PWM_DEV_BY_8,
        PWM_DEV_BY_16,
        PWM_DEV_BY_32,
        PWM_DEV_BY_64,
    }PWM_DEVIDER;

    typedef enum {
        /**
         * Selects Generator Control Configration
         * */
        PWM_HIGH_ON_LOAD_LOW_ON_MATCH,
        PWM_LOW_ON_LOAD_HIGH_ON_MATCH,
    }PWM_OUTPUT_STATE;

    typedef enum{
        /**
         * Valid PWM pins
         * */
        PWM_PA6,
        PWM_PA7,

        PWM_PB4,
        PWM_PB5,
        PWM_PB6,
        PWM_PB7,

        PWM_PC4,
        PWM_PC5,

        PWM_PD0_M0,
        PWM_PD0_M1,
        PWM_PD1_M0,
        PWM_PD1_M1,
        
        PWM_PE4_M0,
        PWM_PE4_M1,
        PWM_PE5_M0,
        PWM_PE5_M1,

        PWM_PF0,
        PWM_PF1,
        PWM_PF2,
        PWM_PF3,

    }PWM_PIN;

    void PWM_Pin_Init(uint8_t port_index, PWM_PIN pwm_pin, PWM_DEVIDER pwm_devider, PWM_OUTPUT_STATE pwm_output_state, uint16_t load_value);
        /**
         * This function takes one valid pwm pin and PWM status and initialize 
         * -- Generator using PWM_Gen_Init() function
         * -- GPIO pin using Port_Driver and set AFSEL for this pin
         */

    void PWM_Gen_Init(PWM_MODULE pwm_module, PWM_GEN pwn_generator, PWM_DEVIDER pwm_devider, PWM_OUTPUT_STATE pwm_output_state, uint16_t load_value);
        /**
         * This function only initialize PWM generator
         * -- initialize module clk
         * -- set pwm devider
         * -- set output waveform state
         * -- set load value
         * -- start timer
         * -- enable pwm output
         */

    void PWM_Write(PWM_PIN pwm_pin, uint16_t duty_cycle,uint16_t load_value);
        /**
         * Set duty cycle for pwm_pin
         * -- set CMP register to corresponding value of duty cycle 
         */

#endif