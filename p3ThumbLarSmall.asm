; THUMB-LAR SMALL
 NAME main
 PUBLIC __iar_program_start
        SECTION datas:CONST(2)
num
  dc32 0x0A,0x02,0x06,0x04,0x00
numend
  dc32 0x00
len
  dc32 (numend-num)/4
  
        SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
  ldr r1,=num
  ldr r2,len
  sub r2,r2,#1
  ldr r3,num
  ldr r4,num
  ldr r0,=thumbcode
  mov lr,pc
  bx r0
stop b stop
  code16
thumbcode
loop add r1,#4
  ldr r5,[r1]
  cmp r5,r3
  bpl subss
  mov r3,r5
subss cmp r5,r4
  bmi loop1
  mov r4,r5
loop1 sub r2,#1
  cmp r2,#0
  bne loop
  bx lr
  end