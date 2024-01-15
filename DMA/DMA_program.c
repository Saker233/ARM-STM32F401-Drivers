/*
 * DMA_program.c
 *
 *  Created on: Jan 15, 2024
 *      Author: Saker
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_registers.h"



void DMA_voidInit()
{
	CLR_BIT(DMA2->S[0].CR, 0);
	DMA2->S[0].CR |= ((1 << 14) | (1 << 12) | (1 << 10) | (1 << 9) | (1 << 7) | (1 << 4));
	DMA2->S[0].FCR |= ((1 << 2) | (1 << 1) | (1 << 0));

}

void DMA_coidSetStream(u8 StreamID, u32 * Pu32SrcAddress, u32 * PuDesAddress, u32 BlockSize)
{
	DMA2->S[StreamID].PAR = Pu32SrcAddress;
	DMA2->S[StreamID].M0AR = PuDesAddress;
	DMA2->S[StreamID].NDTR = BlockSize;

}

void DMA_voidEnable(u8 StreamID)
{
	DMA2->LIFCR |= ((1 << 0) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
	SET_BIT(DMA2->S[StreamID].CR, 0);
}

void DMA_voidSetStreamCallBack(u8 StreamID, void(*ptr_func)(void))
{

}
