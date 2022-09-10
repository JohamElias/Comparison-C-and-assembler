global asmMediana
	section .text

asmMediana:
	xorpd xmm0, xmm0
	xorpd xmm1, xmm1
	xorpd xmm2, xmm2
	;rdi = n, rsi = arreglo
	;rdx,rcx,r8

	mov rdx, 2
	mov rcx, 4
	cvtsi2ss xmm0, rdi
	cvtsi2ss xmm1, rdx
	cvtsi2ss xmm2, rcx
	divss xmm0, xmm1
	mulss xmm0, xmm2
    br:
	cvtss2si rdx, xmm0
	add rsi, rdx
	movss xmm0, [rsi]
	sub rsi, 4
	movss xmm1, [rsi]
	addss xmm0, xmm1
	mov rdx,2
	cvtsi2ss xmm1, rdx
	divss xmm0, xmm1
    
	ret