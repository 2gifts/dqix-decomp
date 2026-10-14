#include <globaldefs.h>
#include "System/Matrix.h"

// USA: func_ov000_0216f1e4
ARM void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b) {
    *(Vector3i*)((char*)obj + 0x264) = *(Vector3i*)srcVec3;
    *(int*)((char*)obj + 0x270) = a;
    *(int*)((char*)obj + 0x274) = b;
}
