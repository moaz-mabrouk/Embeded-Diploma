#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum {
	lowLevel,
	IOC,
	RisingEdge,
	FallingEdge
}enu_SenseControl;

void EXT0_vdEnable(enu_SenseControl Copy_enuSenseControlMode);
void EXT1_vdEnable(enu_SenseControl Copy_enuSenseControlMode);
void EXT2_vdEnable(enu_SenseControl Copy_enuSenseControlMode);

/*disable interrupts*/
void EXT0_vdDisable(void);
void EXT1_vdDisable(void);
void EXT2_vdDisable(void);
#endif
