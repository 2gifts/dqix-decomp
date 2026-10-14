#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c14c
extern "C" ARM
asm int _fneq(float a, float b)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    blo _L54
    cmp r3, r1, lsl #1
    blo _L54
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bne _L34
    mrs ip, cpsr
    orr ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
_L34:
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    mrs ip, cpsr
    bicne ip, ip, #0x40000000
    orreq ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
_L54:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
}
