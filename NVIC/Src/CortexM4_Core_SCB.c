/*
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.c
 * @author         : Mohamed Saker
 * @brief          : Contains static to control System control block
 ******************************************************************************
*/
#include "CortexM4_Core_SCB.h"


void SCB_SetPriorityGrouping(uint32_t PriorityGroup)
{
	uint32_t Register_Value = 0;
	uint32_t PriorityGroupTemp = ((uint32_t)PriorityGroup & (uint32_t)0x07);

	Register_Value = SCB->AIRCR;
	Register_Value &= ~((uint32_t)SCB_AIRCR_PRIGROUP_MSK | SCB_AIRCR_VECTKEYSTAT_MSK);

	Register_Value = (Register_Value | ((uint32_t)0x05FA << SCB_AIRCR_VECTKEYSTAT_POS) | (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_POS));


	SCB->AIRCR = Register_Value;
}
uint32_t SCB_GetPriorityGrrouping(void)
{
	return (((uint32_t)SCB->AIRCR & (uint32_t)SCB_AIRCR_PRIGROUP_MSK) >> SCB_AIRCR_PRIGROUP_POS);
}
