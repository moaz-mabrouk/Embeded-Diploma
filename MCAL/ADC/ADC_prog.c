#include"../../lib/BIT_MATH.h"
#include"../../lib/STD_TYPES.h"
#include "DIO_registers.h"
u8 ADC_u8Init(enum_refVoltage Copy_enuRefVoltage,
		enum_prescaler Copy_enuPrescaler) {

	/*Clear reference voltage then set it back*/
	CLR_BIT(ADMUX, ADMUX_REFS1);
	CLR_BIT(ADMUX, ADMUX_REFS0);
	ADMUX |= Copy_enuRefVoltage;

	/*set prescaler division factor*/
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	ADCSRA |= Copy_enuPrescaler;

	/*Set data register adjust bit to right adjustment*/
	CLR_BIT(ADMUX, ADMUX_ADLAR);

	/*Enable ADC*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);

}

u8 ADC_u8GetReading(enum_channels Copy_enuChannels, u16* pu16Value) {

	/*Handle channel selection*/
	CLR_BIT(ADMUX, ADMUX_MUX0);
	CLR_BIT(ADMUX, ADMUX_MUX1);
	CLR_BIT(ADMUX, ADMUX_MUX2);
	CLR_BIT(ADMUX, ADMUX_MUX3);
	CLR_BIT(ADMUX, ADMUX_MUX4);
	ADMUX |= Copy_enuChannels;

	/*Start conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/*read ADCH && ADCL*/
	*pu16Value = ADCL;
	*pu16Value |= (ADCH << 6);
}

u8 ADC_u8InterruptEnable(enum_triggers Copy_enuTriggers,enum_channels Copy_enuChannels){

	/*Handle channel selection*/
	CLR_BIT(ADMUX, ADMUX_MUX0);
	CLR_BIT(ADMUX, ADMUX_MUX1);
	CLR_BIT(ADMUX, ADMUX_MUX2);
	CLR_BIT(ADMUX, ADMUX_MUX3);
	CLR_BIT(ADMUX, ADMUX_MUX4);
	ADMUX |= Copy_enuChannels;

	/*set trigger source*/
	CLR_BIT(SFIOR,SFIOR_ADTS0);
	CLR_BIT(SFIOR,SFIOR_ADTS1);
	CLR_BIT(SFIOR,SFIOR_ADTS2);
	SFIOR|=Copy_enuTriggers;
}
