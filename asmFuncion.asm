	global asmFuncion
	section .text

asmFuncion:
	mov rax,rdi
    mul rax
    cvtsi2ss xmm3,rax
    cvtsi2ss xmm4,rdi
    mulss xmm0,xmm4
    subss xmm0,xmm1
    addss xmm0,xmm3
done:
	movss	[rsi],	xmm0
	ret