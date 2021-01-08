// LED
//COUNTER
#include "lpc214x.h"
#include "stdint.h"
unsignedintdelay_ms,led_val;
unsigned char index;
voidInitLPC(void)
{
PINSEL0 = 0x00L;
IODIR = 0XFFFFFFFF;
}
void Delay(unsigned intdms)
{
delay_ms = dms;
while(delay_ms> 0)
delay_ms--;
}
main()
{
index=0;
InitLPC();
while(1)
{
index&= 0xffffffff;
led_val = index++;
IOSET =led_val;
Delay(200000);
IOCLR=0xFFFFFFFF;
}
}
