/*
 * LED.c
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */


#include "LED.h"




void LED_tog(pin_t pin)
{
	HAL_GPIO_TogglePin(pin.port, pin.pin);
}


void LED_state(pin_t pin, uint8_t state)
{
	HAL_GPIO_WritePin(pin.port, pin.pin, state);
}



