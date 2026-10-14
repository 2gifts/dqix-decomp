#include <globaldefs.h>

// KEEP-NAME
// USA: func_0200cf24
extern "C" ARM
asm long long func_0200cf24(long long a, long long b)
{
    stmdb sp!, {r4, r5, lr}
    umull r5, r4, r0, r2
    mla r4, r0, r3, r4
    mla r4, r2, r1, r4
    mov r1, r4
    mov r0, r5
    ldmia sp!, {r4, r5, lr}
    bx lr
}
