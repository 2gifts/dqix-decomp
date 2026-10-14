#include "System/Matrix.h"
#include <globaldefs.h>

// USA: func_020c6914  (semantic: GX_SendFifo48B)
extern "C" ARM asm void func_020c6914(const void *pSrc, void *pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    bx lr
}
