#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*Reference voltage enum*/
typedef enum {
	external_Aref =0x00<<6,
	internal_Avcc =0x01<<6,
	internal_vref =0x03<<6
}enum_refVoltage;
/*channel selection enum*/
typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC10x00_,
	ADC10x10_,
	ADC200x00_,
	ADC200X10_,
	ADC10X22_,
	ADC10x32_,
	ADC200x22_,
	ADC200x32_,
	ADC1x01_,
	ADC1x11_,
	ADC1x21,
	ADC1x31,
	ADC1x41,
	ADC1x51,
	ADC1x61,
	ADC1x71,
	ADC1x02,
	ADC1x12,
	ADC1x22,
	ADC1x32,
	ADC1x42,
	ADC1x52,
	ADC_V,
	ADC_GND
}enum_channels;
/*prescaler division factors*/
typedef enum{
	divisionFactor2,
	divisionFactor2,
	divisionFactor4,
	divisionFactor8,
	divisionFactor16,
	divisionFactor32,
	divisionFactor64,
	divisionFactor128
}enum_prescaler;
/*auto trigger sources*/
typedef enum{
	freeRun=0x00<<5,
	analogComparator=0x01<<5,
	extI=0x02<<5,
	timer0_CompareMatch=0x03<<5,
	timer0_overflow=0x04<<5,
	timer_CompareMatchB=0x05<<5,
	timer1_overflow=0x06<<5,
	timer1_event=0x07<<5,
}enum_triggers


u8 ADC_u8Init(enum_refVoltage Copy_enuRefVoltage, enum_prescaler Copy_enuPrescaler );
u8 ADC_u8InterruptEnable(enum_triggers Copy_enuTriggers);
u8 ADC_u8GetReading(enum_channels Copy_enuChannels);


#endif 
