.text
.global main
.align 4 /* code alignment */
.extern tcsetattr

main:

open: @ opens the tty
    ldr r0, =path_tty @ load path file to open
    mov r7, #5 @ move the open syscall number to r7
    ldr r1, =#258  @ O_RDWR = 0400 = 0x100 = 256, O_NOCTTY = 02 = 0x2 = 2
    svc 0
    ldr r3, =tty_fd
    str r0, [r3] @ store fd to tty_fd address

config: @ r0 = tty_fd
    mov r1, #0 @ FLAG FOT TCSETATTRTCSANOW
    ldr r2, =options
    bl tcsetattr

read:
    mov r7, #3 @ move the read syscall number to r7
    ldr r0, =tty_fd
    ldr r0, [r0] @ tty file descriptor
    ldr r1, =string
    mov r2, #64
    svc #0

done_read:
    ldr r5, =string @ current address to string
    mov r8, #1 @ for address increasing
    ldr r9, =hash_set @ hash set

process:
    ldrb r4, [r5], #1 @ load a single character - byte and increase addres
    cmp r4, #10 @ if \n end process
    beq until_here_0 
    cmp r4, #32 @ if space skip
    beq process
    cmp r4, #0 @ if null skip
    beq process
    add r10, r9, r4 @ else increase by 1 the correct position (the offset of the array is the actual ascii of the character)
    ldrb r11, [r10]
    add r11, r11, #1
    strb r11, [r10]
    bal process

until_here_0:
    ldr r5, =hash_set
    mov r6, #0 @ counter
    ldrb r8, [r5] @ current max
    mov r9, #0 @ position of current max

end_process: @ searching for the character with maximum frequency
    ldrb r10, [r5, r6] @ load the frequency of the new character
    cmp r8, r10 @ compare her with the existing max
    movlt r8, r10
    movlt r9, r6 @ save the position of max frequency(actually the ascii of the character)
    add r6, r6, #1 @ increase counter
    cmp r6, #255 @ if end stop
    ble end_process

ldr r0, =output_array
ldr r8, [r5, r9]
add r8, r8, #48
strb r8, [r0], #1
mov r10, #32
strb r10, [r0], #1
strb r9, [r0], #1
mov r10, #10 @ canonical -> we need to write \n
strb r10, [r0], #1
write: @ write the results so the host can take them
    ldr r0, =tty_fd @ load the file descriptor needed by fscanf
    ldr r0, [r0]
ro_:
    @ ldr r1, =write_data @ load the format needed by fscanf
    ldr r1, =output_array @ load the character that is the most frequent
    @ add r9, r8, r10, lsl #2 @ load the frequency
    mov r2, #5
ro_1:
    mov r7, #4
    svc 0

close:
    ldr r0, =tty_fd   
    ldr r0, [r0]
    mov r7, #6 @ move the close syscall number to r7
    svc 0

exit:
    mov r0, #0
    mov r7, #1          /* exit system call */
    svc 0


.data
    char_: .asciz "%c"

    .balign 1
    hash_set: .skip 256 @ array that stores the frequencies
    @ len = . - input_array

    @ .balign 1
    @ output_array: .skip 10
    output_array: .asciz "00000000"

    path_tty: .asciz "/dev/ttyAMA0"

    tty_fd: .word 1

    options:
        .word 0x00000000 /* c_iflag */
        .word 0x00000000 /* c_oflag */
        .word 0x000008BF /* c_cflag */
        .word 0x00000A22 /* c_lflag */
        .byte 0x00
        /* c_line */
        .word 0x157F1C03 /* c_cc[0-3] */
        .word 0x00010004 /* c_cc[4-7] */ @ VMIN = 1 (6TH ELEMENT), VTIME = 0 (5TH ELEMENT)
        .word 0x001A1311 /* c_cc[8-11] */
        .word 0x16170E12 /* c_cc[12-15] */
        .word 0x00000000 /* c_cc[16-19] */
        .word 0x00000000 /* c_cc[20-23] */
        .word 0x00000000 /* c_cc[24-27] */
        .word 0x00000000 /* c_cc[28-31] */
        .byte 0x00
        /* padding */
        .hword 0x0000 /* padding */
        .word 0x0000000d /* c_ispeed */
        .word 0x0000000d /* c_ospeed */

    string: .asciz "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
    

    write_data: .asciz "%c %d\n"
