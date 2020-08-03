/* 
 * File:   Temp.h
 * Author: ayaha
 *
 * Created on August 3, 2020, 6:28 PM
 */

#ifndef TEMP_H
#define	TEMP_H

#include "stdint.h"

enum { TEMP_SETTING_OFF , TEMP_SETTING_ON} Temp_Setting_Mode;

volatile uint16_t TempArray[10];                /* Array that holds the last 10 readings of Temp*/
volatile uint8_t Temp_index=0;

uint8_t  Get_Average_Temp(void);
void Update_Temp_Setpoint(uint8_t Button);
void UpdateTempArray(uint16_t Temperature);
uint8_t Get_Current_Temp(void);
uint8_t Get_Setpoint_Temp(void);
#endif	/* TEMP_H */

