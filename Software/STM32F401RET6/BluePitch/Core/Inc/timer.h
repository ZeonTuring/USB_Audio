/*
 * timer.h
 *
 *  Created on: 29 Jan 2020
 *      Author: zeont
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#ifdef __cpluscplus
extern "C"
{
#endif

#include "stm32f401xe.h"
#include "gpio_custom.h"
#include "assert.h"
#include "math.h"

typedef enum
{
	Channel_1,
	Channel_2,
	Channel_3,
	Channel_4
}TIM_CHANNEL;

void TIM_InitPWM(TIM_TypeDef* timer, TIM_CHANNEL channel, float freq, uint16_t dutyCycle);


#ifdef __cpluscplus
}
#endif

#endif /* INC_TIMER_H_ */
