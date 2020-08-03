#include "Heater.h"
#include "Temp.h"


void UpdateTempArray(uint16_t Temperature)
{
    TempArray[Temp_index]=Temperature;       // Insert temperature in array
        Temp_index++;     
        
    if(Temp_index==10)                  // Reset TempIndex to start inserting from 0 again
        Temp_index=0;
}

uint8_t Get_Setpoint_Temp(void)
{
    EEPROM_Read(WORD_ADDRESS);
}

uint8_t Get_Current_Temp(void)
{
    return ( (AN2RES * 0.0048828) / 0.01 ); 
}

uint8_t Get_Average_Temp(void)
{
    uint32_t Total=0;
    for(int i=0; i<10 ; i++)
    {
    Total+=TempArray[i];
    }
    return ( (Total * 0.0048828) / (0.01*10) );
}

void Update_Temp_Setpoint(uint8_t Button)
{
    uint8_t NewTemp  = EEPROM_Read(WORD_ADDRESS) ;
    if ( Button == BUTTON_UP)                 
    {
            NewTemp = NewTemp + TEMP_STEP;
            if ( NewTemp > TEMP_MAX )             // Ensure Temperature is within limits
                NewTemp = TEMP_MAX;
            EEPROM_Write(NewTemp,WORD_ADDRESS);   //Write new Temperature in the memory
    }
        
    else if ( Button == BUTTON_DOWN)
    {
        NewTemp = NewTemp - 5;
        if ( NewTemp < TEMP_MIN )
            NewTemp = TEMP_MIN;
        EEPROM_Write(NewTemp,WORD_ADDRESS);
    }
}