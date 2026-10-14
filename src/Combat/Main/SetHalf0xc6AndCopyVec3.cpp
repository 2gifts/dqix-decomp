#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_02033e18
ARM void SetHalf0xc6AndCopyVec3_02033e18(void* obj, int* src, short val) {
    *(short*)((char*)obj + 0xc6) = val;
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0xc8), src);
}
