.text
.align 4
.global strlen
.type strlen, %function

@ r0: string address
@ r0 is the const char *s
strlen:
    PUSH {ip, lr}
    mov r2, #0      @ initialise the counter to 0

loop:
    ldrb r1, [r0], #1 @ r1 = s[0] ++s;
    cmp r1, #0
    beq exit @ if s ended jump to exit

    add r2, #1 @ increase counter (counter++)
    b loop 
exit:
    mov r0, r2 @ return the counter
    POP {lr, ip}
    bx lr
