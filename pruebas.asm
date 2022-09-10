section .data
    cadena db "Un numero float: "
    len equ $ - cadena

section .text
    global _start

_start:
    mov rax,1
   ; movss xmm0,[rax]

    mov rax,1
    mov rdi,1
    mov rsi,cadena
    mov rdx,len
    syscall

    final:
    mov rax,60
    mov rdi,0
    syscall
