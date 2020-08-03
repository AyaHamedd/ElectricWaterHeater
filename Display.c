#include "Display.h"


void Display(void)
{
    if ( (SSD_State == SSD_BLINK) && (count10ms > 100) )
    {
        SSD_EN1=0;
        SSD_EN2=0;
        return;
    }
    SSD_Display();
}


void Update_Display(void)
{
    uint8_t DisplayedTemp=0;
    /******************Update Value of Temperature to be Displayed */     
    if(Temp_Setting_Mode == TEMP_SETTING_ON)
    {
        DisplayedTemp = Get_Setpoint_Temp(); // READ SETPOINT TEMPERATURE
        SSD_State = SSD_BLINK;
    }
    else
    {
        DisplayedTemp = Get_Current_Temp();
        SSD_State = SSD_NORMAL;
    }
    SSD_Write(DisplayedTemp);
}

