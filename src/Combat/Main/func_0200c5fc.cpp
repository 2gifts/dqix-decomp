#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c5fc
extern "C" ARM
asm int _ffix(float x)
{
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #23
    ble _L28
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    bx lr
_L28:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
}
