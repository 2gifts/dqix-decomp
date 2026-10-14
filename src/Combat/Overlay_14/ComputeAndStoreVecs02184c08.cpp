#include <globaldefs.h>
#include "World/Object3D.h"

struct BinarySearch020971a8Node;
struct BinarySearch020971a8Container;
struct BinarySearch020971a8Node* BinarySearchByField4_02097224(struct BinarySearch020971a8Container* c, int key);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vector3i;

// USA: func_ov014_02184c08
ARM void ComputeAndStoreVecs02184c08(unsigned char* obj) {
    void* b = *(void**)(obj + 0x48);
    if (b == NULL) return;
    struct BinarySearch020971a8Node* node = BinarySearchByField4_02097224((struct BinarySearch020971a8Container*)(obj + 0xc), *(short*)((char*)b + 0xc));
    if (node == NULL) return;

    int vecA[3];
    int vecB[3];
    int vecC[3];

    vecA[0] = (int)(4096.0f * *(float*)((char*)node + 0x10));
    vecA[1] = (int)(4096.0f * *(float*)((char*)node + 0x14));
    vecA[2] = (int)(4096.0f * *(float*)((char*)node + 0x18));
    vecB[0] = 0;
    vecB[1] = (int)(4096.0f * *(float*)((char*)node + 0x1c));
    vecB[2] = 0;
    vecC[0] = (int)(4096.0f * *(float*)((char*)node + 0x20));
    vecC[1] = (int)(4096.0f * *(float*)((char*)node + 0x24));
    vecC[2] = (int)(4096.0f * *(float*)((char*)node + 0x28));

    _ZN8Vector3iaSERKS_((int*)(*(char**)(obj + 0x40) + 0x44), vecA);
    _ZN8Vector3iaSERKS_((int*)(*(char**)(obj + 0x40) + 0x50), vecB);
    ((Object3D*)(*(unsigned char**)(obj + 0x40)))->SetScale((Vector3i const*)vecC);
}
