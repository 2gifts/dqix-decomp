#include <globaldefs.h>

// USA: func_0200f2ec
//
// Register-state restore for the coroutine/interpreter frame that func_0200f31c
// saves and 0200eca0 dispatches. It reloads r4-r11 from the frame (offsets
// 0x2c..0x48, the same slots 0200f31c stores them in), sets sp from the saved
// stack pointer at 0x5c, subtracts the frame size at 0x64, and tail-jumps to
// the resume pointer in r2. It never returns.
//
// No C form reaches these bytes: the eight loads write callee-saved registers
// with no prologue and no reader, which mwccarm never emits (a 10-argument tail
// call compiles to r0-r3 plus stack slots), and a C body containing
// __asm("ldr r4, ...") always gets push {r3-r11,lr} / pop around it. The form
// below is mwccarm's whole-body assembly function, which is emitted verbatim.
extern "C" ARM __asm int func_0200f2ec(void* state, void* context, void (*resume)()) {
    ldr r4, [r0, #0x2c]
    ldr r5, [r0, #0x30]
    ldr r6, [r0, #0x34]
    ldr r7, [r0, #0x38]
    ldr r8, [r0, #0x3c]
    ldr r9, [r0, #0x40]
    ldr r10, [r0, #0x44]
    ldr r11, [r0, #0x48]
    ldr sp, [r0, #0x5c]
    ldr ip, [r0, #0x64]
    sub sp, sp, ip
    bx r2
}