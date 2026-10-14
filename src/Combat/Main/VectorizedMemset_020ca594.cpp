#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020ca594
//
// Hand-written SDK assembly, transcribed instruction-for-instruction from the ROM.
// It is not un-decompiled C: no C form reaches it, because DQIX's SDK build spells every
// PREDICATED instruction as an explicit branch pair (`ldrneh r3,[r0,#-1]` becomes
// `bne L; b M; L: ldrh r3,[r0,#-1]`), which is also why the reference decomp's own asm
// does not assemble to these bytes -- theirs is ~20 instructions shorter for that reason.
//
// PROVENANCE: pret/pokediamond arm7/lib/src/MI_memory.c -- MIi_CpuClearFast family, asm void there too
extern "C" ARM
asm void VectorizedMemset(void *dst, int value, unsigned int size)
{
    cmp r2, #0
    beq _Lc
    b _L10
_Lc:
    bx lr
_L10:
    tst r0, #1
    beq _L3c
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    beq _L38
    b _L3c
_L38:
    bx lr
_L3c:
    cmp r2, #2
    blo _L94
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq _L64
    strh r1, [r0], #2
    subs r2, r2, #2
    beq _L60
    b _L64
_L60:
    bx lr
_L64:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq _L84
    sub r2, r2, r3
    add ip, r3, r0
_L78:
    str r1, [r0], #4
    cmp r0, ip
    blo _L78
_L84:
    tst r2, #2
    bne _L90
    b _L94
_L90:
    strh r1, [r0], #2
_L94:
    tst r2, #1
    beq _La0
    b _La4
_La0:
    bx lr
_La4:
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}
