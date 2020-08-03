/* 
 * File:   i2c.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 5:20 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "stdint.h"

//--------[ Definitions ]--------------------------------
#define _XTAL_FREQ 8000000UL        /* Crystal Frequency    */
#define BAUDRATE    9600UL          /* I2C Baude Rate       */

/*
 * I2C Clock and Data lines pins definitions 
 */
#define I2C_SDA C4
#define I2C_SCK C3



/********************************************************************************************
 * @fn				- I2C_Master_Init
 * @brief			- This function Intialize I2C bus
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_Master_Init(void);

/********************************************************************************************
 * @fn				- I2C_Master_Wait
 * @brief			- This function Wait till the bus is idle
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_Master_Wait(void);


/********************************************************************************************
 * @fn				- I2C_Master_Start
 * @brief			- This function is used to generate I2C Start Condition.
 *                    Start Condition: SDA goes low when SCL is High.
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_Master_Start(void);

/********************************************************************************************
 * @fn				- I2C_Master_RepeatedStart
 * @brief			- Send a Repeated Start Condition
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_Master_RepeatedStart(void);


/********************************************************************************************
 * @fn				- I2C_Master_Stop
 * @brief			- Generate I2C Stop Condition.                   Stop Condition: SDA goes High when SCL is High.
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_Master_Stop(void);


/********************************************************************************************
 * @fn				- I2C_Master_NACK
 * @brief			- Generate a NACK bit
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void I2C_NACK(void);


/********************************************************************************************
 * @fn				- I2C_Master_Write
 * @brief			- Send a one byte Data on the bus
 * @param			- data : one byte data to be sent
 * @return			- ACK status
 * @Note			- none
 */
uint8_t I2C_Master_Write(uint8_t data);

/********************************************************************************************
 * @fn				- I2C_Read_Byte
 * @brief			- Receive one byte data 
 * @param			- none
 * @return			- ACK status
 * @Note			- none
 */
uint8_t I2C_Read_Byte(void);

#endif	/* I2C_H */

