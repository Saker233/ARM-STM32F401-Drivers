/*
 * GPIO_program.c
 *
 *  Created on: Jan 10, 2024
 *      Author: Saker
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_register.h"




void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case GPIOA_u8PORT : GPIOA->MODER &= ~((0b11)<<(Copy_u8Pin * 2));
						GPIOA->MODER |= (Copy_u8Mode << (Copy_u8Pin * 2));
						break;
	case GPIOB_u8PORT : GPIOB->MODER &= ~((0b11)<<(Copy_u8Pin * 2));
						GPIOB->MODER |= (Copy_u8Mode << (Copy_u8Pin * 2));
						break;
	case GPIOC_u8PORT : GPIOC->MODER &= ~((0b11)<<(Copy_u8Pin * 2));
						GPIOC->MODER |= (Copy_u8Mode << (Copy_u8Pin * 2));
						break;
	}
}


void GPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
	switch(Copy_u8Port)
	{

	case GPIOA_u8PORT : GPIOA -> OTYPER &= ~((1)<<(Copy_u8Pin));
						GPIOA -> OTYPER |= (Copy_u8Type << Copy_u8Pin);
						break;
	case GPIOB_u8PORT : GPIOB -> OTYPER &= ~((1)<<(Copy_u8Pin));
						GPIOB -> OTYPER |= (Copy_u8Type << Copy_u8Pin);
						break;
	case GPIOC_u8PORT : GPIOC -> OTYPER &= ~((1)<<(Copy_u8Pin));
						GPIOC -> OTYPER |= (Copy_u8Type << Copy_u8Pin);
						break;
	}
}


void GPIO_voidOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed)
{
	switch (Copy_u8Port)
		{
		   case GPIOA_u8PORT :GPIOA -> OSPEEDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
		   	   	  	   	   	   GPIOA -> OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin*2)) ;
		                      break;
		   case GPIOB_u8PORT :GPIOB -> OSPEEDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
						GPIOB -> OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin*2)) ;
						break;
		   case GPIOC_u8PORT :GPIOC -> OSPEEDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
							GPIOC -> OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin*2)) ;
								break;
		}
}


void GPIO_voidSetPull(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType)
{
	switch (Copy_u8Port)
			{
			   case GPIOA_u8PORT : GPIOA -> PUPDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
			   	   	   	   	   	   GPIOA -> PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2)) ;
			                        break;
			   case GPIOB_u8PORT : GPIOB -> PUPDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
									GPIOB -> PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2)) ;
									break;
			   case GPIOC_u8PORT : GPIOC -> PUPDR &= ~((0b11)<<(Copy_u8Pin*2)) ;
									GPIOC -> PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2)) ;
									break;
			}
}


u8	 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8PinValue;
	switch(Copy_u8Port)
	{
	case GPIOA_u8PORT : Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8Pin); break;
	case GPIOB_u8PORT : Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8Pin); break;
	case GPIOC_u8PORT : Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8Pin); break;
	}
	return Local_u8PinValue;
}


void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if(Copy_u8Value == GPIO_u8LOW)
	{
		switch(Copy_u8Port)
		{
		case GPIOA_u8PORT : CLR_BIT(GPIOA->ODR, Copy_u8Pin); break;
		case GPIOB_u8PORT : CLR_BIT(GPIOB->ODR, Copy_u8Pin); break;
		case GPIOC_u8PORT : CLR_BIT(GPIOC->ODR, Copy_u8Pin); break;
		}
	}
	else if(Copy_u8Value == GPIO_u8HIGH)
	{
		switch(Copy_u8Port)
		{
		case GPIOA_u8PORT : SET_BIT(GPIOA->ODR, Copy_u8Pin); break;
		case GPIOB_u8PORT : SET_BIT(GPIOB->ODR, Copy_u8Pin); break;
		case GPIOC_u8PORT : SET_BIT(GPIOC->ODR, Copy_u8Pin); break;
		}
	}
}


void GPIO_voidDirectSetReset(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8BValue)
{
	if(Copy_u8BValue == GPIO_u8HIGH)
	{

		switch(Copy_u8Port)
		{
		case GPIOA_u8PORT : GPIOA -> BSRR = (1 << Copy_u8Pin); break;
		case GPIOB_u8PORT : GPIOB -> BSRR = (1 << Copy_u8Pin); break;
		case GPIOC_u8PORT : GPIOC -> BSRR = (1 << Copy_u8Pin); break;

		}
	}
	else if(Copy_u8BValue == GPIO_u8HIGH)
	{
		Copy_u8Pin += 16;
		switch(Copy_u8Port)
		{
		case GPIOA_u8PORT : GPIOA -> BSRR = (1 << Copy_u8Pin); break;
		case GPIOB_u8PORT : GPIOB -> BSRR = (1 << Copy_u8Pin); break;
		case GPIOC_u8PORT : GPIOC -> BSRR = (1 << Copy_u8Pin); break;
		}
	}
}
