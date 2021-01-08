// LCD
//SINGLE LINE
#include "lpc214x.h"
#include "stdint.h"
unsignedint cmd8[] = {0X38,0x38,0x0E,0x02,0x01,0x00};
unsigned intmsg[] = {'H','e','l','l','o',0x20,'R','I','T',0x20,0x00};
unsignedintlcdval,index,delay_ms;
voidInitLPC(void)
{
PINSEL0 = 0x00L;
IO0DIR = 0XFFFFFFFF;
}
void Delay(unsigned intdms)
{
delay_ms = dms;
while(delay_ms> 0)
{
delay_ms--;
}
}
Void InitLCD()
{
index=0;
lcdval=cmd8[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x400;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=cmd8[index];
}
}
voidShowMsg()
{
index=0;
lcdval=msg[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x500;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=msg[index];
}
}
void main(void)
{
InitLPC();
while(1)
{
InitLCD();
ShowMsg();
Delay(5000);
}
}
