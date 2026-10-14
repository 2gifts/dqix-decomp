#include <globaldefs.h>

extern "C" void func_020c8b44(void* p);
extern "C" void func_020c8bd4(void);

// USA: func_020c8b30
ARM asm void* CallFunc020c8b44Then020c8bd4_020c8b30(void* p) {
    stmdb sp!, {r0, lr}
    bl func_020c8b44
    bl func_020c8bd4
    ldmia sp!, {r0, lr}
    bx lr
}
