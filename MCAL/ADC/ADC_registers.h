#ifndef ADC_REGISTERS_H
#define ADC_REGISTERS_H


/**************************************/
/**ADC multiplexer selection register**/
/**************************************/
#define ADMUX *((volatile u8*)0x27)

/*Reference voltage*/
#define ADMUX_REFS1 7
#define ADMUX_REFS0 6

/*Adjustment bit*/
#define ADMUX_ADLAR 5

/*Channel selection bits*/
#define ADMUX_MUX4	4
#define ADMUX_MUX3 	3
#define ADMUX_MUX2	2
#define ADMUX_MUX1	1
#define ADMUX_MUX0	0


/**************************************/
/***ADC control and status register****/
/**************************************/
#define ADCSRA *((volatile u8*)0x26)
/*Enable bit*/
#define ADCSRA_ADEN  7

/*Start conversion bit*/
#define ADCSRA_ADSC  6

/*Auto Trigger Enable bit*/
#define ADCSRA_ADATE 5

/*Interrupt flag bit*/
#define ADCSRA_ADIF  4

/*Conversion complete interrupt bit*/
#define ADCSRA_ADIE  3

/*Pre-scaler bits*/
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0


/**************************************/
/*********ADC data registers***********/
/**************************************/
#define ADCH *((volatile u8*)0x25)//high DR
#define ADCL *((volatile u8*)0x24)//low  DR


/**************************************/
/****ADC special functions register****/
/**************************************/
#define SFIOR *((volatile u8*)0x50)
/*Auto trigger source selector bits */
#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5	


#endif 
