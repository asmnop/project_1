/*
 * software_timers.c
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */


#include "tim.h"

void init_software_timers(TIM_HandleTypeDef *htim)
{
	static uint16_t counter = 0;

	if(htim->Instance == TIM7)
	{
		counter++;
		if(counter == 100)
		{
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			counter = 0;
		}

	}

}
