#include"../../lib/STD_TYPES.h"
#include"../../lib/BIT_MATH.h"
#include "GIE_registers.h"
void GIE_vdEnable(void){
	SET_BIT(SREG,SREG_IBIT);
}
void GIE_vdDisable(void){
	CLR_BIT(SREG,SREG_IBIT);
}
