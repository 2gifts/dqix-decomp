#include <globaldefs.h>
#include "World/Object3D.h"

struct U16Field0x6_020375f8;
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_02053ed8
ARM void CaptureTransformState02053ed8(void* obj) {
    *(int*)((char*)obj + 0x15c) = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x160), (int*)((char*)obj + 0x44));
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x16c), (int*)((char*)obj + 0x50));
}
