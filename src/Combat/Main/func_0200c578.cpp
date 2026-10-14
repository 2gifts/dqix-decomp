#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c578
extern "C" ARM
asm double _f2d(float x)
{
    and r2, r0, #0x80000000
    mov ip, r0, lsr #0x17
    mov r3, r0, lsl #9
    ands ip, ip, #0xff
    beq _L30
    cmp ip, #0xff
    beq _L5c
_L1c:
    add ip, ip, #0x380
    mov r0, r3, lsl #0x14
    orr r1, r2, r3, lsr #12
    orr r1, r1, ip, lsl #20
    bx lr
_L30:
    cmp r3, #0
    bne _L44
    mov r1, r2
    mov r0, #0
    bx lr
_L44:
    mov r3, r3, lsr #1
    clz ip, r3
    movs r3, r3, lsl ip
    rsb ip, ip, #1
    add r3, r3, r3
    b _L1c
_L5c:
    cmp r3, #0
    bhi _L74
    ldr r1, =0x7ff00000
    orr r1, r1, r2
    mov r0, #0
    bx lr
_L74:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
}
