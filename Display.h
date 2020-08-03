/* 
 * File:   Display.h
 * Author: ayaha
 *
 * Created on August 3, 2020, 6:27 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include "stdint.h"
#include"sevensegment.h"
#include "Temp.h"

enum { DISPLAY_SETPOINT_CURRENT , DISPLAY_CURRENT_TEMP } Display_State;
enum { SSD_OFF , SSD_NORMAL , SSD_BLINK} SSD_State;


volatile uint8_t count10ms = 0;                 /* Counter Increments every 10ms */

/********************************************************************************************
 * @fn				- Update_Display
 * @brief			- Updates Display state and displayed value
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void Update_Display(void);

/********************************************************************************************
 * @fn				- Display_SSD
 * @brief			- Displays temperature value in SSD
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void Display_SSD(void);

#endif	/* DISPLAY_H */

