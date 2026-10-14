#include <globaldefs.h>
#include "World/Object3D.h"

struct U16Field0x6_020375f8;
struct Vector3i;

// USA: func_02053ed8
ARM void CaptureTransformState02053ed8(void* obj) {
    *(int*)((char*)obj + 0x15c) = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    *(Vector3i*)((int*)((char*)obj + 0x160)) = *(Vector3i const*)((int*)((char*)obj + 0x44));
    *(Vector3i*)((int*)((char*)obj + 0x16c)) = *(Vector3i const*)((int*)((char*)obj + 0x50));
}
