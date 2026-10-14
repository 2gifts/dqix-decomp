#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_020c5650
ARM int GetPositionVectorMtxStackLevel_020c5650(int* out) {
    volatile unsigned int* gxstat = (volatile unsigned int*)0x4000600;
    if (*gxstat & 0x4000) return -1;
    *out = (*gxstat & 0x1f00) >> 8;
    return 0;
}
