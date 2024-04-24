/*
 * software_timers.h
 *
 *  Created on: Apr 24, 2024
 *      Author: mm
 */

#ifndef INC_SOFTWARE_TIMERS_H_
#define INC_SOFTWARE_TIMERS_H_

void init_software_timers(TIM_HandleTypeDef *htim);

extern uint16_t timer_1;
extern uint16_t timer_2;
extern uint16_t timer_3;


#endif /* INC_SOFTWARE_TIMERS_H_ */
