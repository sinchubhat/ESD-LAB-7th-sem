// KEYPAD
#include "lpc214x.h"
#include "stdint.h"
unsignedinti,delay_ms,segval;
unsigned char index, lcdval,row,keyscan,keyret,keynum=0, keypress,scanret = 0xFF;
unsigned char seg7[] =
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00,0x00,0x0
};
unsigned char scan[] = {0xEF,0xDF,0xBF,0x7F,0x00} ;
unsigned char keycode[] =
{0xEE,0xED,0xEB,0xE7,0xDE,0xDD,0xDB,0xD7,0xBE,0xBD,0xBB,0xB7,0x7E,0x7D,0x7B,0x77,0x00};
voidInitLPC(void)
{
PINSEL0 = 0x00L;
IO0DIR = 0XFFFFFFF0;
}
void Delay(unsigned intdms)
{ delay_ms = dms;
while(delay_ms> 0)
delay_ms--;
}
voidGetKey()
{
row=0;
while(1)
{
IO0CLR = 0xFF;
row&= 0x3;
keyscan=scan[row];
IO0SET = keyscan;
Delay(2);
keyret = IO0PIN;
if (keyscan != keyret)
break;
row++;
}
for(i=0;i<0x10;i++)
{
if(keycode[i]==keyret)
keynum=i;
}
IO0CLR = 0xFF00;
segval = seg7[keynum];
segval<<= 8;
IO0SET = segval;
}
void main(void)
{
InitLPC();
index=0;
while(1)
GetKey();
}
