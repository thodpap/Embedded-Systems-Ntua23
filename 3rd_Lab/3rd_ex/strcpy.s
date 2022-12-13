.text
.align 4
.global strcpy
.type strcpy, %function

@ r0: dest, r1: src
strcpy:
    PUSH {ip, lr}
    mov r3, r0  @ copy the dest address

loop:
    ldrb r2, [r1], #1   @ r2 = src[0] & ++src;
    strb r2, [r0], #1    @ dest[0] = r2 & ++dest;
    cmp r2, #0      @ If the src hasn't ended yet
    bne loop

exit:
    mov r0, r3  @ restore and return destination's initial address

    POP {lr, ip}
    bx lr
