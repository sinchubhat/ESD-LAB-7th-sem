; String copy and reverse
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT (2)
str dc8 'hello'
stre dc8 0x0
len dc32 (stre-str)
copy ds32 0x20
rev ds32 0x20
        SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
  ldr r0,=str
  ldr r1,len
  ldr r3,=copy
  ldr r4,=rev
  mov r2, r0
  add r2 ,r2, r1
loop ldrb r5,[r0],#1
  strb r5,[r3],#1
  strb r5,[r4],#-1
  ldrb r5,[r2],#1
  strb r5,[r4],#-1
  subs r1,r1,#1
  bne loop
  ldr r1,len
  sub r1,r1,#1
stop b stop
  END