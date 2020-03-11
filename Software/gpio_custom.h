/*
 * gpio_custom.h
 *
 *  Created on: Jan 28, 2020
 *      Author: zeont
 */

#ifndef INC_GPIO_CUSTOM_H_
#define INC_GPIO_CUSTOM_H_
#ifdef __cpluscplus
extern "C"
{
#endif

#include "stm32f401xe.h"
#include "assert.h"

typedef enum //36
{
	PA0 = 0x00,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PB0 = 0x10,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB12 = 0x1C,
	PB13,
	PB14,
	PB15,
	PC13 = 0x2D,
	PC14,
	PC15,
	PH0 = 0x70,
	PH1
}GPIO_PinName;

typedef enum
{
	Input,
	Output,
	Alternate,
	Analog
}GPIO_Mode;

typedef enum
{
	Hi_Z,
	PullUp,
	PullDown
}GPIO_PullUpPullDown;

typedef struct
{
	GPIO_PinName gpioPinName;
	GPIO_Mode gpioMode;
	uint8_t altFunction;
	GPIO_PullUpPullDown gpioPUPD;
}GPIO_InitStruct;


void GPIO_InitPin(GPIO_InitStruct* initStruct);
void GPIO_SetPin(GPIO_PinName pinName, bool assert);

#ifdef __cplusplus
}
#endif


#endif /* INC_GPIO_CUSTOM_H_ */
