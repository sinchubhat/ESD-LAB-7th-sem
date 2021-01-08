; BUBBLE SORT
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT (2)
mydata:
  DC32 0X99999999,0X33333333,0X44444444,0XAAAAAAAA,0XFFFFFFFF
mydataend:
  DC32 0x00
length:
  DC32 (mydataend-mydata)/4
        SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
MAIN
  LDR R0,length
  SUB R0,R0,#1
  MOV R5,R0
  LDR R1,=mydata
LOOP2 MOV R0,R5
  MOV R2,R1
  ADD R2,R2,#4
L1 LDR R3,[R1]
  LDR R4,[R2]
  CMP R3,R4
  BLO LOOP1    ; (BHS for DESCENDING)
  SWP R3,R4,[R1]
  STR R3,[R2]
LOOP1 ADD R2,R2,#4
  SUBS R0,R0,#1
  BHI L1
  ADD R1,R1,#4
  SUBS R5,R5,#1
  BGT LOOP2
stop B stop
  END