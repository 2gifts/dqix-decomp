#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c8348
ARM asm void WaitForVCountZero_020c8348(void) {
    mov r12, #0x4000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
loop:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne loop
    str r1, [r12, #0x208]
    bx lr
}
