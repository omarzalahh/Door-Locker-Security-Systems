 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: source file for the Motor driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/
#include"motor.h"
#include"common_macros.h"
#include"gpio.h"
/* *******************************************************************************
 * Description :
 * Name:DcMotor_Init
 * This is a function that is used to initialize Motor pins out put
 * Make the motor stop as don't rotate
 ********************************************************************************/
void DcMotor_init(void)
{
	GPIO_setupPinDirection(PORTA_MOTOR, PINA_MOTOR,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_MOTOR, PINB_MOTOR,PIN_OUTPUT);

	GPIO_writePin(PORTA_MOTOR, PINA_MOTOR, LOGIC_LOW);
	GPIO_writePin(PORTA_MOTOR, PINB_MOTOR, LOGIC_LOW);
}

/* *******************************************************************************
 * Description :
 * Name:DcMotor_Rotate
 * This is a function that is used to Rotate the motor counter clock wise or clock wise or stop
 ********************************************************************************/
void DcMotor_rotate(DcMotor_State state)
{

	if(state == stop)//condition to determine the direction of rotation of the motor
		{
			GPIO_writePin(PORTA_MOTOR, PINA_MOTOR, LOGIC_LOW);
			GPIO_writePin(PORTB_MOTOR, PINB_MOTOR, LOGIC_LOW);
		}
	else if(state == A_CW)
		{
			GPIO_writePin(PORTA_MOTOR, PINA_MOTOR, LOGIC_LOW);
			GPIO_writePin(PORTB_MOTOR, PINB_MOTOR, LOGIC_HIGH);
		}
	else if(state == cw)
		{
			GPIO_writePin(PORTA_MOTOR, PINA_MOTOR, LOGIC_HIGH);
			GPIO_writePin(PORTB_MOTOR, PINB_MOTOR, LOGIC_LOW);
		}
}
