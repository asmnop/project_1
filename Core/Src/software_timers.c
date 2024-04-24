/*
 * software_timers.c
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */


#include "tim.h"

volatile uint16_t timer_1 = 0;
volatile uint16_t timer_2 = 0;
volatile uint16_t timer_3 = 0;

volatile uint16_t timer_LED_1 = 0;
volatile uint16_t timer_LED_2 = 0;
volatile uint16_t timer_LED_3 = 0;
volatile uint16_t timer_LED_4 = 0;
volatile uint16_t timer_LED_5 = 0;
volatile uint16_t timer_LED_6 = 0;
volatile uint16_t timer_LED_7 = 0;
volatile uint16_t timer_LED_8 = 0;

void software_timers(TIM_HandleTypeDef *htim)
{
	static uint16_t counter = 0;

	if(htim->Instance == TIM7)
	{
		counter++;
		if(counter == 100)
		{
			//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			counter = 0;
		}

		if(timer_1)		timer_1--;
		if(timer_2)		timer_2--;
		if(timer_3)		timer_3--;

		if(timer_LED_1)		timer_LED_1--;
		if(timer_LED_2)		timer_LED_2--;
		if(timer_LED_3)		timer_LED_3--;
		if(timer_LED_4)		timer_LED_4--;
		if(timer_LED_5)		timer_LED_5--;
		if(timer_LED_6)		timer_LED_6--;
		if(timer_LED_7)		timer_LED_7--;
		if(timer_LED_8)		timer_LED_8--;

	}

}
