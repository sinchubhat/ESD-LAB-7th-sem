//SQUARE
#include "lpc214x.h"
#include "stdint.h"
voiddelay_ms(uint16_t j)
{
uint16_tx,i;
for(i=0;i<j;i++)
for(x=0; x<6000; x++);
}
int main (void)
{
uint16_t value;
uint16_t i = 0;
PINSEL1 = 0x00080000;
IO0DIR = 0xFFFFFFFF;
while(1)
{
DACR=1023*50;
delay_ms(10);
DACR=0;
delay_ms(10);
}
}
