/* 
 * File:   adc.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 5:35 PM
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include "stdint.h"

//--------[ Definitions ]--------------------------------
#define _XTAL_FREQ 8000000UL        /* Crystal Frequency  */


//-----[ Globals ]-----------------------------------------
volatile uint16_t AN2RES = 0;       /* ADC Result                                   */


//-----[ Functions Prototypes ]----------------------------
void ADC_Init(void);

/********************************************************************************************
 * @fn				- ADC_Read
 * @brief			- Reads the value of ADC  
 * @param			- none
 * @return			- The digital value 
 * @Note			- none
 */
uint16_t ADC_Read(void);


#endif	/* ADC_H */

