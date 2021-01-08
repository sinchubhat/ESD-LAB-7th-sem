// 7-Seg
//0-F
#include "lpc214x.h"
#include "stdint.h"
#define IO1 0x10000
#define IOX 0xF0000
#define IOXcl 0xFFFFF
int count=0x0;
unsignedint d0;
unsigned char
seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39
,0x5e,0x79,0x71,0x00};
voidinit_gpio()
{
PINSEL0=0x00000000;
PINSEL1=0x00000000;
PINSEL2=0x00000000;
IO0DIR=0xFFFFFFFF;
IO1DIR=0xFFFFFFFF;
}
void delay()
{
int c=250000;
while(c)
c--;
}
voidshow_disp()
{
//Digit 0
d0=count& 0x0F;
IO0CLR=IOXcl;
IO0SET=seg[d0];
IO1SET=IOX;
IO1CLR=IO1;
delay();
IO1SET=IOXcl;
}
int main(void)
{
init_gpio();
while(1)
{
show_disp();
count++;
count&=0xF;
}
}
