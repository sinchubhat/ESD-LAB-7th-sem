// 7-SEG
//0000-FFFF
include "lpc214x.h"
#include "stdint.h"
#define IO1 0x10000
#define IO2 0x20000
#define IO3 0x40000
#define IO4 0x80000
#define IOX 0xF0000
#define IOXcl 0xFFFFF
int count=0000;
unsignedint d1,d2,d3,d4;
unsigned char seg[] =
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
voidinit_gpio()
{
PINSEL0 = 0x00000000;
PINSEL1 = 0x00000000;
PINSEL2 = 0x00000000;
IO0DIR = 0XFFFFFFFF;
IO1DIR = 0XFFFFFFFF;
}
void delay()
{
int c = 50000;
while(c)
c--;
}
voidshow_disp()
{
//Digit 1
d1 = count & 0x000F;
IO0CLR = IOXcl;
IO0SET = seg[d1];
IO1SET = IOX;
IO1CLR = IO1;
delay();
IO1SET = IOX;
//Digit 2
d2 = count & 0x00F0;
d2 >>= 4;
IO0CLR = IOXcl;
IO0SET= seg[d2];
IO1SET = IOX;
IO1CLR = IO2;
delay();
IO1SET= IOX;
//Digit 3
d3 = count & 0x0F00;
d3 >>= 8;
IO0CLR = IOXcl;
IO0SET= seg[d3];
IO1SET = IOX;
IO1CLR = IO3;
delay();
IO1SET = IOX;
//Digit 4
d4 = count & 0xF000;
d4>>= 4;
IO0CLR = IOXcl;
IO0SET = seg[d4];
IO1SET = IOX;
IO1CLR = IO4;
delay();
IO1SET = IOX;
}
int main( void )
{
init_gpio();
while(1)
{
show_disp();
count++;
count&= 0xFFFF;
}
}
