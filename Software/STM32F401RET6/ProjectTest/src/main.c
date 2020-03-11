/*
 * main.c
 *
 *  Created on: Feb 9, 2020
 *      Author: zeont
 */

#include "stm32f4xx_gpio.h"

int main()
{
	GPIO_InitTypeDef init;
	init.GPIO_Pin = GPIO_Pin_0;
	init.GPIO_Mode = GPIO_Mode_OUT;
	init.GPIO_Speed = GPIO_High_Speed;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &init);

	return 0;

}
