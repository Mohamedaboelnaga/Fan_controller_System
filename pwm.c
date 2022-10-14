/*
 * pwm.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "pwm.h"

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0

	/*the value of duty cycle in % is given to this function to multiply by 256/100 to convert
	 * this number to a value from 0 to 255 to be stored in the compare register to generate the required
	 *PWM signal
	 * e.g: duty_cycle is 25 , so 25 *(256/100) = 64 , so 64 is stored in the OCR0
	 */
	uint8 value;
	if(duty_cycle==100) OCR0=255;
	else
	{
		value=(uint8)(((uint16)(duty_cycle*256))/100);
		OCR0  =value;
	}
	// Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	//this pin is connected to the enable of the motor to control the speed using the generated PWM
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

