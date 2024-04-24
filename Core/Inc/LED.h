/*
 * LED.h
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
}line_t;


static const line_t LED[] =
{
	{ LED_1_GPIO_Port, LED_1_Pin },
	{ LED_2_GPIO_Port, LED_2_Pin },
	{ LED_3_GPIO_Port, LED_3_Pin },
	{ LED_4_GPIO_Port, LED_4_Pin },
	{ LED_5_GPIO_Port, LED_5_Pin },
	{ LED_6_GPIO_Port, LED_6_Pin },
	{ LED_7_GPIO_Port, LED_7_Pin },
	{ LED_8_GPIO_Port, LED_8_Pin },
};

void LED_tog(line_t pin);
void LED_state(line_t pin, uint8_t state);


#endif /* INC_LED_H_ */
