 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author:  Omar Salah
 *
 *******************************************************************************/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1
#define F_CPU 8000000


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* *******************************************************************************
 * Description :
 * Name:EEPROM_writeByte
 * This is a function that is used to Write in EEPROM
 * 1-START TWI
 * 2- Send the device address, we need to get A8 A9 A10 address bits from the
 *  memory location address and R/W=0 (write)
 * 3-Send the required memory location address
 * 4-write byte to EEPROM
 * 5-Send the Stop Bit
 ********************************************************************************/
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
/* *******************************************************************************
 * Description :
 * Name:EEPROM_readByte
 * This is a function that is used to read from EEPROM
 * 1-START TWI
 * 2-Send the Start Bit
 * 3-Send the device address, we need to get A8 A9 A10 address bits from the
 *   memory location address and R/W=0 (write)
 * 4-Send the required memory location address
 * 5-Send the Repeated Start Bit
 * 6-Read Byte from Memory without send ACK
 * 7-Send the Stop Bit
 ********************************************************************************/
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
