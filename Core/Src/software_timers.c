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

void init_software_timers(TIM_HandleTypeDef *htim)
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

	}

}
