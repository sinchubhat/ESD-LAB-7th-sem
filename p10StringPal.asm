; STRING PAL
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT(2)
string DCB 'radar'
end DCb 0x00
length DCD end-string
        SECTION .intvec:CODE:NOROOT(2)
__iar_program_start
main
  ldr R5,length
  ldr R0,=string
  mov R1,R0
  add R1,R1,R5
  SUB R1,R1,#1
loop CMP R1,R0
  BMI PALI
  LDRB R2,[R0],#1
  LDRB R3,[R1],#-1
  CMP R2,R3
  BEQ loop
NOTPALI MOV R10,#0
STOP B STOP
PALI MOV R10,#0XFF
stop b stop
  end