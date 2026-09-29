#include "System/Matrix.h"
#include <globaldefs.h>

// USA: func_020c6938
extern "C" ARM asm void func_020c6938(const void *pSrc, void *pDest) {
    stmfd sp!, {r4-r8}
    ldmia r0!, {r2-r8, r12}
    stmia r1, {r2-r8, r12}
    ldmia r0!, {r2-r8, r12}
    stmia r1, {r2-r8, r12}
    ldmfd sp!, {r4-r8}
    bx lr
}
