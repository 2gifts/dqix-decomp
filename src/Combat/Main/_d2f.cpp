#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200ae40
extern "C" ARM asm float _d2f(double d) {
    and r2, r1, #0x80000000
    mov ip, r1, lsr #20
    bics ip, ip, #0x800
    beq L_zero
    mov r3, ip, lsl #21
    cmn r3, #0x200000
    bhs L_infnan
    subs ip, ip, #0x380
    bls L_denorm
    cmp ip, #0xff
    bge L_overflow
    mov r1, r1, lsl #12
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, ip, lsl #23
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_infnan:
    orrs r3, r0, r1, lsl #12
    bne L_nan
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_nan:
    mvn r0, #0x80000000
    bx lr
L_zero:
    orrs r3, r0, r1, lsl #12
    bne L_underflow
    mov r0, r2
    bx lr
L_denorm:
    cmn ip, #0x17
    beq L_tiny
    bmi L_underflow
    mov r1, r1, lsl #11
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb ip, ip, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr ip
    rsb ip, ip, #32
    mov r3, r3, lsl ip
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_tiny:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
L_underflow:
    mov r0, r2
    bx lr
L_overflow:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
}
