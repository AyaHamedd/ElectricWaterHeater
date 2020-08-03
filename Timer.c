#include<xc.h>
#include"Timer.h"


void TMR1_Init(void)
{
  TMR1=TMR1_PRELOAD;    //TMR0 Initiation 10ms
  TMR1CS = 0;           //Choosing to work with internal clk
  T1CKPS0 = 1;          // 1:8 prescale value
  T1CKPS1 = 1;
  TMR1ON = 1;
  TMR1IE = 1;
  TMR1IF = 0;
  PEIE = 1;
  GIE = 1;
}
void TMR0_Init(void)
{
  TMR0=TMR0_PRELOAD;        //TMR0 Initiation 25ms
  T0CS=0;                   //Choosing to work with internal clk
  T0SE=0;                   //Reacting on Low2High edge
  PSA=0;                    //Choosing to work with a Prescaler
  PS0=1;
  PS1=1;                    //Prescaler value divides 256
  PS2=1;
  TMR0IE = 1;
  TMR0IF = 0;  
  PEIE = 1;
  GIE = 1;
}