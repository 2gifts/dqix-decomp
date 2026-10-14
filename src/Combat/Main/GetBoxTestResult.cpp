#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_020c56b0
ARM int GetBoxTestResult_020c56b0(int* out) {
    volatile unsigned int* gxstat = (volatile unsigned int*)0x4000600;
    if (*gxstat & 0x1) return -1;
    *out = *gxstat & 0x2;
    return 0;
}
