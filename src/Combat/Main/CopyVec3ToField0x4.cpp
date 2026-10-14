#include <globaldefs.h>
#include "System/Matrix.h"

// USA: func_0202ef04
ARM void CopyVec3ToField0x4_0202ef04(int* obj, int* src) {
    *(Vector3i*)(obj + 1) = *(const Vector3i*)src;
}
