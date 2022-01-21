/*
 * main.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Moaz Mahmoud
 */
#include<util/delay.h>
#include"stdlib.h"
#include"../../lib/STD_TYPES.h"
#include "Private.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include"../../HAL/LCD/LCD_interface.h"
#include "../../HAL/KPAD/KPAD_interface.h"



/*******************************************************/
/*						Int Main		  			   */
/*******************************************************/
int main(){


	/******************************************************/
	/*					Set port for LCD				  */
	/******************************************************/
	DIO_u8SetPortDirection(portA,0xff);
	DIO_u8SetPortValue(portA,0x00);
	DIO_u8SetPortDirection(portD,0xff);
	DIO_u8SetPortValue(portD,0x00);
	LCD_vdInit();


	/******************************************************/
	/*			KeyPad initialize Pull Up Resistor		  */
	/******************************************************/
	DIO_u8SetPortDirection(portB,0xf0);
	DIO_u8SetPortValue(portB,0xff);

	LCD_vdSendCommand(LCD_CURSOR_ON);
	/********************************************************/
	/*						void loop						*/
	/********************************************************/

	while(1){

		u8 i=0;
		f32 Result=0;
		u8 kpd=0;
		u8 Num_index=0;
		u8 	 Number[20]={0};
		u8  *operators =malloc(sizeof(u8));
		f32 *Operands  =malloc(sizeof(f32));
		Operands[0]=1.0;
		operators[0]='\0';
		do{
			kpd=Private_u8WaitToPressKey();
			LCD_vdSendData(kpd);
			_delay_ms(100);

			if((kpd>='0' && kpd<='9') || kpd=='.'){
				Number[Num_index]=kpd;
				Number[Num_index+1]='\0';
				Num_index+=1;

			}else if(kpd!='='){
				/*Assigning operator and its operand*/
				operators[i]=kpd;
				Operands[i]*=Private_f32StringToFloat(Number);
				/*Allocating New memory for next operand & operator*/
				operators=realloc(operators,sizeof(u8)*(i+2));
				Operands=realloc(Operands,sizeof(f32)*(i+2));
				/*Initializing newly allocated memory*/
				operators[i+1]='\0';
				/*To handle subtraction operator operands*/
				if(kpd=='-'){
					Operands[i+1]=-1.0;
				}else{
					Operands[i+1]=1.0;
				}
				/*Incrementing Index*/
				i+=1;
				Num_index=0;

			}else if(kpd == '='){
				Operands[i]*=Private_f32StringToFloat(Number);
			}

		}while(kpd!='=');
		/********************************************************/
		/*				to handle divisors operands				*/
		/********************************************************/
		for(u8 j=0; operators[j]!='\0'; j++){
			if (operators[j]=='/'){
				operators[j]='*';
				Operands[j+1]=1/Operands[j+1];
			}
		}
		/********************************************************/
		/*					to handle multiplications			*/
		/********************************************************/
		f32 temp=0;
		u8 seq_flag=0;
		for(u8 j=0; operators[j]!='\0'; j++){

			if(!seq_flag && operators[j]=='*'){
				seq_flag=1;
				temp=Operands[j]*Operands[j+1];
				Operands[j]=Operands[j+1]=0;
			}else if(seq_flag && operators[j]=='*'){
				temp *=Operands[j+1];
				Operands[j+1]=0;
			}else if(seq_flag && operators[j]!='*'){
				seq_flag=0;
				Result+=temp;
				temp=0;
			}
		}
		Result+=temp;
		/********************************************************/
		/*			Handling summation and subtraction			*/
		/********************************************************/
		for(u8 j=0; j<=i; j++){
			Result+=Operands[j];
		}
		/********************************************************/
		/*			Converting result to String					*/
		/********************************************************/
		u8 StringResult[7]={0};
		Private_vdFloatToString(Result,StringResult);
		/********************************************************/
		/*					Printing result 					*/
		/********************************************************/
		LCD_vdSendCommand(LCD_CURSOR_OFF);
		LCD_vdSendCommand(LCD_RETHOME);
		LCD_vdSendStringToPos(1,10,StringResult);
		Private_u8WaitToPressKey();
		/********************************************************/
		/*					Reset screen						*/
		/********************************************************/
		LCD_vdSendCommand(LCD_CLRDISP);
		LCD_vdSendCommand(LCD_CURSOR_ON);
		LCD_vdSendCommand(LCD_INCREMENT_CURSOR);
		/********************************************************/
		/*					Deallocating memory					*/
		/********************************************************/
		free(operators);
		free(Operands);
	}
	while(1);
}









