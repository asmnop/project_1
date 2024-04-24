/*
 * LED.c
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */


#include "LED.h"




void LED_tog(line_t line)
{
	HAL_GPIO_TogglePin(line.port, line.pin);
}


void LED_state(line_t line, uint8_t state)
{
	HAL_GPIO_WritePin(line.port, line.pin, state);
}



