/*
 * motor.h
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */

#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum
{
	off,clockwise,anticlockwise
}DcMotor_State;
/*
 *  The Function responsible for setup the direction for the two
motor pins through the GPIO driver and  Stop at the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void);


/*
 * The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value and
send the required duty cycle to the PWM driver based on the
required speed value.
 *
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
