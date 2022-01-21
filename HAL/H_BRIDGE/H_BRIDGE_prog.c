#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "H_BRIDGE_config.h"
#include <util/delay.h>

void H_BRIDGE_vdStop(void){
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_A,pinLow);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_B,pinLow);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_C,pinLow);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_D,pinLow);
	_delay_ms(STOP_DELAY_ms);
}
void H_BRIDGE_vdClockWise(void){
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_C,pinLow);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_B,pinLow);
	_delay_ms(STOP_DELAY_ms);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_A,pinHigh);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_D,pinHigh);

}
void H_BRIDGE_vdAntiClockWise(void){
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_A,pinLow);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_D,pinLow);
	_delay_ms(STOP_DELAY_ms);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_C,pinHigh);
	DIO_u8SetPinValue(BASE_PORT,BASE_PIN_B,pinHigh);
}
