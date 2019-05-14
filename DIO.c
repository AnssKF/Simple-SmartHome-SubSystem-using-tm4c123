#include "DIO.h"



void DIO_WritePort(uint8_t port_index, uint8_t pins_mask, Dio_LevelType pins_level)
    {

        Port_SetPinDirection(port_index, pins_mask, PORT_PIN_OUT);
        
        switch(port_index)
        {
            case PORTA: GPIO_PORTA_DATA_R = (pins_level)? GPIO_PORTA_DATA_R | pins_mask : GPIO_PORTA_DATA_R & (~pins_mask); break;
            case PORTB: GPIO_PORTB_DATA_R = (pins_level)? GPIO_PORTB_DATA_R | pins_mask : GPIO_PORTB_DATA_R & (~pins_mask); break;
            case PORTC: GPIO_PORTC_DATA_R = (pins_level)? GPIO_PORTC_DATA_R | pins_mask : GPIO_PORTC_DATA_R & (~pins_mask); break;
            case PORTD: GPIO_PORTD_DATA_R = (pins_level)? GPIO_PORTD_DATA_R | pins_mask : GPIO_PORTD_DATA_R & (~pins_mask); break;
            case PORTE: GPIO_PORTE_DATA_R = (pins_level)? GPIO_PORTE_DATA_R | pins_mask : GPIO_PORTE_DATA_R & (~pins_mask); break;
            case PORTF: GPIO_PORTF_DATA_R = (pins_level)? GPIO_PORTF_DATA_R | pins_mask : GPIO_PORTF_DATA_R & (~pins_mask); break;

        }

    }


void DIO_FlipPort(uint8_t port_index, uint8_t pins_mask)
{

	Port_SetPinDirection(port_index, pins_mask, PORT_PIN_OUT);

	switch (port_index)
	{
	case PORTA: GPIO_PORTA_DATA_R ^= pins_mask; break;
	case PORTB: GPIO_PORTB_DATA_R ^= pins_mask; break;
	case PORTC: GPIO_PORTC_DATA_R ^= pins_mask; break;
	case PORTD: GPIO_PORTD_DATA_R ^= pins_mask; break;
	case PORTE: GPIO_PORTE_DATA_R ^= pins_mask; break;
	case PORTF: GPIO_PORTF_DATA_R ^= pins_mask; break;

	}

}


void DIO_write_halfPort(uint8_t port_index, uint8_t upper_half, uint8_t data)
{
        //uint8_t pins_mask = (upper_half)? 0xF0: 0x0F;
        //Port_SetPinDirection(port_index, pins_mask, PORT_PIN_OUT);
        
        switch(port_index)
        {
            case PORTA: GPIO_PORTA_DATA_R = 0 & 0xF0;
							GPIO_PORTA_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;
            case PORTB: GPIO_PORTB_DATA_R = 0 & 0xF0;
							GPIO_PORTB_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;
            case PORTC:  GPIO_PORTC_DATA_R = 0 & 0xF0; 
							GPIO_PORTC_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;
            case PORTD:	GPIO_PORTD_DATA_R = 0 & 0xF0; 
							GPIO_PORTD_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;
            case PORTE:   GPIO_PORTE_DATA_R = 0 & 0xF0;
							GPIO_PORTE_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;
            case PORTF:  GPIO_PORTF_DATA_R = 0 & 0xF0; 
							GPIO_PORTF_DATA_R |= (upper_half)? (data << 4) : (data & 0x0F); break;


        }

}






uint8_t DIO_ReadPort(uint8_t port_index, uint8_t pins_mask)
{
    Port_SetPinDirection(port_index, pins_mask, PORT_PIN_IN);

    switch(port_index)
    {
        case PORTA: return (uint8_t) GPIO_PORTA_DATA_R & pins_mask; break;
        case PORTB: return (uint8_t) GPIO_PORTB_DATA_R & pins_mask; break;
        case PORTC: return (uint8_t) GPIO_PORTC_DATA_R & pins_mask; break;
        case PORTD: return (uint8_t) GPIO_PORTD_DATA_R & pins_mask; break;
        case PORTE: return (uint8_t) GPIO_PORTE_DATA_R & pins_mask; break;
        case PORTF: return (uint8_t) GPIO_PORTF_DATA_R & pins_mask; break; 
        default: return 0; break;
    }
    return 0;
}


void DIO_writePort(uint8_t port_index, uint8_t data)
{
        Port_SetPinDirection(port_index, 0xFF, PORT_PIN_OUT);
        
        switch(port_index)
        {
            case PORTA: GPIO_PORTA_DATA_R = data; break;
            case PORTB: GPIO_PORTB_DATA_R = data; break;
            case PORTC: GPIO_PORTC_DATA_R = data; break;
            case PORTD: GPIO_PORTD_DATA_R = data; break;
            case PORTE: GPIO_PORTE_DATA_R = data; break;
            case PORTF: GPIO_PORTF_DATA_R = data; break;

        }

    
}