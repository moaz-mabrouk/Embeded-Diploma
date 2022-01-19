#ifndef EXTI_REGISTERS_H
#define EXTI_REGISTERS_H

/*Sensing control
 * INT0 & INT1*/
#define MCUCR 	*((volatile u8*)0x55)
#define MCUCR_ISC11	3
#define MCUCR_ISC10	2
#define MCUCR_ISC01	1
#define MCUCR_ISC00	0

/*Sensing control
 *INT2*/
#define MCUCSR	*((volatile u8*)0x54)
#define MCUCSR_ISC2	6

/*PIE register*/
#define GICR	*((volatile u8*)0x5b)
#define GICR_INT1	7
#define GICR_INT0	6
#define GICR_INT2	5

#endif 
