#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c6b8
extern "C" ARM
asm float _ffltu(unsigned int x)
{
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi _L1c
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
_L1c:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}
