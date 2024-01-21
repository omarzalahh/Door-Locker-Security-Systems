 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the External EEPROM Memory
 *
 * Author: Omar Salah
 *
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_
/*******************************************************************************/\
/*****************************Defines*******************************************/
#define BUZZER_PORT     PORTC_ID
#define PINA_BUUZER      PIN4_ID
/*******************************************************************************/
/*****************************Functions*******************************************/
/* *******************************************************************************
 * Description :
 * Name:Buzzer_Init
 * This is a function that is used to initialize Buzzer pin out put
 * Make the Buzzer logic low
 ********************************************************************************/
void Buzzer_init(void);
/* *******************************************************************************
 * Description :
 * Name:Buzzer_ON
 * This is a function that is used to start the buzzer sound
 ********************************************************************************/
void Buzzer_ON(void);
/* *******************************************************************************
 * Description :
 * Name:Buzzer_Stop
 * This is a function that is used to stop the buzzer sound
 ********************************************************************************/
void Buzzer_Stop(void);

#endif /* BUZZER_H_ */
