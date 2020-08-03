/* 
 * File:   buttons.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 5:22 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#include <xc.h>
#include "stdint.h"

//--------[ Definitiotns ]--------------------------------

#define _XTAL_FREQ 8000000UL        /* Crystal Frequency */

/*
 * I/O pins Definitions 
 */
#define ON_OFF_DIR          (TRISBbits.TRISB0)                  /* Sets the direction of ON/Off Button pin          */
#define TEMP_DOWN_DIR       (TRISBbits.TRISB1)                  /* Sets the direction of Temperature down button pin*/
#define TEMP_UP_DIR         (TRISBbits.TRISB2)                  /* Sets the direction of Temperature up button pin  */

#define TEMP_DOWN_PIN       (!RB1)                              /* Reads the status of the Temp down button pin     */
#define TEMP_UP_PIN         (!RB2)                              /* Reads the status of the Temp up button pin       */
#define ON_OFF_PIN          (!RB0)                              /* Reads the status of the on/off button pin        */

#define PULL_UP_ENABLE      0                                   /* Enable Pull Up Resistor on PORTB                 */
#define PULL_UP_DISABLE     1                                   /* Disable Pull Up Resistor on PORTB                */

/*
 * Temperature definitions
 */
#define TEMP_INIT           (uint8_t)60                         /* Initial value of temperature                         */
#define TEMP_MAX            (uint8_t)75                         /* Max value of temperature                             */
#define TEMP_MIN            (uint8_t)35                         /* Minimum value of temperature                         */
#define TEMP_STEP           (uint8_t)5                          /* One step of incrementing and decrementing temperature*/


typedef enum{ BUTTON_NONE , BUTTON_OFF , BUTTON_UP , BUTTON_DOWN} Button_State_t; /* @Button_State */

void  Buttons_Init(void);

/********************************************************************************************
 * @fn				- Buttons_Read
 * @brief			- Reads Buttons Status
 * @param			- none
 * @return			- Possible Values : @Button_State
 * @Note			- none
 */
Button_State_t Buttons_Read(void);


#endif	/* BUTTONS_H */

