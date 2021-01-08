; PACKED BCD to HEX
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT(2)
num DC16 0x1234
result DS32 0x00
        SECTION .intvec:CODE:NOROOT(2)
__iar_program_start
  ADR R0,num
  MOV R5,#4
  MOV R9,#12
  MOV R1,#0
  ;MOV R2,R1
  MOV R10,#10 ;Multiply by 10
  MOV R11,#0x0F ;To mask
loop MOV R7,R1
  MUL R1,R7,R10
  LDRH R8,[R0]
  ROR R8,R8,R9
  AND R4,R8,R11
  ADD R1,R1,R4
  SUBS R9,R9,#4
  SUBS R5,R5,#1
  BNE loop
  STR R1,result
stop B stop
  END