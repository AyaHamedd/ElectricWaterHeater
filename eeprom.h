/* 
 * File:   eeprom.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 5:17 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h>
#include "i2c.h"
#include "stdint.h"

//--------[ Definitions ]--------------------------------
/*
 * EEPROM address macros
 */
#define EEPROM_ADDRESS_W     0b10100000         /* EEPROM Device address for write operations   */
#define EEPROM_ADDRESS_R     0b10100001         /* EEPROM Device address for read operations    */
#define WORD_ADDRESS         0x0010             /* EEPROM Word address                          */


//-----[ Functions Prototypes ]----------------------------

/********************************************************************************************
 * @fn				- EEPROM_Read
 * @brief			- Read value from the specified word address 
 * @param			- Wordadd : Word Address in eeprom
 * @return			- Read 8bit value
 * @Note			- none
 */
uint8_t EEPROM_Read(uint8_t Wordadd);

/********************************************************************************************
 * @fn				- EEPROM_Write
 * @brief			- Writes a value to a specified word address 
 * @param			- Data    : Value to be written 
 *                  - Wordadd : Word Address in eeprom          
 * @return			- none
 * @Note			- none
 */
void    EEPROM_Write(uint8_t Data,uint8_t Wordadd);

#endif	/* EEPROM_H */

