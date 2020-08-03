#include "sevensegment.h"

void SSD_Init      (void)
{
    SSD_DIR = OUTPUT;
    SSD_DATA = OUTPUT;

    SSD_EN1_DIR = OUTPUT;
    SSD_EN2_DIR = OUTPUT;
    
    SSD_DATA = 0;
    SSD_EN1=0;
    SSD_EN2=0;
}

void SSD_Write(unsigned int num)
{
  if(num<=999)
  {
    SevenSeg1_Digits[0] = (num/10)%10;
    SevenSeg1_Digits[1] = num % 10;
  }
}


void SSD_Display(void)
{
    if(Current_Digit==0) 
    {
        SSD_EN1 = 1;
        SSD_EN2 = 0;
        SSD_DATA = Segments_Code[SevenSeg1_Digits[0]];
    }
        
    else if(Current_Digit==1)
    {
        SSD_EN2 = 1;
        SSD_EN1 = 0;
        SSD_DATA = Segments_Code[SevenSeg1_Digits[1]];
    }
        
    Current_Digit++;
    if(Current_Digit==2)
        Current_Digit=0;
}

void SSD_Disable(void)
{
    SSD_EN1=0;
    SSD_EN2=0;
}