#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct S02055080;
void* GetField0x4Field0x4OrNull(struct S02055080* p);

struct Wrap020578e8;
extern "C" float _Z20ComputeSlope020578e8P12Wrap020578e8S0_(Wrap020578e8* a, Wrap020578e8* b);

struct Obj020559cc {
    char pad0[4];
    int field4;
    char pad8[0x28];
    void* ptr30;
    char pad34[0x64 - 0x34];
    float slope64[3];
    float slope70[3];
    float slope7c[3];
    unsigned short counter88[3];
    unsigned short counter8e[3];
    unsigned short counter94[3];
};

// USA: func_020559cc
extern "C" ARM void func_020559cc(struct Obj020559cc* obj) {
    unsigned char* subPtr = (unsigned char*)GetField0x4Field0x4OrNull((struct S02055080*)obj->ptr30);

    unsigned char* counts = subPtr;
    counts += 0x24;
    for (int i = 0; i < 3; i++) {
        unsigned char count = counts[i];
        if (count <= 1) continue;
        if (count <= obj->counter88[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x8 + i * 12))->GetNthElement(obj->counter88[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter88[i]++;
        if (obj->counter88[i] >= counts[i]) {
            obj->slope64[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x8 + i * 12))->GetNthElement(obj->counter88[i]);
        if (elem2 == NULL) continue;
        obj->slope64[i] = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        counts = subPtr + 0x27;
        unsigned char count = counts[i];
        if (count <= 1) continue;
        if (count <= obj->counter8e[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x2c + i * 12))->GetNthElement(obj->counter8e[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter8e[i]++;
        if (obj->counter8e[i] >= counts[i]) {
            obj->slope70[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x2c + i * 12))->GetNthElement(obj->counter8e[i]);
        if (elem2 == NULL) continue;
        obj->slope70[i] = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        counts = subPtr + 0x2a;
        unsigned char count = counts[i];
        if (count <= 1) continue;
        if (count <= obj->counter94[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x50 + i * 12))->GetNthElement(obj->counter94[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter94[i]++;
        if (obj->counter94[i] >= counts[i]) {
            obj->slope7c[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x50 + i * 12))->GetNthElement(obj->counter94[i]);
        if (elem2 == NULL) continue;
        obj->slope7c[i] = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }
}
