#include <globaldefs.h>
#include "System/Matrix.h"

// USA: func_02033e18
ARM void SetHalf0xc6AndCopyVec3_02033e18(void* obj, int* src, short val) {
    *(short*)((char*)obj + 0xc6) = val;
    *(Vector3i*)((char*)obj + 0xc8) = *(Vector3i*)src;
}
