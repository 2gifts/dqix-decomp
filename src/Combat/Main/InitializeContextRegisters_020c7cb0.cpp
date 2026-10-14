#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c7cb0
struct ProcessorContext;

ARM asm void InitializeContextRegisters(ProcessorContext *ctx, unsigned int arg1, unsigned int arg2)
{
    add r1, r1, #4
    str r1, [r0, #0x40]
    str r2, [r0, #0x44]
    sub r2, r2, #0x40
    tst r2, #4
    bne _L1c
    b _L20
_L1c:
    sub r2, r2, #4
_L20:
    str r2, [r0, #0x38]
    ands r1, r1, #1
    bne _L30
    b _L34
_L30:
    mov r1, #0x3f
_L34:
    beq _L3c
    b _L40
_L3c:
    mov r1, #0x1f
_L40:
    str r1, [r0]
    mov r1, #0
    str r1, [r0, #4]
    str r1, [r0, #8]
    str r1, [r0, #0xc]
    str r1, [r0, #0x10]
    str r1, [r0, #0x14]
    str r1, [r0, #0x18]
    str r1, [r0, #0x1c]
    str r1, [r0, #0x20]
    str r1, [r0, #0x24]
    str r1, [r0, #0x28]
    str r1, [r0, #0x2c]
    str r1, [r0, #0x30]
    str r1, [r0, #0x34]
    str r1, [r0, #0x3c]
    bx lr
}
