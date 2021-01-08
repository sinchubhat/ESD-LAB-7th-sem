// LCD
//DOUBLE LINE
#include "lpc214x.h"
#include "stdint.h"
unsignedint cmd8_one[] = {0x38,0x0E,0x02,0x01,0x00};
unsignedint cmd8_two[]= {0X38,0x0E,0x02,0xC0,0x00};
unsigned intmsg_one[] = {'H','e','l','l','o',0x20,'R','I','T',0x20,0x00};
unsigned intmsg_two[] = {'L','i','n','e',0x20,'T','W','O',0x20,0x00};
unsignedintlcdval,index,delay_ms;
voidInitLPC(void)
{
PINSEL0 = 0x00L;
IO0DIR = 0XFFFFFFFF;
}
void Delay(unsigned intdms)
{
delay_ms = dms;
while(delay_ms>0)
delay_ms--;
}
voidInitLCD_one()
{
index=0;
lcdval=cmd8_one[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x400;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=cmd8_one[index];
}
}
voidInitLCD_two()
{
index=0;
lcdval=cmd8_two[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x400;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=cmd8_two[index];
}
}
voidShowMsg_one()
{
index=0;
lcdval=msg_one[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x500;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=msg_one[index];
}
}
voidShowMsg_two()
{
index=0;
lcdval=msg_two[index];
while(lcdval !=0x0)
{
IO0SET = lcdval;
lcdval |= 0x500;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=msg_two[index];
}
}
void main(void)
{
InitLPC();
while(1)
{
InitLCD_one();
ShowMsg_one();
InitLCD_two();
ShowMsg_two();
}
}
