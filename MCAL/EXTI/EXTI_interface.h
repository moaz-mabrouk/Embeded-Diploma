#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*------------------------------------*/
/*-----------Trigger Event------------*/
/*------------------------------------*/
typedef enum {
	lowLevel,
	IOC,
	RisingEdge,
	FallingEdge
}enu_SenseControl;


/********************************************************************/
/****************************Prototypes******************************/
/********************************************************************/


/*-----------Enable interrupts--------*/
void EXT0_vdEnable(enu_SenseControl Copy_enuSenseControlMode);
void EXT1_vdEnable(enu_SenseControl Copy_enuSenseControlMode);
void EXT2_vdEnable(enu_SenseControl Copy_enuSenseControlMode);


/*----------Disable interrupts--------*/
void EXT0_vdDisable(void);
void EXT1_vdDisable(void);
void EXT2_vdDisable(void);

#endif
