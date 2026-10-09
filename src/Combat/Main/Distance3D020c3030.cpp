#include <globaldefs.h>

#include "System/Matrix.h"

#define REG_SQRTCNT_020c3030      (*(volatile unsigned short*)0x040002b0)
#define REG_SQRT_RESULT_020c3030  (*(volatile unsigned int*)0x040002b4)
#define REG_SQRTPARAM_LO_020c3030 (*(volatile unsigned int*)0x040002b8)
#define REG_SQRTPARAM_HI_020c3030 (*(volatile unsigned int*)0x040002bc)

// USA: func_020c3030
extern "C" ARM fix32_t Vector3fix_Distance(const Vector3fix* a, const Vector3fix* b) {
    int dx = a->x - b->x;
    long long sq = (long long)dx * dx;
    int dy = a->y - b->y;
    sq += (long long)dy * dy;
    int dz = a->z - b->z;
    sq += (long long)dz * dz;
    REG_SQRTCNT_020c3030 = 1;
    unsigned long long scaled = (unsigned long long)sq << 2;
    REG_SQRTPARAM_LO_020c3030 = (unsigned int)scaled;
    REG_SQRTPARAM_HI_020c3030 = (unsigned int)(scaled >> 32);
    while (REG_SQRTCNT_020c3030 & 0x8000) {}
    return (int)(REG_SQRT_RESULT_020c3030 + 1) >> 1;
}
