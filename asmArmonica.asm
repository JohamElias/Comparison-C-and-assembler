;arr rdi / cant rsi
global asmArmonica
    section .text
asmArmonica:
    xorpd xmm0,xmm0
    xorpd xmm1,xmm1
    xorpd xmm2,xmm2
    xorpd xmm3,xmm3
    cvtsi2sd xmm2,rsi
    bucle:
    mov r8,1
    cvtsi2sd xmm1,[rdi]
    cvtsi2sd xmm0,r8
    divsd xmm0,xmm1
    addsd xmm3,xmm0
    add rdi,8
    dec rsi
    jnz bucle
    divsd xmm2,xmm3
    movsd xmm0,xmm2
    ret