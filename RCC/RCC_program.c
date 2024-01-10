/*
	Author : Mohamed Saker
	Date   : 10/1/2024
	Content : Functions Implementation




*/

#include "STD_TYPES.h"
#include "BIT_MATH.h

#include "RCC_interface.h"
#include "RCC_registers.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSystemCLK();
{
	#if MRCC_CLKSRC == HSI
		/* Enable the HSI */
		SET_BIT(RCC_CR, 0U);
		/* Select the HSI for the system */
		CLR_BIT(RCC_CFGR, 0U);
		CLR_BIT(RCC_CFGR, 1U);
		
	#elif MRCC_CLKSRC == HSE
	
		#if  MCC_HSE_SRC == HSE_CRYSTAL
		/* Enable the HSE */
		SET_BIT(RCC_CR, 16U);
		
		/* Disable the bypass */
		CLR_BIT(RCC_CR, 18U);
		
		/* Select the HSE for the system */
		CLR_BIT(RCC_CFGR, 0U);
		SET_BIT(RCC_CFGR, 1U);
		
		#elif MCC_HSE_SRC == HSE_RC
		/* Enable the HSE */
		SET_BIT(RCC_CR, 16U);
		
		/* Disable the bypass */
		SET_BIT(RCC_CR, 18U);
		
		/* Select the HSE for the system */
		CLR_BIT(RCC_CFGR, 0U);
		SET_BIT(RCC_CFGR, 1U);
		#endif
	#endif
		
}

void MRCC_voidEnablePeripheralClock(BusName_t A_u8BusID, u8 A_u8PerNum)
{
	switch(A_u8BusID)
	{
		case AHB1 : 
		SET_BIT(RCC_AHB1ENR, A_u8PerNum);
		break;
		case AHB2 :
		SET_BIT(RCC_AHB2ENR, A_u8PerNum);
		break;
		case APB1 :
		SET_BIT(RCC_APB1ENR, A_u8PerNum);
		break;
		case APB2 :
		SET_BIT(RCC_APB2ENR, A_u8PerNum);
		
		default:
		break;
		/* ERROR */
	
	
	
	}
}

void MRCC_voidDisablePeripheralClock(BusName_t A_u8BusID, u8 A_u8PerNum)
{
	case AHB1 : 
		CLR_BIT(RCC_AHB1ENR, A_u8PerNum);
		break;
		case AHB2 :
		CLR_BIT(RCC_AHB2ENR, A_u8PerNum);
		break;
		case APB1 :
		CLR_BIT(RCC_APB1ENR, A_u8PerNum);
		break;
		case APB2 :
		CLR_BIT(RCC_APB2ENR, A_u8PerNum);
		
		default:
		break;
		/* ERROR */
}


