#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200af44
extern "C" ARM
asm int func_0200af44(double x)
{
    bic r3, r1, #0x80000000
    ldr r2, =0x0000041e
    subs r2, r2, r3, lsr #20
    ble _L3c
    cmp r2, #0x20
    bge _L34
    mov r3, r1, lsl #0xb
    orr r3, r3, #0x80000000
    orr r3, r3, r0, lsr #21
    cmp r1, #0
    mov r0, r3, lsr r2
    rsbmi r0, r0, #0
    bx lr
_L34:
    mov r0, #0
    bx lr
_L3c:
    mvn r0, r1, asr #31
    add r0, r0, #0x80000000
    bx lr
}
