/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*
 ********************************Enumerations and structures********************************************
 */

/*
 * enum that saves the values of the VREF required for the adc and takes values
 * either 0 , 1 or 3 according to the data sheet ( value that is equal 2 is reserved in the data-sheet)
 */
typedef enum
{
	AREF=0,AVCC=1,INTERNAL_VOLTAGE=3
} ADC_ReferenceVolatge;


/*
 * enum that saves the values of the required PRE-scalars for the adc
 * and takes the values from 1 to 7 according to their order in the data sheet
 */
typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


/*
 * a structure to be able to control the ref_volt and the PRE-scalar by using a pointer to
 * structure that will access the objects using the arrow operator and choose the value
 * for each object according to the chosen PRE-scalar and v_ref by the user.
 */

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
