/*
 * motor.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */

#include "pwm.h"
#include "gpio.h"
#include "motor.h"

void DcMotor_Init(void)
{
	// set up PB0 , PB1 as OUTPUT pins ( 2 pins of the motor)
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	// write logic low (zero) on  PB0 , PB1 initially ( motor is off)
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch(state)
	{   //if the motor state is off, write logic low on the 2 pins of the motor
	case off:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
		//if the motor state is clockwise, write logic low on the 1st pin and
		//logic high on the other pin of the  2 pins of the motor
	case clockwise:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
		break;
		//if the motor state is clockwise, write logic high on the 1st pin and
		//logic low on the other pin of the  2 pins of the motor
	case anticlockwise:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	}
	/*
	 * the given speed to the function will be passed to the PWM function to generate w PWM signal
	 * that controls the speed of the motor by connecting the output pin of the PWM on the enable
	 * of the motor
	 */
	PWM_Timer0_Start(speed);
}

