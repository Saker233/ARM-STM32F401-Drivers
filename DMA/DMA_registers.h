/*
 * DMA_registers.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Saker
 */

#ifndef DMA_REGISTERS_H_
#define DMA_REGISTERS_H_

#define DMA1_BASE_ADDRESS 			0x40026000
#define DMA2_BASE_ADDRESS 			0x40026000

typedef struct
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_stream_t;


typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_stream_t S[8];
}DMA_Mem_t;

#define DMA2		((volatile DMA_Mem_t *)(DMA2_BASE_ADDRESS))





#endif /* DMA_REGISTERS_H_ */
