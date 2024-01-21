/******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: timer0.h
 *
 * Description: Header file for the AVR Timer0 driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_types.h"

#define F_CPU 8000000


/*******************************************************************************
 ***************************Types Declaration***********************************
 *******************************************************************************/
/*******************************************************************************
 ************************** Enum for the prescaler******************************
 *******************************************************************************/
typedef enum
{
	TIMER_NO_CLOCK,TIMER_F_CPU_CLOCK,TIMER_F_CPU_8,TIMER_F_CPU_64,TIMER_F_CPU_256,TIMER_F_CPU_1024
}Timer0_Prescaler;

/********************************************************************************
 ************************Enum for overflow mode or Compare mode******************
 ********************************************************************************/
typedef enum
{
	OVF,CTC
}Timer0_Mode;

/********************************************************************************
 *********Structure that contain the prescaler ,mode,initial value,compare value*
 ********************************************************************************/
typedef struct
{
	Timer0_Prescaler prescaler;
	Timer0_Mode mode;
	uint16 initial_value;
	uint16 compare_value;
}Timer0_ConfigType;
/*******************************************************************************
 *****************************Functions Prototypes******************************
 *******************************************************************************/

/* *******************************************************************************
 * Description :
 * Name:Timer0_Init
 * This is a function that is used to initialize Timer0
 * Timer0 could be initialized in compare mode or in over flow mode
 * we can determine the required frequency on which timer operate by using prescaler
 ********************************************************************************/
void Timer0_init(const Timer0_ConfigType * Config_Ptr);
/* *******************************************************************************
 * Description:
 * Name:Timer0_setCallBack
 * Argument:void(*a_ptr) (pointer to a function)
 *Function to set the Call Back function address.
 ********************************************************************************/
void Timer0_setCallBack(void(*a_ptr)(void));
/********************************************************************************
 * Description:
 * Name : Timer0_Deinit
 *Function to disable the Timer0 to stop Timer0
 ********************************************************************************/
void Timer0_Deinit(void);
#endif /* TIMER0_H_ */
