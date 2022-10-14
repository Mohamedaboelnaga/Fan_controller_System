/*
 * pwm.h
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */

#ifndef PWM_H_
#define PWM_H_

#define max_speed 100
#define zero_speed 0
#define quarter_speed 25
#define half_speed 50
#define max_minus_quarter_speed 75

#include "std_types.h"
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
