#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200c7d4
extern "C" ARM
asm float _fmul(float a, float b)
{
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov ip, #0xff
    ands r3, ip, r0, lsr #23
    mov r0, r0, lsl #8
    cmpne r3, #0xff
    beq _L7c
    orr r0, r0, #0x80000000
    ands ip, ip, r1, lsr #23
    mov r1, r1, lsl #8
    cmpne ip, #0xff
    beq _Lbc
    orr r1, r1, #0x80000000
_L34:
    add ip, r3, ip
    umull r1, r3, r0, r1
    movs r0, r3
    addpl r0, r0, r0
    subpl ip, ip, #1
    subs ip, ip, #0x7f
    bmi _L148
    cmp ip, #0xfe
    bge _L1b4
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    tst r3, #0x80
    bxeq lr
    orrs r1, r1, r3, lsl #25
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
_L7c:
    cmp r3, #0
    beq _Ld0
    movs r0, r0, lsl #1
    bne _L1a4
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq _Lb0
    cmp ip, #0xff
    blt _L198
    cmp r1, #0
    beq _L198
    b _L1a4
_Lb0:
    cmp r1, #0
    beq _L1ac
    b _L198
_Lbc:
    cmp ip, #0
    beq _L12c
_Lc4:
    movs r1, r1, lsl #1
    bne _L1a4
    b _L198
_Ld0:
    movs r0, r0, lsl #1
    beq _L108
    mov r0, r0, lsr #1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq _L12c
    cmp ip, #0xff
    beq _Lc4
    orr r1, r1, #0x80000000
    b _L34
_L108:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq _L1d8
    cmp ip, #0xff
    blt _L1d8
    cmp r1, #0
    beq _L1ac
    b _L1a4
_L12c:
    movs r1, r1, lsl #1
    beq _L1d8
    mov r1, r1, lsr #1
    clz ip, r1
    movs r1, r1, lsl ip
    rsb ip, ip, #1
    b _L34
_L148:
    cmn ip, #0x18
    beq _L190
    bmi _L1d0
    cmp r1, #0
    orrne r0, r0, #1
    mov r3, r0
    mov r0, r0, lsr #8
    rsb ip, ip, #0
    orr r0, r2, r0, lsr ip
    rsb ip, ip, #0x18
    movs r1, r3, lsl ip
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
_L190:
    mov r0, r0, lsl #1
    b _L1c0
_L198:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
_L1a4:
    mvn r0, #0x80000000
    bx lr
_L1ac:
    mvn r0, #0x80000000
    bx lr
_L1b4:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
_L1c0:
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
_L1d0:
    mov r0, r2
    bx lr
_L1d8:
    mov r0, r2
    bx lr
}
