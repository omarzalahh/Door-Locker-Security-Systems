 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.c
 *
 * Description: Source file for the External EEPROM Memory
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#include "gpio.h"
#include "buzzer.h"
/* *******************************************************************************
 * Description :
 * Name:Buzzer_Init
 * This is a function that is used to initialize Buzzer pin out put
 * Make the Buzzer logic low
 ********************************************************************************/
void Buzzer_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT, PINA_BUUZER,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT, PINA_BUUZER, LOGIC_LOW);
}
/* *******************************************************************************
 * Description :
 * Name:Buzzer_ON
 * This is a function that is used to start the buzzer sound
 ********************************************************************************/
void Buzzer_ON(void)
{
	GPIO_writePin(BUZZER_PORT, PINA_BUUZER, LOGIC_HIGH);
}

void Buzzer_Stop(void)
{
	GPIO_writePin(BUZZER_PORT, PINA_BUUZER, LOGIC_LOW);
}
