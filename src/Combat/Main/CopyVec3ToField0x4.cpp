#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_0202ef04
ARM void CopyVec3ToField0x4_0202ef04(int* obj, int* src) {
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x4), src);
}
