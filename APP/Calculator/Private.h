/*
 * Private.h
 *
 *  Created on: Dec 28, 2021
 *      Author: Moaz Mahmoud
 */
#ifndef APP_CALCULATOR_PRIVATE_H_
#define APP_CALCULATOR_PRIVATE_H_
/******************************************************/
u8  Private_u8WaitToPressKey(void);
f32 Private_f32StringToFloat(u8 *pu8Number);
void Private_vdFloatToString(f32 Copy_f32Value, u8 *pu8_string);
/******************************************************/


#endif /* APP_CALCULATOR_PRIVATE_H_ */



