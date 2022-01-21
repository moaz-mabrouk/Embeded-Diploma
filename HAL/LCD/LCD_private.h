#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H
/***************************************************/
/*LCD Private convert position argument to LCD command*/
u8 LCD_u8ConvertPos(u8 Copy_u8Row,u8 Copy_u8Col){
	/*Holds location as hex command*/
	u8 Local_u8Result=0;

	switch (Copy_u8Row){
	case 0:/*If First LCD row*/
		if(Copy_u8Col<16){/*If Column is in the first 16 characters in DDRAM*/
			Local_u8Result=Copy_u8Col;
		}else if (Copy_u8Col<32){/*If Column is in the 2nd 16 character in the DDRAM*/
			Local_u8Result=0x10|Copy_u8Col;
		}else if (Copy_u8Col<40){/*IF Column is in the Last 8 characters in the DDRAM*/
			Local_u8Result=0x20|Copy_u8Col;
		}
		break;
	case 1:/*If Second LCD row*/
		if(Copy_u8Col<16){/*If Column is in the first 16 characters in DDRAM*/
			Local_u8Result=0x40|Copy_u8Col;

		}else if (Copy_u8Col<32){/*If Column is in the 2nd 16 character in the DDRAM*/
			Local_u8Result=0x50|Copy_u8Col;

		}else if (Copy_u8Col<40){/*IF Column is in the Last 8 characters in the DDRAM*/
			Local_u8Result=0x60|Copy_u8Col;
		}
		break;
	}
	/*Return Zero if position is invalid */
	return Local_u8Result;
}
#endif
