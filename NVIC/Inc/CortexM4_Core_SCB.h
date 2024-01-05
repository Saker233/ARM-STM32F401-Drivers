/*
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.h
 * @author         : Mohamed Saker
 * @brief          : Contains declaration to control System control block
 ******************************************************************************
*/

#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_


/* ----------------------- Includes Start -------------------------------- */

#include "Std_Types.h"


/* ----------------------- Includes End -------------------------------- */

/* ----------------------- Macro Declaration Start -------------------------------- */

/* Memory Mapping for core Hardware 8 */
#define SCB_BASE			(0xE000ED00UL)
#define SCB					((SCB_Type *)SCB_BASE)


#define SCB_PRIORITYGROUP0			0x00000007U
#define SCB_PRIORITYGROUP1			0x00000006U
#define SCB_PRIORITYGROUP2			0x00000005U
#define SCB_PRIORITYGROUP3			0x00000004U
#define SCB_PRIORITYGROUP4			0x00000003U

#define SCB_AIRCR_PRIGROUP_POS			8U
#define SCB_AIRCR_PRIGROUP_MSK			(7UL << SCB_AIRCR_PRIGROUP_POS)



#define SCB_AIRCR_VECTKEYSTAT_POS		16U
#define SCB_AIRCR_VECTKEYSTAT_MSK		(0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_POS)

/* ----------------------- Macro Declaration End-------------------------------- */

/* ----------------------- Macro Functions Declaration Start -------------------------------- */



/* ----------------------- Macro Functions DeclarationEnd -------------------------------- */

/* ----------------------- Data Types Declarations Start-------------------------------- */

typedef struct
{
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCSR;
	volatile uint32_t CFSR;
}SCB_Type;





/* ----------------------- Data Types Declarations End-------------------------------- */


/* ----------------------- Software Interfaces Declarations Start -------------------------------- */

void SCB_SetPriorityGrouping(uint32_t PriorityGroup);
uint32_t SCB_GetPriorityGrrouping(void);

/* ----------------------- Software Interfaces Declarations End-------------------------------- */


#endif /* CORTEXM4_CORE_SCB_H_ */
