.text
.global main
.type main, %function
.extern tcsetattr
.extern fscanf

main:
    push {ip,lr}

open: @ opens the tty

    ldr r0, =path_tty @ load path file to open
    ldr r7, #5 @ move the open syscall number to r7
    ldr r2, #258  @O_RDWR = 0400 = 0x100 = 256, O_NOCTTY = 02 = 0x2 = 2
    svc 0

    ldr r3, =tty_fd
    str r0, [r3] @ store fd to tty_fd address

config:
    @ r0 = tty_fd
    ldr r1, #0 #TCSANOW
    ldr r2, =options
    bl tcsetattr

read:
    ldr r7, #3 @ move the read syscall number to r7
    ldr r0, =tty_fd
    ldr r0, [r0] @ tty file descriptor
    ldr r1, =string
    ldr r2, #64
    svc #0

    ldr r5, =string @ current address to hash set 
    mov r8, #1 @ for address increasing
    ldr r9, =hash_set @ hash set


process:
    ldrb r4, [r5], #1 @ load a single character - byte and increase addres
    cmp r4, #10 @ if \n end process
    breq end_process 
    cmp r4, #32 @ if space skipp
    addne r10, r9, r4, LSL #2 @ else increase by 1 the correct position (the offset of the array is the actual ascii of the character)
    ldrne r11, [r10]
    addne r11, r11, #1
    strne r11, [r10]
    bal process


ldr r5, =hash_set
mov r6, #0 @ counter
ldr r8, [r5] @ current max
ldr r9, #0 @ position of current max
end_process: @ searching for the character with maximum frequency
    ldr r10, [r5, r6, LSL #2] @ load the frequency of the new character
    cmp r8, r10 @ compare her with the existing max
    movlt r8, r10 @ if bigger then save her to r8
    movlt r9, r6 @ also save her position (actually the ascii of the character)
    add r6, r6, #1 @ increase counter
    cmp r6, 255 @ if end stop
    ble end_process

write: @ write the results so the host can take them
    ldr r0, =tty_fd @ load the file descriptor needed by fscanf
    ldr r1, =write_data @ load the format needed by fscanf
    mov r2, r9 @ load the character that is the most frequent
    mov r3, r8 @ load the frequency
    bl fscanf

close:
    ldr r0, =tty_fd   
    mov r7, #6 @ move the close syscall number to r7
    svc 0

exit:
    pop {ip,pc}


.data
    char_: .asciz "%c"

    .balign 4
    hash_set: .skip 256*4 @ array that stores the frequencies
    len = . - input_array

    .balign 4
    output_array: .skip 2*4

    path_tty: .asciz "/dev/ttyAMA0"

    tty_fd: .word 1

    options:
        .word 0x00000000 /* c_iflag */
        .word 0x00000000 /* c_oflag */
        .word 0x000008BF /* c_cflag */
        .word 0x00000A22 /* c_lflag */
        .byte 0x00
        /* c_line */
        .word 0x00000000 /* c_cc[0-3] */
        .word 0x00010000 /* c_cc[4-7] */ @ VMIN = 1 (6TH ELEMENT), VTIME = 0 (5TH ELEMENT)
        .word 0x00000000 /* c_cc[8-11] */
        .word 0x00000000 /* c_cc[12-15] */
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
    len = . - string

    write_data: .asciz "%c %d\n"
