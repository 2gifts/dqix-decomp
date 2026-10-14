#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// USA: func_02033e38
ARM void AdjustPositionTowardTarget02033e38(void* obj) {
    char* base = (char*)obj;
    short* speedPtr = (short*)(base + 0xc6);
    short speed = *speedPtr;
    if (speed != 0) {
        Vector3i diff;
        Vector3fix_Subtract((Vector3i*)(base + 0xc8), (Vector3i*)(base + 0x44), &diff);
        int dist = Vector3fix_Length(&diff);
        if (dist < speed) {
            *(Vector3i*)(base + 0x44) = *(Vector3i*)(base + 0xc8);
            *speedPtr = 0;
        } else {
            int scale = fix32_Divide(speed, dist);
            Vector3fixMultiplyScalar(&diff, scale, &diff);
            Vector3i sum;
            Vector3fix_Add((Vector3i*)(base + 0x44), &diff, &sum);
            *(Vector3i*)(base + 0x44) = sum;
        }
    }
}
