#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200b454
extern "C" ARM
asm double func_0200b454(double x)
{
    stmdb sp!, {r4, r5, r6, lr}
    ldr r2, =0x7ff00000
    cmp r1, r2
    bhs _L14c
    movs ip, r1, lsr #0x14
    beq _Lf8
    bic r1, r1, r2
    orr r1, r1, #0x100000
_L20:
    movs ip, ip, asr #1
    bhs _L34
    sub ip, ip, #1
    movs r0, r0, lsl #1
    adc r1, r1, r1
_L34:
    movs r3, r0, lsl #1
    adc r1, r1, r1
    mov r2, #0
    mov r4, #0
    mov lr, #0x200000
_L48:
    add r6, r4, lr
    cmp r6, r1
    addle r4, r6, lr
    suble r1, r1, r6
    addle r2, r2, lr
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne _L48
    mov r0, #0
    mov r5, #0
    cmp r1, r4
    cmpeq r3, #0x80000000
    blo _L90
    subs r3, r3, #0x80000000
    sbc r1, r1, r4
    add r4, r4, #1
    mov r0, #0x80000000
_L90:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    mov lr, #0x40000000
_L9c:
    add r6, r5, lr
    cmp r4, r1
    cmpeq r6, r3
    bhi _Lbc
    add r5, r6, lr
    subs r3, r3, r6
    sbc r1, r1, r4
    add r0, r0, lr
_Lbc:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne _L9c
    orrs r1, r1, r3
    biceq r0, r0, #1
    movs r1, r2, lsr #1
    movs r0, r0, rrx
    adcs r0, r0, #0
    adc r1, r1, #0
    add r1, r1, #0x20000000
    sub r1, r1, #0x100000
    add r1, r1, ip, lsl #20
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
_Lf8:
    cmp r1, #0
    bne _L128
    cmp r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #0xb
    mov r0, r0, lsl #0x15
    b _L20
_L128:
    clz r2, r1
    movs r1, r1, lsl r2
    rsb r2, r2, #0x2b
    mov r1, r1, lsr #0xb
    orr r1, r1, r0, lsr r2
    rsb r2, r2, #0x20
    mov r0, r0, lsl r2
    rsb ip, r2, #1
    b _L20
_L14c:
    tst r1, #0x80000000
    beq _L168
    bics r3, r1, #0x80000000
    cmpeq r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    b _L174
_L168:
    orrs r2, r0, r1, lsl #12
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
_L174:
    ldr r2, =0x7ff80000
    orr r1, r1, r2
    ldr r3, =0x020f3390
    mov r4, #0x21
    str r4, [r3]
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
}
