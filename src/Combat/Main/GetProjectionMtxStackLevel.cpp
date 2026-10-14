#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_020c5680
ARM int GetProjectionMtxStackLevel_020c5680(int* out) {
    volatile unsigned int* gxstat = (volatile unsigned int*)0x4000600;
    if (*gxstat & 0x4000) return -1;
    *out = (*gxstat & 0x2000) >> 13;
    return 0;
}
