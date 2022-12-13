.text
.align 4
.global strcmp
.type strcmp, %function

@ r0: str1, r1: str2
@ if str1 == str2 return 0
strcmp:
    PUSH {ip, lr}
    mov r4, #0x0 @ r4 keeps the return value, we will mov it to r0 in the end
loop:
    ldrb r2, [r0], #1   @ r2 = s1[0] and ++s1
    ldrb r3, [r1], #1   @ r3 = s2[0] and ++s2
    cmp r2, r3 @ if r2 != r3 jump to notEqual
    bne notEqual    

    cmp r2, #0      @ if we parsed s1 jump to exit
    beq exit    

    b loop          @ else continue looping

notEqual:
    movlt r4, #0xffffffff   @ if s1 < s2 -> -1
    movgt r4, #0x1      @ if s1 > s2 -> 1

exit:
    mov r0, r4  @ return the result(r4) into r0
    POP {lr, ip}
    bx lr
