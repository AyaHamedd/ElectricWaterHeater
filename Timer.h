/* 
 * File:   Timer.h
 * Author: ayaha
 *
 * Created on July 15, 2020, 5:27 PM
 */

#ifndef TIMER_H
#define	TIMER_H

//--------[ Definitions ]--------------------------------
#define TMR1_PRELOAD            63036     /* Preload value of Timer1 */
#define TMR0_PRELOAD            195       /* Preload value of Timer0 */



//-----[ Functions Prototypes ]----------------------------

/********************************************************************************************
 * @fn				- TMR1_Init
 * @brief			- Initialize Timer 1
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void TMR1_Init(void);

/********************************************************************************************
 * @fn				- TMR0_Init
 * @brief			- Initialize Timer 0
 * @param			- none
 * @return			- none
 * @Note			- none
 */
void TMR0_Init(void);
#endif	/* TIMER_H */

