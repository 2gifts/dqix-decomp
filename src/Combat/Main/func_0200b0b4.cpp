#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200b0b4
extern "C" ARM
asm double _dfltu(unsigned int x)
{
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    bmi _L24
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
_L24:
    mov r1, r0
    mov r0, r1, lsl #0x15
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, r3, lsl #20
    bx lr
}
