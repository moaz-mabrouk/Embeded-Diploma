/*
 * Private.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Moaz Mahmoud
 */
#include"../../lib/STD_TYPES.h"
#include"../../HAL/KPAD/KPAD_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
/*************************************************************/
/*This function converts a string number to a float variable*/
/************************************************************/
f32 Private_f32StringToFloat(u8 *pu8Number) {

	f32 Local_f32Result = 0;
	u8 Local_u8DotFlag = 0;
	f32 Local_u8DivideFactor = 10;

	for (u8 i = 0; pu8Number[i] != '\0'; i++) {
		if (pu8Number[i] == '.') {
			Local_u8DotFlag = 1;
			i++;
		}

		if (!Local_u8DotFlag) {
			Local_f32Result *= 10;
			Local_f32Result += (pu8Number[i] - '0');
		} else if (Local_u8DotFlag) {
			Local_f32Result += (pu8Number[i] - '0')/Local_u8DivideFactor;
			Local_u8DivideFactor *= 10;
		}

	}
	return Local_f32Result;
}
/*************************************************************/
/*This function waits until a button is pressed on the keypad*/
/*************************************************************/
u8 Private_u8WaitToPressKey(void) {
	u8 Local_u8character = 0;
	do {
		Local_u8character = KPAD_u8GetPressedKey();
	} while (Local_u8character == 10);
	return Local_u8character;
}
/***********************************************************/
/*This function converts a float number into a string array*/
/***********************************************************/
void Private_vdFloatToString(f32 Copy_f32Value, u8 *pu8_string) {
	/*This variable is used in handling the fraction part of the float */
	s32 Local_s32Temp = Copy_f32Value;
	u8 i = 0; //This variable is used as counter
	s32 Local_s32NumLengthFactor = 10; //This is used to find the number length for the conversion

	/*****************************************/
	/*This condition handles the negative sign*/
	if (Local_s32Temp < 0) {
		pu8_string[0] = '-';
		i += 1;
		Local_s32Temp *= -1;
	}

	/*****************************************/
	/*while loop to calculate number length*/
	while ((Local_s32Temp / Local_s32NumLengthFactor) != 0) {
		Local_s32NumLengthFactor *= 10;
	}
	Local_s32NumLengthFactor /= 10;

	/*convert the integer part into a string*/
	while (Local_s32NumLengthFactor >= 1) {
		pu8_string[i] = (Local_s32Temp / Local_s32NumLengthFactor) + 48;
		Local_s32Temp %= Local_s32NumLengthFactor;
		Local_s32NumLengthFactor /= 10;
		i += 1;
	}
	/*****************************************/
	pu8_string[i] = '.';
	i += 1;
	/*****************************************/
	/*Handle fraction part of float(only 2 decimal places)*/
	Local_s32NumLengthFactor = 10;
	Local_s32Temp = Copy_f32Value;
	Local_s32Temp = (s32)((Copy_f32Value-Local_s32Temp)*100);//Get 2 decimal digits of the float

	/*****************************************/
	/*convert the fraction part into a string*/
	for (u8 j=0 ; j<2; j++,i++) {
		pu8_string[i] = (Local_s32Temp / Local_s32NumLengthFactor) + 48;
		Local_s32Temp %= Local_s32NumLengthFactor;
		Local_s32NumLengthFactor /= 10;
	}
	pu8_string[i] = '\0'; //add \0 at the end of the string

}

