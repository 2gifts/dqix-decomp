#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200bdb4
extern "C" ARM
asm int func_0200bdb4(double a, double b)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs _L78
    cmn ip, r3, lsl #1
    bhs _L8c
_L14:
    orrs ip, r3, r1
    bmi _L44
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #1
    movhs r0, #0
    bx lr
_L30:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
_L44:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bne _L64
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bxeq lr
_L64:
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #1
    movhs r0, #0
    bx lr
_L78:
    bne _L30
    cmp r0, #0
    bhi _L30
    cmn ip, r3, lsl #1
    blo _L14
_L8c:
    bne _L30
    cmp r2, #0
    bhi _L30
    b _L14
}
