#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
/****************************************************/
/*Return Home and Clear display*/
#define LCD_CLRDISP 	0X01
#define LCD_RETHOME 	0X02
/*CURSOR MOVE*/
#define LCD_CURSOR_LFT	0X10
#define LCD_CURSOR_RGHT	0X14
/*DISPLAY MOVE*/
#define LCD_DISP_LFT	0X18
#define LCD_DISP_RGHT	0X1C
#define LCD_CURSOR_ON	0x0f
/*CURSOR ON/OFF*/
#define LCD_CURSOR_OFF	0x0C
#define LCD_CURSOR_ON	0x0f
/*DISPLAY MOVE*/
#define LCD_INCREMENT_CURSOR 0X06
#define LCD_DECREMENT_CURSOR 0X04
/****************************************************/
void LCD_vdInit(void);
void LCD_vdSendData(u8 Copy_u8Data);
void LCD_vdSendCommand(u8 Copy_u8Command);
void LCD_vdSendString(u8 *pu8String);
void LCD_vdSendDataToPos(u8 Copy_u8Row,u8 Copy_u8Col, u8 Copy_u8Data);
void LCD_vdSendStringToPos(u8 Copy_u8Row,u8 Copy_u8Col, u8 *pu8String);
void LCD_vdDelData(void);
#endif
