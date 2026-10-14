#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200bbe0
extern "C" ARM
asm int func_0200bbe0(double a, double b)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs _L74
    cmn ip, r3, lsl #1
    bhs _L88
_L14:
    orrs ip, r3, r1
    bmi _L44
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #1
    movlo r0, #0
    bx lr
_L30:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
_L44:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #1
    movlo r0, #0
    bx lr
_L74:
    bne _L30
    cmp r0, #0
    bhi _L30
    cmn ip, r3, lsl #1
    blo _L14
_L88:
    bne _L30
    cmp r2, #0
    bhi _L30
    b _L14
}
