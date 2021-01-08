; UNPACKED BCD to HEX
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT(2)
num DC8 0x01,0x02,0x03,0x04
result DC8 0x00
        SECTION .intvec:CODE:NOROOT(2)
__iar_program_start
main
  ADR R0,num
  MOV R5,#4
  MOV R1,#0
  MOV R2,R1
  MOV R10,#10
loop MOV R7,R1
  MUL R1,R7,R10 ;10(a+(10(b+(10(c+10d)))));
  LDRB R4,[R0],#1
  ADD R1,R1,R4
  SUBS R5,R5,#1 ;Count
  BNE loop
  STR R1,result
stop B stop
  END