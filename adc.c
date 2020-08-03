#include "adc.h"

void ADC_Init()
{
  TRISAbits.TRISA2 |= 1;    // Configure RA2 as input
  ADCON0 = 0x51;            // Turn ADC ON, Select AN2 Channel, ADC Clock = Fosc
  ADCON1 = 0xC0;            // All 8 Channels Are Analog, Result is "Right-Justified"
}

uint16_t ADC_Read(void)
{
    GO_DONE = 1;                        // Start A/D Conversion
    while(ADCON0bits.GO_DONE);          // Polling GO_DONE Bit
    ADIF = 0;                           // Clear ADC Flag
    return ((ADRESH << 8) + ADRESL);        
}

