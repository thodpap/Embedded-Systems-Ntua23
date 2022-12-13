.text
.align 4
.global strcat
.type strcat, %function

@ r0: dest, r1: src
strcat:
    PUSH {ip, lr}
    
    mov r6, r0  @ r6 is the address of our destination string
    mov r7, r1  @ r7 is the address of our source string

loop:
    ldrb r2, [r0], #1 @ r2 = string1[0] & ++string1
    cmp r2, #0      @ If the first string ended continue to sub
    bne loop        

    @ we have passes string1
    @ r2 = '\0' and r0 is len + 1 so we need to subtract 1 to override '\0'
    sub r0, #1

concat:
    ldrb r3, [r1], #1   @ r3 = string2[0] & ++string2
    strb r3, [r0], #1   @ string1[0] = r3 & ++string1
    cmp r3, #0     @ If string2 ended continue to exit
    bne concat

exit:
    mov r0, r6  @ restore and return string1
    mov r1, r7  @ restore string2
    POP {lr, ip}
    bx lr
