#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200afe8
extern "C" ARM
asm unsigned long long func_0200afe8(double x)
{
    tst r1, #0x80000000
    bne _L64
    ldr r2, =0x0000043e
    subs r2, r2, r1, lsr #20
    blt _L7c
    cmp r2, #0x40
    bge _L58
    mov ip, r1, lsl #0xb
    orr ip, ip, #0x80000000
    orr ip, ip, r0, lsr #21
    cmp r2, #0x20
    ble _L40
    sub r2, r2, #0x20
    mov r1, #0
    mov r0, ip, lsr r2
    bx lr
_L40:
    mov r3, r0, lsl #0xb
    mov r1, ip, lsr r2
    mov r0, r3, lsr r2
    rsb r2, r2, #0x20
    orr r0, r0, ip, lsl r2
    bx lr
_L58:
    mov r1, #0
    mov r0, #0
    bx lr
_L64:
    cmn r1, #0x100000
    cmpeq r0, #0
    bhi _L7c
    mov r1, #0
    mov r0, #0
    bx lr
_L7c:
    mvn r1, #0
    mvn r0, #0
    bx lr
}
