; 64 BIT ADD/SUB
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT(2)
first: DC32 0xAAAAAAAA,0x22222222
second: DC32 0x11111111,0x11111111
sum: DS32 0x04
difference: DS32 0x04
        SECTION .intvec:CODE:NOROOT(2)
main
__iar_program_start
  ADR R0,first
  ADR R1,second
  ADR R9,sum
  ADR R8,difference
  LDMIA R0,{R2,R3} ;Load first operand into R2 and R3
  LDMIA R1,{R4,R5} ;Load second operand into R4 and R5
  ADDS R6,R3,R5 ;Add lower 32 bits
  ADC R7,R2,R4 ;Add upper 32 bits
  STMIA R9,{R6,R7} ;Store sum
  SUBS R6, R3,R5 ;Subtract lower 32 bits
  SBC R7,R2,R4 ;Subtract upper 32 bits
  STMIA R8,{R6,R7} ;Store difference
stop B stop
  END