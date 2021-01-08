//triangle
#include "lpc214x.h"
#include "stdint.h"
int main (void)
{
uint16_t value;
uint16_t i = 0;
PINSEL1 = 0x00080000;
IO0DIR = 0xFFFFFFFF;
while(1)
{
i=0;
while(i!=1023)
{
DACR=i*50;
i++;
}
i=1023;
while(i!=0)
{
DACR=i*50;
i--;
}
}
}
