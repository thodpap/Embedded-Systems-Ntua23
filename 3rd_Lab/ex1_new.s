.text
.global main
.type main, %function
.extern printf
.extern scanf

main:
    push {ip,lr}
    ldr r5, =input_array @ input array addres
    ldr r7, =output_array @ output array addres

loop:
    mov r4, #0 @ r4 is the len counter
    mov r10, #0 @ global counter
    mov r9, #1 @ for LSL
    mov r1, #0
    ldr r0, =string_input @ prints Input a string of up to 32 chars long:
    bl printf

read_input: @reads the input, if single q or Q exits, if enter (new line) continues
    ldr r1, =char_one
    ldr r0, =char_
    bl scanf
    ldr r1, =char_one
    ldr r1, [r1]
    add r6, r5, r4
    add r4, r4, r9, lsl #2
    add r10, r10, r9, lsl #2
    cmp r10, #128
    movge r10, #128
    cmp r10, #4
    bne SKIP
    cmp r1, #81 @ Q
    beq exit
    cmp r1, #113 @ q
    beq exit
    SKIP:
    cmp r1, #10 @ enter
    beq result_is
    str r1, [r6] @ stores the input characters (max 32) to input_array
    bal read_input

result_is: @prints "Result is:" and initiazlizes r4
    mov r1, #0
    ldr r0, =new_line
    bl printf
    mov r1, #0
    ldr r0, =string_output
    bl printf
    mov r4, #0

convert: 
    add r6, r5, r4
    add r8, r7, r4
    ldr r1, [r6]
    cmp r1, #47
    ble interm @ r1 <= 47 keep it as it is
    cmp r1, #57
    ble num_converter @ r1 <= 57 number
    cmp r1, #64
    ble interm @ r1 <= 65 keep it as it is
    cmp r1, #90
    ble capital_letters @ r1 <= 90 capital letters
    cmp r1, #96
    ble interm @ r1 <= 96 keep it as it is
    cmp r1, #122
    ble small_letters @ r1 <= 122 small letters

interm:
    str r1, [r8]
    add r4, r4, r9, LSL #2
    cmp r4, r10
    blt convert

write_output:
    mov r4, #0
    sub r10, #4

write:
    add r8, r7, r4
    ldr r1, [r8]
    ldr r0, =char_
    bl printf
    add r4, r4, r9, LSL #2
    cmp r4, r10
    blt write
    mov r1, #0
    ldr r0, =new_line
    bl printf
    bal loop

num_converter: @ r1 -> r1
    add r1, r1, #5 @ r1 += 5
    cmp r1, #58 @ r1 %= 10 -> if r1 > '9' then subtract 10
    subge r1, #10
    bal interm @ branch always

capital_letters: @ A-Z : 65 - 90
    add r1, r1, #32
    bal interm

small_letters: @ a-z : 97 - 122
    sub r1, r1, #32
    bal interm

exit: 
    ldr r0, =new_line
    bl printf
    pop {ip,pc}

.data
    string_input: .asciz "Input a string of up to 32 chars long:"
    string_output: .asciz "Result is:"
    char_: .asciz "%c"
    new_line: .asciz "\n"
    one_: .asciz "\0"

    char_one: .word 1

    .balign 4
    input_array: .skip 32*4
    len = . - input_array

    .balign 4
    output_array: .skip 32*4
    @ output_len = . - output_array
