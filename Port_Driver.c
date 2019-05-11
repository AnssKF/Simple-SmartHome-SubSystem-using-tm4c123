#include "Port_Driver.h"

void Port_Init(uint8_t port_index)
{
    volatile uint8_t delay;
    SET_BIT(SYSCTL_RCGCGPIO_R, port_index); // Port CLK Enable
    delay = 5;
    switch (port_index)
    {
    case PORTA:
        GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTA_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTA_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTA_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTA_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTA_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTA_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTA_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    case PORTB:
        GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTB_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTB_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTB_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTB_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTB_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTB_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTB_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    case PORTC:
        GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTC_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTC_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTC_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTC_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTC_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTC_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTC_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    case PORTD:
        GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTD_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTD_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTD_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTD_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTD_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTD_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTD_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    case PORTE:
        GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTE_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTE_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTE_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTE_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTE_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTE_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTE_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    case PORTF:
        GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // Unlock register
        GPIO_PORTF_CR_R |= 0x0f;           // GPIO Commit Register
        GPIO_PORTF_DEN_R |= 0xff;          // PORTA Digital Enable for all port
        // GPIO_PORTF_AFSEL_R = 0;            // GPIO Alternate Function Select
        // GPIO_PORTF_PCTL_R = 0;             // GPIO specific peripheral Function
        // GPIO_PORTF_ADCCTL_R = 0;           // GPIO ADC Control
        // GPIO_PORTF_DMACTL_R = 0;           // GPIO DMA Control
        // GPIO_PORTF_AMSEL_R = 0;            // GPIO Analog Mode Select
        break;

    default:
        // Do nothing
        break;
    }
}

void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirection pins_direction)
{
    switch (port_index)
    {
    case PORTA:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTA_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTA_DIR_R &= (~pins_mask);
        break;

    case PORTB:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTB_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTB_DIR_R &= (~pins_mask);
        break;

    case PORTC:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTC_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTC_DIR_R &= (~pins_mask);
        break;

    case PORTD:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTD_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTD_DIR_R &= (~pins_mask);
        break;

    case PORTE:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTE_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTE_DIR_R &= (~pins_mask);
        break;

    case PORTF:
        if (pins_direction == PORT_PIN_OUT)
            // Set Pins To Be OUTPUT
            GPIO_PORTF_DIR_R |= pins_mask;
        else
            // Set Pins To Be INPUT
            GPIO_PORTF_DIR_R &= (~pins_mask);
        break;

    default:
        // Do nothing
        break;
    }
}

void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
    switch (port_index)
    {
    case PORTA:
        if (enable)
            GPIO_PORTA_PUR_R |= pins_mask;
        else
            GPIO_PORTA_PUR_R &= (~pins_mask);
        break;

    case PORTB:
        if (enable)
            GPIO_PORTB_PUR_R |= pins_mask;
        else
            GPIO_PORTB_PUR_R &= (~pins_mask);
        break;

    case PORTC:
        if (enable)
            GPIO_PORTC_PUR_R |= pins_mask;
        else
            GPIO_PORTC_PUR_R &= (~pins_mask);
        break;

    case PORTD:
        if (enable)
            GPIO_PORTD_PUR_R |= pins_mask;
        else
            GPIO_PORTD_PUR_R &= (~pins_mask);
        break;

    case PORTE:
        if (enable)
            GPIO_PORTE_PUR_R |= pins_mask;
        else
            GPIO_PORTE_PUR_R &= (~pins_mask);
        break;

    case PORTF:
        if (enable)
            GPIO_PORTF_PUR_R |= pins_mask;
        else
            GPIO_PORTF_PUR_R &= (~pins_mask);
        break;

    default:
        // Do nothing
        break;
    }
}

void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
    switch (port_index)
    {
    case PORTA:
        if (enable)
            GPIO_PORTA_PDR_R |= pins_mask;
        else
            GPIO_PORTA_PDR_R &= (~pins_mask);
        break;

    case PORTB:
        if (enable)
            GPIO_PORTB_PDR_R |= pins_mask;
        else
            GPIO_PORTB_PDR_R &= (~pins_mask);
        break;

    case PORTC:
        if (enable)
            GPIO_PORTC_PDR_R |= pins_mask;
        else
            GPIO_PORTC_PDR_R &= (~pins_mask);
        break;

    case PORTD:
        if (enable)
            GPIO_PORTD_PDR_R |= pins_mask;
        else
            GPIO_PORTD_PDR_R &= (~pins_mask);
        break;

    case PORTE:
        if (enable)
            GPIO_PORTE_PDR_R |= pins_mask;
        else
            GPIO_PORTE_PDR_R &= (~pins_mask);
        break;

    case PORTF:
        if (enable)
            GPIO_PORTF_PDR_R |= pins_mask;
        else
            GPIO_PORTF_PDR_R &= (~pins_mask);
        break;

    default:
        // Do nothing
        break;
    }
}