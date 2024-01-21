 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the Motor driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
/*******************************************************************************/
/*****************************Includes*****************************************/
#include "std_types.h"
/*******************************************************************************/
/*****************************Defines*****************************************/
#define F_CPU 8000000

#define PORTA_MOTOR     PORTC_ID
#define PINA_MOTOR      PIN2_ID
#define PORTB_MOTOR     PORTC_ID
#define PINB_MOTOR      PIN3_ID
/*******************************************************************************/
/*****************************Enumes*****************************************/
typedef enum{
	stop,cw,A_CW}DcMotor_State;
/*******************************************************************************/
/*****************************Functions*****************************************/
/* *******************************************************************************
 * Description :
 * Name:DcMotor_Init
 * This is a function that is used to initialize Motor pins out put
 * Make the motor stop as don't rotate
 ********************************************************************************/
void DcMotor_init(void);
/* *******************************************************************************
 * Description :
 * Name:DcMotor_Rotate
 * This is a function that is used to Rotate the motor counter clock wise or clock wise or stop
 ********************************************************************************/
void DcMotor_rotate(DcMotor_State state);

#endif /* MOTOR_H_ */
