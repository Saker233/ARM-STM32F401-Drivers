/*
 * DMA_interface.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Saker
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA_voidInit();

void DMA_coidSetStream(u8 StreamID, u32 * Pu32SrcAddress, u32 * PuDesAddress, u32 BlockSize);

void DMA_voidEnable(u8 StreamID);

void DMA_voidSetStreamCallBack(u8 StreamID, void(*ptr_func)(void));







#endif /* DMA_INTERFACE_H_ */
