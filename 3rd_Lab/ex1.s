.text
.global main
.extern printf
.extern scanf


main:
    push {ip,lr}
    @ mov r12, #32
    mov r3, #0 @ r3 is the len counter

    bal scanf_

@ assumes that r1 got the right value
print:
    ldr r0, =string_output
    bl printf
    add r3, r3, #1
    cmp r3, #32
    bge exit
    
    @ ldr r1, [r2, r3]
    @ ldr r0, =test_print
    @ bl printf

    bal move

@ returns the result to r1
scanf_:

    ldr r0, =string_input
    bl printf

    ldr r1, =all_
    ldr r0, =read_string
    bl scanf

    ldr r2, =all_
    
    ldr r1, [r2, r3]
    @ ldr r0, =test_print
    @ bl printf
    
    bal move

move:
    cmp r1, #10
    beq exit
    
    cmp r1, #47
    ble print @ r1 <= 47 keep it as it is

    cmp r1, #57
    ble num_converter @ r1 <= 57 number

    cmp r1, #64
    ble print @ r1 <= 65 keep it as it is
    
    cmp r1, #90
    ble capital_letters @ r1 <= 90 capital letters

    cmp r1, #96
    ble print @ r1 <= 96 keep it as it is

    cmp r1, #122
    ble small_letters @ r1 <= 122 small letters

    @ do nothing return
    bal print
    

num_converter:
    @ r1 -> r1
    add r1, r1, #5 @ r1 += 5

    cmp r1, #58 @ r1 %= 10 -> if r1 > '9' then subtract 10
    subge r1, #10

    @ branch always
    bal print

    
@ A-Z : 65 - 90
@ a-z : 97 - 122
capital_letters:
    add r1, r1, #32
    bal print

small_letters:
    sub r1, r1, #32
    bal print

exit: 

    ldr r0, =new_line
    bl printf
    pop {ip,pc}

.data
    string_input: .asciz "Input a string of up to 32 chars long:"
    test_print: .asciz "Input a string of up to 32 chars long:%c\n"
    read_string: .asciz "%s"
    string: .asciz "Result is:"
    string_output: .asciz "%c"
    str_: .asciz "%c"
    new_line: .asciz "\n"
    all_: .asciz "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
    one_: .asciz "\0"
