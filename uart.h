 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#define F_CPU 8000000

/*******************************************************************************
 ***********************Types Declaration***************************************
 *******************************************************************************/
typedef enum
{
ONE_STOP_BIT,TWO_STOP_BIT
}UART_Stop;

typedef enum
{
FIVE_BIT,SIX_BIT,SEVEN_BIT,EIGHT_BIT,NINE_BIT=7
}UART_CharSize;
typedef enum
{
DISABLED,EVEN=2,ODD
}UART_ParityMode;

typedef struct
{
	UART_Stop StopBit;
	UART_CharSize CharSize;
	uint32 baudRate;
	UART_ParityMode parity;
}UART_ConfigType;

/*******************************************************************************
 ***********************Functions Prototypes************************************
 *******************************************************************************/
/*******************************************************************
 * Description :
 * Name:UART_init
 * Argument:uint32 baud_rate,pointer const UART_ConfigType * Config_Ptr
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 *******************************************************************/
void UART_init(const UART_ConfigType * Config_Ptr);
/*******************************************************************
 * Description :
 * Name:UART_sendByte
 * Argument:const uint8 data
 * Functional responsible for send byte to another UART device.
 *******************************************************************/
void UART_sendByte(const uint8 data);
/*******************************************************************
 * Description :
 * Name:UART_recieveByte
 * Functional responsible for receive byte from another UART device.
 *******************************************************************/
uint8 UART_recieveByte(void);
/*******************************************************************
 * Description :
 * Name:UART_sendString
 * Argument:Pointer const uint8 *Str
 * Send the required string through UART to the other UART device.
 *******************************************************************/
void UART_sendString(const uint8 *Str);
/*******************************************************************
 * Description :
 * Name:UART_receiveString
 * Argument:Pointer uint8 *Str
 * Receive the required string until the '#' symbol through UART from the other UART device.
 *******************************************************************/
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
