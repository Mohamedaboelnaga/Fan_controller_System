/*
 * fan_controller_main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */


#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "pwm.h"

int main(void)
{
	ADC_ConfigType adc_Config = {INTERNAL_VOLTAGE,F_CPU_8}; // initial values of the structure
	uint8 temp=0; //a variable to store the temperature from the temp. sensor in it
	LCD_init(); /* initialize LCD driver */
	ADC_init(&adc_Config); /* initialize ADC driver */
	DcMotor_Init();/* initialize MOTOR driver */
	/* Display this string "Fan is =   " only once on LCD at the first row in the middle */
	LCD_moveCursor(0,4);
	LCD_displayString("Fan is ");
	/* Display this string "Temp =   " only once on LCD at the second row in the middle */
	LCD_moveCursor(1,4);
	LCD_displayString("Temp =");
	while(1)
	{   //every time the temp value will appear at this place ( second row after the string "Temp =" )
		LCD_moveCursor(1,10);
		temp = LM35_getTemperature();
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		if(temp<30) // 1st case , the motor is off
		{
			LCD_moveCursor(0,11);//write the state of the motor after the string "fan is"
			LCD_displayString("off");
			DcMotor_Rotate(off,zero_speed);
		}
		else if(temp>=30&&temp<60) // 2nd case , 25% of motor's max speed
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON");//write the state of the motor after the string "fan is"
			LCD_displayCharacter(' ');//to avoid writing "onf" when going from "off" to "on"
			DcMotor_Rotate(clockwise,quarter_speed);
		}
		else if(temp>=60&&temp<90)// 3rd case , 50% of motor's max speed
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON");//write the state of the motor after the string "fan is"
			DcMotor_Rotate(clockwise,half_speed);
		}
		else if(temp>=90&&temp<120)// 4th case , 75% of motor's max speed
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON");//write the state of the motor after the string "fan is"
			DcMotor_Rotate(clockwise,max_minus_quarter_speed);
		}
		else if(temp>=120)// 5th case,  100%  ( max speed)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			DcMotor_Rotate(clockwise,max_speed);
		}
	}
}
