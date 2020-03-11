/*
 * timer.c
 *
 *  Created on: 29 Jan 2020
 *      Author: zeont
 */

#include "timer.h"

#define PWM_DUTYCYCLE_PRECISION 1000u

void TIM_InitPWM(TIM_TypeDef* timer, TIM_CHANNEL channel, float freq, uint16_t dutyCycle)
{
	if (timer == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
		assert((RCC->APB2ENR & RCC_APB2ENR_TIM1EN) == RCC_APB2ENR_TIM1EN);
	}

	uint32_t period;
	float prescaler = 0.0f;

	prescaler = (SystemCoreClock / (PWM_DUTYCYCLE_PRECISION + 1) / freq) - 1;
	if (trunc(prescaler) != prescaler)
		prescaler = trunc(prescaler) + 1;//7432,7433
	assert(prescaler <= 65535);

	period = SystemCoreClock / (prescaler + 1 ) / freq - 1;

	timer->ARR = period;
	timer->PSC = prescaler;

	timer->EGR = TIM_EGR_UG;

	timer->CCER &= ~ (TIM_CCER_CC1E << (channel << 2));
	if(channel == Channel_3 || channel == Channel_4)
	{

	}
	else
	{
		timer->CCMR1 &= ~(TIM_CCMR1_OC1M << (channel << 8));
		timer->CCMR1 &= ~(TIM_CCMR1_CC1S << (channel << 8));
		timer->CCMR1 |= ((TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1) << (channel == Channel_1 ? 8 : 0));
	}

	timer->CCR1 = dutyCycle * period / PWM_DUTYCYCLE_PRECISION;
	timer->CCER &= ~ (TIM_CCER_CC1P << (2 << channel));
	timer->CCER |= TIM_CCER_CC1P << ( 2 << channel);
	timer->CCER &= ~ (TIM_CCER_CC1NP << ( 2 << channel));
	timer->CCER |= TIM_CCER_CC1NP << ( 2 << channel);
	timer->CCER &= ~ (TIM_CCER_CC1NP << ( 2 << channel));
	timer->CCER &= ~ (TIM_CCER_CC1NE << ( 2 << channel));
	if(channel == Channel_3 || channel == Channel_4)
		{

		}
		else
		{
			timer->CCMR1 |= ~(TIM_CCMR1_OC1PE << (channel << 8));
			timer->CCMR1 &= ~(TIM_CCMR1_OC1FE << (channel << 8));
		}

	GPIO_InitStruct gpioInitStruct;
	gpioInitStruct.gpioPinName = PA9;
	gpioInitStruct.gpioMode = Alternate;
	gpioInitStruct.altFunction = 1;
	gpioInitStruct.gpioPUPD = Hi_Z;
	GPIO_InitPin(&gpioInitStruct);
}

