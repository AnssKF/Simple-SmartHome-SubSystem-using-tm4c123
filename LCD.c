void LCD_DisplayChar(uint8_t Data)
	{
		/* RW  Should be 0  and RS should be 1 when Writing Data to LCD */
		SET_BIT(LCD_Control_reg_OP,RS);
		CLEAR_BIT(LCD_Control_reg_OP,RW);
		/* Delay of Address Set 60ns minimum */
		_delay_ms(1);
		/* Enable LCD E=1 */
		SET_BIT(LCD_Control_reg_OP,E);
		/* delay for processing PW min 450ns */
		_delay_ms(1);
		#if eight_bitdata
			LCD_Data_Reg_OP=Data;
		#else
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				/* Send MSB (4-bits )*/
				LCD_Data_Reg_OP |= (Data & 0xF0);
			
			#else /* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				/* Send MSB (4-bits )*/
				LCD_Data_Reg_OP |= ((Data >> 4) & 0x0f);
			#endif
				
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1);
			/* disable LCD E=0 */
			CLEAR_BIT(LCD_Control_reg_OP,E);
			/* Data Hold delay Th = 10ns */
			_delay_ms(1);
			/* Enable LCD E=1 */
			SET_BIT(LCD_Control_reg_OP,E); 
				
			#ifdef Upper_Data_port
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0x0F;
				LCD_Data_Reg_OP |= ((Data <<4) & 0xF0);
				/* delay for processing PW min 450ns */
				_delay_ms(1);
			#else	/* Lower Port */
				/* clear the Prev Data */
				LCD_Data_Reg_OP &=0xF0;
				LCD_Data_Reg_OP |= ((Data) & 0x0f);
			#endif
			
			#endif
		/* Data set-up time delay  Tdsw = 195 ns */
		_delay_ms(1);
		/* disable LCD E=0 */
		CLEAR_BIT(LCD_Control_reg_OP,E);						
		/* Data Hold delay Th = 10ns */
		_delay_ms(1);
		
	}