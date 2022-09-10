;arr->rdi cant->rsi prom->rdx
global asmPromedio
section .text
asmPromedio:
    xorps xmm0,xmm0
    xorps xmm1,xmm1
    mov rcx,rsi
    cmp rdx,0
    je done
bucle:
    cvtsi2ss xmm1,[rdi]
    addss xmm0,xmm1
    add rdi,4
    dec rcx
    jnz bucle
done:
    cvtsi2ss xmm2,rsi
    divss xmm0,xmm2
    movss [rdx],xmm0
    ret