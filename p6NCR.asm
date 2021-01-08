; NCR
 NAME main
 PUBLIC __iar_program_start
        SECTION .data:CONST:NOROOT (2)
n DC32 0xa
r dc32 0x3
quotient dcd 0x0,0x0,0x0
remain dcd 0x0
        SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
  ldr r0,n
  bl fact ;N! IS FOUND
  mov r10,r6 ;r10=n!
  ldr r0,r
  bl fact ; R! IS FOUND
  mov r1,r6 ;r1=r!
  ldr r5,n
  ldr r8,r
  sub r5,r5,r8 ;r5=n-r
  mov r0,r5
  bl fact ; (N-R)! IS FOUND
  mov r5,r6 ;r5=(n-r)!
  mul r9,r5,r1 ;r5=r!*(n-r)!
  bl div
stop b stop
fact EOR R6,R6,R6
  MOV R6,R0
  MOV R4,R6
LOOP SUBS R4,R4,#1
  MULNE R7,R6,R4
  MOV R6,R7
  BNE LOOP
  mov PC,LR
div mov r0,r10
  mov r1,r9
  mov r3,#0
loop
  cmp r1,#0
  beq err
  cmp r0,r1
  blt done
  add r3,r3,#1
  sub r0,r0,r1
  b loop
err
  mov r3,#0xffffffff
done
  ldr r2,=remain
  ldr r4,=quotient
  str r0,[r2]
  str r3,[r4]
  mov pc,lr
  END