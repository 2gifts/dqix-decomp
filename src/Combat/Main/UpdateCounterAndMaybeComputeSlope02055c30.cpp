#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct S02055080;
void* GetSubField0x8_020550c0(struct S02055080* p);

struct Wrap020578e8;
float ComputeSlope020578e8(Wrap020578e8* a, Wrap020578e8* b);

struct Obj02055c30 {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* ptr30;
    char pad2[0x68];
    float field9c;
    unsigned short fieldA0;
};

// USA: func_02055c30
ARM void UpdateCounterAndMaybeComputeSlope02055c30(struct Obj02055c30* obj) {
    void* subPtr = GetSubField0x8_020550c0((struct S02055080*)obj->ptr30);
    if (*(unsigned char*)((char*)subPtr + 4) <= 1) return;
    if (*(unsigned char*)((char*)subPtr + 4) <= obj->fieldA0) return;

    SignedAllocatorHeader* elem = ((SignedAllocatorList*)((char*)obj->ptr30 + 0x74))->GetNthElement(obj->fieldA0);
    if (elem == NULL) return;
    if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) return;

    obj->fieldA0 = obj->fieldA0 + 1;
    if (obj->fieldA0 >= *(unsigned char*)((char*)subPtr + 4)) {
        obj->field9c = 0;
        return;
    }
    SignedAllocatorHeader* elem2 = ((SignedAllocatorList*)((char*)obj->ptr30 + 0x74))->GetNthElement(obj->fieldA0);
    if (elem2 == NULL) return;
    obj->field9c = ComputeSlope020578e8((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
}
