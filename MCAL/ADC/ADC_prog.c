#include"../../lib/BIT_MATH.h"
#include"../../lib/STD_TYPES.h"
#include "ADC_registers.h"
#include "ADC_interface.h"

u8 ADC_u8State(enum_state Copy_enuState){

	if (Copy_enuState==Disable) {

		/*Disable ADC*/
		CLR_BIT(ADCSRA, ADCSRA_ADEN);

	} else if (Copy_enuState==Enable) {

		/*Set result register as right adjustment*/
		CLR_BIT(ADMUX, ADMUX_ADLAR);

		/*Enable ADC*/
		SET_BIT(ADCSRA, ADCSRA_ADEN);
	}
}
/*------------------------------------------------------------*/
u8 ADC_u8Init(enum_refVoltage Copy_enuRefVoltage,
		enum_prescaler Copy_enuPrescaler) {

	/*Set reference voltage*/
	CLR_BIT(ADMUX, ADMUX_REFS1);
	CLR_BIT(ADMUX, ADMUX_REFS0);
	ADMUX |= Copy_enuRefVoltage;

	/*Set clock division factor*/
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	ADCSRA |= Copy_enuPrescaler;

}
/*------------------------------------------------------------*/
u8 ADC_ChannelSelect(enum_channels Copy_enuChannels){
	/*Handle channel selection*/
	CLR_BIT(ADMUX, ADMUX_MUX0);
	CLR_BIT(ADMUX, ADMUX_MUX1);
	CLR_BIT(ADMUX, ADMUX_MUX2);
	CLR_BIT(ADMUX, ADMUX_MUX3);
	CLR_BIT(ADMUX, ADMUX_MUX4);
	ADMUX |= Copy_enuChannels;
}
/*------------------------------------------------------------*/
u8 ADC_u8StartConversion(void){
	/*Start conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);
}
/*------------------------------------------------------------*/
u8 ADC_u8AutoTriggerState(enum_state Copy_enuState){

	if (Copy_enuState == Disable) {
		/*Disable Auto trigger mode*/
		CLR_BIT(ADCSRA, ADCSRA_ADATE);
	} else if (Copy_enuState == Enable) {
		/*Enable Auto trigger mode*/
		SET_BIT(ADCSRA, ADCSRA_ADATE);
	}
}
/*------------------------------------------------------------*/
u8 ADC_u8AutoTriggerSource(enum_triggers Copy_enuTriggers){
	/*set trigger source*/
	CLR_BIT(SFIOR, SFIOR_ADTS0);
	CLR_BIT(SFIOR, SFIOR_ADTS1);
	CLR_BIT(SFIOR, SFIOR_ADTS2);
	SFIOR |= Copy_enuTriggers;
}
/*------------------------------------------------------------*/
u8 ADC_u8ConversionCompleteInterruptState(enum_state Copy_enuState){
	if (Copy_enuState==Disable){
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}else if(Copy_enuState==Enable){
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
}
/*------------------------------------------------------------*/
u8 ADC_u8GetReading(u16* pu16Value){
	/*read ADCH && ADCL*/
	*pu16Value = ADCL;
	*pu16Value |= (ADCH << 6);
}

