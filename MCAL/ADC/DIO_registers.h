#ifndef ADC_REGISTERS_H
#define ADC_REGISTERS_H

/*ADC multiplexer selection register*/
#define ADMUX *((volatile u8*)0x27)
#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5
#define ADMUX_MUX4	4
#define ADMUX_MUX3 	3
#define ADMUX_MUX2	2
#define ADMUX_MUX1	1
#define ADMUX_MUX0	0
 
/*ADC control and status register*/
#define ADCSRA *((volatile u8*)0x26)
#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF  4
#define ADCSRA_ADIE  3
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0

/*ADC data registers*/
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)

/*ADC special functions register*/
#define SFIOR *((volatile u8*)0x50)
#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5	



#endif 
