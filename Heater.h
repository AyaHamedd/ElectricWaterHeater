/* 
 * File:   Heater.h
 * Author: ayaha
 *
 * Created on July 17, 2020, 12:51 AM
 */

#ifndef HEATER_H
#define	HEATER_H

#include "stdint.h"
#include "Temp.h"
#include "sevensegment.h"
#include "i2c.h"
#include "eeprom.h"
#include "buttons.h"
#include "Timer.h"
#include "config.h"
#include"Display.h"
#include"adc.h"
#include <xc.h>

#define _XTAL_FREQ 8000000UL        /* Crystal Frequency    */

//--------[ Definitions ]--------------------------------

#define HEATING_LED_DIR     TRISBbits.TRISB6                  /* Sets the direction of the Heating led pin  */
#define COOLING_LED_DIR     TRISBbits.TRISB7                  /* Sets the direction of the Cooling led pin  */
#define HEATER_DIR          TRISCbits.TRISC5                  /* Sets the direction of the Heater Button pin*/
#define COOLER_DIR          TRISCbits.TRISC2                  /* Sets the direction of the Cooler Button pin*/

#define HEATING_LED         RB6                               /* Writes to the heating led pin              */
#define COOLING_LED         RB7                               /* Writes to the cooling led pin              */

#define HEATER              RC5                               /* Writes to the Heater pin                   */
#define COOLER              RC2                               /* Writes to the Cooler pin                   */ 

#define INPUT               1
#define OUTPUT              0


//----------------------------------------[ Globals ]-----------------------------------------
volatile uint8_t count25ms = 0;                 /* Counter Increments every 25ms                */
volatile uint8_t count1s = 0;                   /* Counter Increments every 1s                  */
volatile uint8_t FiveSecondsPassed = 0;         /* This variable is set every five sec          */

enum { HEATER_OFF, HEATER_ON} Heater_State;
enum { HEATING_LED_OFF , HEATING_LED_BLINK} Heating_Led_State;


void Heater_Init(void);
void Disable_Heater(void);
void Update_Heater(void);
void Update_Heating_Elements(void);
void Elements_init(void);

#endif	/* HEATER_H */

