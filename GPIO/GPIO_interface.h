/*
 * GPIO_interface.h
 *
 *  Created on: Jan 10, 2024
 *      Author: Saker
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_



#define GPIO_u8LOW						0
#define GPIO_u8HIGH						1


#define GPIOA_u8PORT					0
#define GPIOB_u8PORT					1
#define GPIOC_u8PORT					2


#define GPIOA_u8UNPUT					0b00
#define GPIOA_u8OUTPUT					0b01
#define GPIOA_u8ALTFUNC					0b10
#define GPIOA_u8ANALOG					0b11


#define GPIO_u8PUSHPULL					0
#define GPIO_u8OPENDRAIN				1


#define GPIO_u8LOWSPEED					0b00
#define GPIO_u8MEDSPEED					0b01
#define GPIO_u8HIGHSPEED				0b10
#define GPIO_u8VERYHIGHSPEED			0b11


#define	GPIO_u8NOPP						0b00
#define	GPIO_u8PULLUO					0b01
#define	GPIO_u8PULLDOWN					0b10





void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);


void GPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type);


void GPIO_voidOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed);


void GPIO_voidSetPull(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType);


u8	 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);


void GPIO_voidDirectSetReset(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8BValue);



#endif /* GPIO_GPIO_INTERFACE_H_ */
