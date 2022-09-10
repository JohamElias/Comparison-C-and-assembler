    global asmfactorial
    section .text
;n->rdi y &resp->rsi
asmfactorial:
    mov rax,[rsi]
    bucle:
    mul rdi
    dec rdi
    jnz bucle
done:
    mov [rsi],rax
    ret
