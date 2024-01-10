/*
	Author : Mohamed Saker
	Date   : 10/1/2024
	Content : Interface file for RCC pripheral




*/

#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H

/* Bus Name */
typedef enum
{
	AHB1 =0,
	AHB2.
	APB1,
	APB2
	
}BusName_t;

/* Peripheral ID */
#define GPIOA_EN				0U
#define GPIOB_EN				1U
#define GPIOC_EN				2U
#define GPIOD_EN				3U
#define GPIOE_EN				4U
#define GPIOH_EN				7U
#define CRC_EN					12U
#define DMA1_EN					21U
#define DMA2_EN					22U


#define SYSCFG_EN				14U
#define UART1_EN				4U




/* Functions Prototypes */
void MRCC_voidInitSystemCLK();

void MRCC_voidEnablePeripheralClock(BusName_t A_u8BusID, u8 A_u8PerNum);

void MRCC_voidDisablePeripheralClock(BusName_t A_u8BusID, u8 A_u8PerNum);



#endif /* MRCC_INTERFACE_H */