#include "buttons.h"
#include "Heater.h"


void    Buttons_Init(void)
{
    ON_OFF_DIR    = INPUT;
    TEMP_DOWN_DIR = INPUT;
    TEMP_UP_DIR   = INPUT;
    OPTION_REGbits.nRBPU = PULL_UP_ENABLE ; // PORTB Pull-up Enable bit.(inverted)
}

Button_State_t Buttons_Read(void)
{
    if(ON_OFF_PIN)
    {
        return BUTTON_OFF;
    }
    else if ( TEMP_DOWN_PIN )
    {
        return BUTTON_DOWN;
    }     
    else if ( TEMP_UP_PIN)
    {
        return BUTTON_UP;
    }
    else
        return BUTTON_NONE;            // If no button is pressed return no operation
}