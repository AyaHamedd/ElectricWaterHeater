/* 
 * File:   sevensegment.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 11:04 PM
 */
#ifndef SEVENSEGMENT_H
#define	SEVENSEGMENT_H

#include <xc.h>
#include "stdint.h"


#define _XTAL_FREQ          8000000UL           /* Crystal Frequency    */

//--------[ Definitions ]--------------------------------
/*
 * Seven segment pins Direction macros
 */
#define SSD_DIR             TRISD                  /* Sets the direction of SSD data pins */
#define SSD_DATA            PORTD                  /* Writes to the SSD Data pins         */

/* Seven segment signal pins   */
#define SSD_EN1_DIR         TRISAbits.TRISA3       /* Sets the direction of Enable 1 pin  */
#define SSD_EN2_DIR         TRISAbits.TRISA4       /* Sets the direction of Enable 2 pin  */

#define SSD_EN1             RA3                    /* Writes to the SSD Enable 1 pin       */
#define SSD_EN2             RA4                    /* Writes to the SSD Enable 2 pin       */

#define INPUT               1
#define OUTPUT              0

#define ENABLE              1
#define DISABLE             0


//--------[ Globals ]-------------------------------------
uint8_t Segments_Code[10] = {0x3F,0x30,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};    /* SSD Code representation of digits  */
uint8_t Current_Digit = 0;                     /* Variable that holds the current diplayed digit for multiplexing purpose */
volatile uint8_t SevenSeg1_Digits[2] = {6,0};  /* Array that holds the digits of the Displayed number on SSD              */


//-----[ Functions Prototypes ]----------------------------

/********************************************************************************************
 * @fn				- SSD_Init
 * @brief			- initialize Seven Segments pins
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void SSD_Init(void);

/********************************************************************************************
 * @fn				- SSD_Write
 * @brief			- Writes the given value digits to the SevenSeg1_Digits Array to be displayed
 * @param			- num : Number to be displayed in SSD
 * @return			- none
 * @Note			- none
 */
void SSD_Write(unsigned int num);
void SSD_Disable(void);
void SSD_Display(void);

#endif	/* SEVENSEGMENT_H */

