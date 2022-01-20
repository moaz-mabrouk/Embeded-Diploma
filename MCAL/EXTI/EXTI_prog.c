#include"../../lib/STD_TYPES.h"
#include"../../lib/BIT_MATH.h"
#include "EXTI_registers.h"
#include"EXTI_interface.h"


void EXT0_vdEnable(enu_SenseControl Copy_enuSenseControlMode) {

	/*Sensing control*/
	switch (Copy_enuSenseControlMode) {
	case lowLevel:
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;
	case IOC:
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;
	case FallingEdge:
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;
	case RisingEdge:
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;
	}

	/*Enable interrupt (PIE)*/
	SET_BIT(GICR, GICR_INT0);
}
/*------------------------------------------------------------*/
void EXT1_vdEnable(enu_SenseControl Copy_enuSenseControlMode) {

	/*Sensing control*/
	switch (Copy_enuSenseControlMode) {
	case lowLevel:
		CLR_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	case IOC:
		CLR_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	case FallingEdge:
		SET_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	case RisingEdge:
		SET_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	}

	/*Enable interrupt (PIE)*/
	SET_BIT(GICR, GICR_INT1);
}
/*------------------------------------------------------------*/
void EXT2_vdEnable(enu_SenseControl Copy_enuSenseControlMode) {
	/*Sensing control*/
	switch (Copy_enuSenseControlMode) {
	case RisingEdge:
		SET_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	case FallingEdge:
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	case lowLevel:
	case IOC:
		break;
	}

	/*Enable interrupt (PIE)*/
	SET_BIT(GICR, GICR_INT2);
}
/*------------------------------------------------------------*/
void EXT0_vdDisable(void) {
	SET_BIT(GICR, GICR_INT0);
}
/*------------------------------------------------------------*/
void EXT1_vdDisable(void) {
	SET_BIT(GICR, GICR_INT1);
}
/*------------------------------------------------------------*/
void EXT2_vdDisable(void) {
	SET_BIT(GICR, GICR_INT2);

}

