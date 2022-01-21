#include"../../lib/STD_TYPES.h"
#include"LCD_config.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include<util/delay.h>
#include "LCD_private.h"

/****************************************************/
/*Data*/
void LCD_vdSendData(u8 Copy_u8Data){
		/*set RS as High*/
		DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_RS_PIN,pinHigh);
		/*set RW as low*/
		DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_RW_PIN,pinLow);
		/*Send data*/
		DIO_u8SetPortValue(LCD_DATAPORT,Copy_u8Data);
		/*Set Enable as high*/
		DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_E_PIN,pinHigh);
		/*Delay 2 ms*/
		_delay_ms(2);
		/*Set Enable as Low*/
		DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_E_PIN,pinLow);

}
/****************************************************/
		/*command*/
void LCD_vdSendCommand(u8 Copy_u8Command){
	/*Set RS as Low*/
	DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_RS_PIN,pinLow);
	/*Set RW ad Low*/
	DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_RW_PIN,pinLow);
	/*Send command*/
	DIO_u8SetPortValue(LCD_DATAPORT,Copy_u8Command);
	/*Set Enable as High*/
	DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_E_PIN,pinHigh);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set Enable as Low*/
	DIO_u8SetPinValue(LCD_CONTROLPORT,LCD_E_PIN,pinLow);

}
/****************************************************/
		/*Initialization*/
void LCD_vdInit(void){
	_delay_ms(40);
	LCD_vdSendCommand(0b00111100);
	_delay_ms(1);
	LCD_vdSendCommand(0b0001100);
	_delay_ms(1);
	LCD_vdSendCommand(0b00000001);
}
/*****************************************************/
		/*Send string*/
void LCD_vdSendString(u8 *pu8String){
	for(u8 i=0; pu8String[i]!='\0';i++){
	/******Print each character until reaching \0*****/
		LCD_vdSendData(pu8String[i]);
	}
}
/****************************************************/
		/*Send Data to specific location*/
void LCD_vdSendDataToPos(u8 Copy_u8Row,u8 Copy_u8Col, u8 Copy_u8Data){
	/*Convert Row column to position Command*/
	u8 Local_u8Pos= LCD_u8ConvertPos(Copy_u8Row,Copy_u8Col);
	/*To Set D7 as High(busy flag)*/
	Local_u8Pos|=0x80;
	/*Move cursor to desired position*/
	LCD_vdSendCommand(Local_u8Pos);
	/*Print Data on LCD*/
	LCD_vdSendData(Copy_u8Data);
}
/****************************************************/
		/*Send string to location*/
void LCD_vdSendStringToPos(u8 Copy_u8Row,u8 Copy_u8Col, u8 *pu8String){
	/*Convert Row column to position Command*/
	u8 Local_u8Pos= LCD_u8ConvertPos(Copy_u8Row,Copy_u8Col);
	/*To Set D7 as High(busy flag)*/
	Local_u8Pos|=0x80;
	/*Move cursor to desired position*/
	LCD_vdSendCommand(Local_u8Pos);
	/*Print String on LCD*/
	LCD_vdSendString(pu8String);
}
/****************************************************/
		/*Delete Data*/
void LCD_vdDelData(void){

}








