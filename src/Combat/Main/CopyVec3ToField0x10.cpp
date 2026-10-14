#include <globaldefs.h>
#include "System/Matrix.h"

// USA: func_0202e938
ARM void CopyVec3ToField0x10_0202e938(void* obj, int* src) {
    *(Vector3i*)((char*)obj + 0x10) = *(const Vector3i*)src;
}
