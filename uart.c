 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#include "uart.h"
#include "avr/io.h" /* To use the UART Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 **********************Functions Definitions************************************
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
void UART_init(const UART_ConfigType * Config_Ptr)
{
	uint16 uber_value = 0;

	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UCSRB = (1<<RXEN) | (1<<TXEN);
	/*decide number of data bits*/
	UCSRB=(UCSRB&0XFB)|(((Config_Ptr->CharSize)&0X04));

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC = (1<<URSEL) ;

	UCSRC=(UCSRC &0XF7 )|((Config_Ptr->StopBit)<<3);//decide the number of stop bits
	UCSRC=(UCSRC&0XF9)|(((Config_Ptr->CharSize)&0X03)<<1);//decide number of data

	/* Calculate the UBRR register value */
	uber_value = (uint16)(((F_CPU / (Config_Ptr->baudRate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = uber_value>>8;
	UBRRL = uber_value;
}

/*******************************************************************
 * Description :
 * Name:UART_sendByte
 * Argument:const uint8 data
 * Functional responsible for send byte to another UART device.
 *******************************************************************/
void UART_sendByte(const uint8 data)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = data;
}

/*******************************************************************
 * Description :
 * Name:UART_recieveByte
 * Functional responsible for receive byte from another UART device.
 *******************************************************************/
uint8 UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
    return UDR;
}

/*******************************************************************
 * Description :
 * Name:UART_sendString
 * Argument:Pointer const uint8 *Str
 * Send the required string through UART to the other UART device.
 *******************************************************************/
void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

/*******************************************************************
 * Description :
 * Name:UART_receiveString
 * Argument:Pointer uint8 *Str
 * Receive the required string until the '#' symbol through UART from the other UART device.
 *******************************************************************/
void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
