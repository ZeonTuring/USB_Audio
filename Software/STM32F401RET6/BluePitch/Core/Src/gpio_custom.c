/*
 * gpio_custom.c
 *
 *  Created on: Jan 28, 2020
 *      Author: zeont
 */

#include "gpio_custom.h"

void GPIO_InitPin(GPIO_InitStruct* initStruct)
{
	GPIO_TypeDef* addr = (GPIO_TypeDef*) (GPIOA_BASE + (0x0400 << (initStruct->gpioPinName>>4)));
	uint8_t shift = initStruct->gpioPinName & 0xFF;
	switch (*(uint32_t*)addr)
	{
		case GPIOA_BASE:
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			assert((RCC->AHB1ENR & RCC_AHB1ENR_GPIOAEN) == RCC_AHB1ENR_GPIOAEN);
			break;
		case GPIOB_BASE:
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
			assert((RCC->AHB1ENR & RCC_AHB1ENR_GPIOBEN) == RCC_AHB1ENR_GPIOBEN);
			break;
		case GPIOC_BASE:
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
			assert((RCC->AHB1ENR & RCC_AHB1ENR_GPIOCEN) == RCC_AHB1ENR_GPIOCEN);
			break;
		case GPIOH_BASE:
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
			assert((RCC->AHB1ENR & RCC_AHB1ENR_GPIOHEN) == RCC_AHB1ENR_GPIOHEN);
			break;
		default:
				return;
	}
//	if (((addr->AFR[shift >> 3] >> (shift > 7 ? shift - 8 : shift)) & 0xFF) != 0x00)
//		return;
	if (initStruct->gpioMode == Output || initStruct->gpioMode == Alternate)
	{
		addr->OSPEEDR |= 2 << shift;
	}
	addr->PUPDR |= initStruct->gpioPUPD << shift;
	if(initStruct->gpioMode == Alternate)
	{
		addr->AFR[shift >> 3] |= initStruct->altFunction << (shift > 7 ? shift - 8 : shift);
	}
	addr->MODER |= initStruct->gpioMode << shift;
}


void GPIO_SetPin(GPIO_PinName pinName, bool assert)
{
	GPIO_TypeDef* addr = (GPIO_TypeDef*) (GPIOA_BASE + (0x0400 << (pinName>>4)));
	uint8_t shift = pinName & 0xFF;

	if (((addr->MODER >> shift) & 0xFF) != 2)
		addr->BSRR |= 1 << (assert ? shift : shift + 16);
}
