#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c630
extern "C" ARM
asm unsigned int _ffixu(float x)
{
    tst r0, #0x80000000
    bne _L24
    mov r1, #0x9e
    subs r1, r1, r0, lsr #23
    blt _L38
    mov r2, r0, lsl #8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
_L24:
    mov r2, #0xff000000
    cmp r2, r0, lsl #1
    movhs r0, #0
    mvnlo r0, #0
    bx lr
_L38:
    mvn r0, #0
    bx lr
}
