#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_0202e938
ARM void CopyVec3ToField0x10_0202e938(void* obj, int* src) {
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x10), src);
}
