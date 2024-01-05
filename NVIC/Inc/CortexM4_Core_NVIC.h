/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Mohamed Saker
 * @brief          : Static code to control NVIC
 ******************************************************************************
*/

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_
/* ----------------------- Includes Start -------------------------------- */

#include "Std_Types.h"


/* ----------------------- Includes End -------------------------------- */

/* ----------------------- Macro Declaration Start -------------------------------- */
#define NVIC_BASE		(0xE000E100UL)
#define NVIC 			((NVIC_Type *)NVIC_BASE)


#define NVIC_PRIO_BITS		4U

/* ----------------------- Macro Declaration End-------------------------------- */

/* ----------------------- Macro Functions Declaration Start -------------------------------- */



/* ----------------------- Macro Functions DeclarationEnd -------------------------------- */

/* ----------------------- Data Types Declarations Start-------------------------------- */
typedef enum
{
	/* Cortex-M4 Processor Exceptions Numbers */
	  NonMaskableInt_IRQn = -14,
	  HardFault_IRQn = -13,
	  MemoryManagement_IRQn = -12,
	  BusFault_IRQn = -11,
	  UsageFault_IRQn = -10,
	  SecureFault_IRQn = -9,
	  SVCall_IRQn = -5,
	  DebugMonitor_IRQn = -4,
	  PendSV_IRQn = -2,
	  SysTick_IRQn = -1,
	  WWDG_STM_IRQn = 0,
	  PVD_STM_IRQn = 1,
	  TAMP_STAMP_IRQn = 2,
	  RTC_WKUP_IRQn = 3,
	  FLASH_IRQn = 4,
	  RCC_IRQn = 5,
	  EXTI0  = 6,
	  EXTI1  = 7,
	  EXTI2   = 8,
	  EXTI3  = 9,
	  EXTI4   = 10
	  /* till the end */

}IRQn_Type;


typedef struct
{
	volatile uint32_t ISER[8U];
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];
	uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8U];
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];
	uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8U];
	uint32_t RESERVED4[56U];
	volatile uint8_t IP[240U];
	uint32_t RESERVED5[644U];
	volatile uint32_t STIR;

}NVIC_Type;




/* ----------------------- Data Types Declarations End-------------------------------- */


/* ----------------------- Software Interfaces Declarations Start -------------------------------- */

void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t NVIC_GetActive(IRQn_Type IRQn);

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
uint32_t NVIC_GetPriority(IRQn_Type IRQn);


/* ----------------------- Software Interfaces Declarations End-------------------------------- */


#endif /* CORTEXM4_CORE_NVIC_H_ */
