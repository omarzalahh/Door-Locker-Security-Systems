 /******************************************************************************
 *
 * Module: TWI(I2C)
 *
 * File Name: twi.h
 *
 * Description: Header file for the TWI(I2C) AVR driver
 *
 * Author: Omar Salah
 *
 *******************************************************************************/

#ifndef TWI_H_
#define TWI_H_

#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define F_CPU 8000000

/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/*Enum for prescaler*/
typedef enum
{
	TWI_NO_PRESCALER,TWI_F_CPU_CLOCK_4,TWI_F_CPU_16,TWI_F_CPU_64

}TWI_Prescaler;

/*Structure contain the prescaler and address device*/
typedef struct
{
	TWI_Prescaler prescaler;
	uint8 deviceAddress;

}TWI_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void TWI_init(const TWI_ConfigType * Config_Ptr);
/*
 * Description :
 * Name:TWI_init
 * Argument:Pointerto the TWI_ConfigType
 * Functional responsible for Initialize the I2C  by:
 * 1. Choose prescaler
 * 2. Choose the device address
 * 3. Enable the I2C
 */
void TWI_start(void);
/*
 * Description :
 * Name:TWI_start
 * Functional responsible for start the I2C :
 * 1. Choose prescaler
 * 2. Choose the device address
 * 3. Enable the I2C
 */
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_getStatus(void);


#endif /* TWI_H_ */
