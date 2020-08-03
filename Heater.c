#include "Heater.h"


void Update_Heating_Elements(void)
{
    uint8_t Temp_Setpoint = Get_Setpoint_Temp();
    uint8_t Temp_Average = Get_Average_Temp();
    
    if (Temp_Average > Temp_Setpoint+5)
    {
        Heating_Led_State = HEATING_LED_OFF;
        HEATER = 0;
        COOLING_LED = 1;
        COOLER = 1;
    }
    else if (Temp_Average < Temp_Setpoint-5)
    {
        COOLING_LED = 0;
        COOLER = 0;
        Heating_Led_State = HEATING_LED_BLINK;
        HEATER = 1;
    }
    else
    {
        COOLING_LED = 0;
        COOLER = 0;
        Heating_Led_State = HEATING_LED_OFF;
        HEATER = 0;   
    }
}

void Enable_Heater(void)
{
    FiveSecondsPassed = 0;
    count10ms = 0;
    count25ms = 0;
    count1s = 0;
    EEPROM_Write(TEMP_INIT,WORD_ADDRESS);    
    SSD_State = SSD_NORMAL;
    Display_State = DISPLAY_SETPOINT_CURRENT;
    Heater_State = HEATER_ON;
}


void Disable_Heater(void)
{
    SSD_State = SSD_OFF;
    Heating_Led_State = HEATING_LED_OFF;
    Heater_State = HEATER_OFF;
    Temp_Setting_Mode = TEMP_SETTING_OFF;
    SSD_Disable();
    HEATER = 0 ;
    COOLER = 0 ;
    HEATING_LED = 0;
    COOLING_LED = 0;
}


void Update_Heater(void)
{
    if ( Heater_State == HEATER_OFF)
        Enable_Heater();
    else if ( Heater_State == HEATER_ON)
        Disable_Heater();   
}
/***********************************************************************************************************/

void Heater_Init(void)
{
    Buttons_Init();
    Elements_init();
    SSD_Init();
    ADC_Init();
    I2C_Master_Init();
    EEPROM_Write(TEMP_INIT,WORD_ADDRESS);
    TMR1_Init();
    TMR0_Init();
    
    /* Reset all variables */     
    FiveSecondsPassed = 0;
    count10ms = 0;
    count25ms = 0;
    count1s = 0;
   
    SSD_State = SSD_OFF;
    Heating_Led_State = HEATING_LED_OFF;
    Display_State = DISPLAY_SETPOINT_CURRENT;
    Heater_State = HEATER_OFF;
    Temp_Setting_Mode = TEMP_SETTING_OFF;
   
}

void Elements_init(void)
{
   /* Configure all elements as output*/
   HEATER_DIR = OUTPUT;
   COOLER_DIR = OUTPUT;
   HEATING_LED_DIR = OUTPUT;
   COOLING_LED_DIR = OUTPUT;
   
   /* Reset all elements */
   HEATER = 0 ;
   COOLER = 0 ;
   HEATING_LED = 0;
   COOLING_LED = 0;
}
