#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct S02055080;
void* GetField0x4Field0x4OrNull_020550a8(struct S02055080* p);

struct Wrap020578e8;
float ComputeSlope020578e8(Wrap020578e8* a, Wrap020578e8* b);

struct Sub020559cc {
    char pad0[0x24];
    unsigned char counts24[3];
    unsigned char counts27[3];
    unsigned char counts2a[3];
};

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
    struct Sub020559cc* sub = (struct Sub020559cc*)GetField0x4Field0x4OrNull_020550a8((struct S02055080*)obj->ptr30);

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->counts24[i];
        if (count <= 1) continue;
        if (count <= obj->counter88[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x8 + i * 12))->GetNthElement(obj->counter88[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter88[i]++;
        if (obj->counter88[i] >= sub->counts24[i]) {
            obj->slope64[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x8 + i * 12))->GetNthElement(obj->counter88[i]);
        if (elem2 == NULL) continue;
        obj->slope64[i] = ComputeSlope020578e8((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->counts27[i];
        if (count <= 1) continue;
        if (count <= obj->counter8e[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x2c + i * 12))->GetNthElement(obj->counter8e[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter8e[i]++;
        if (obj->counter8e[i] >= sub->counts27[i]) {
            obj->slope70[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x2c + i * 12))->GetNthElement(obj->counter8e[i]);
        if (elem2 == NULL) continue;
        obj->slope70[i] = ComputeSlope020578e8((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

    for (int i = 0; i < 3; i++) {
        unsigned char count = sub->counts2a[i];
        if (count <= 1) continue;
        if (count <= obj->counter94[i]) continue;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x50 + i * 12))->GetNthElement(obj->counter94[i]);
        if (elem == NULL) continue;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4) continue;
        obj->counter94[i]++;
        if (obj->counter94[i] >= sub->counts2a[i]) {
            obj->slope7c[i] = 0;
            continue;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x50 + i * 12))->GetNthElement(obj->counter94[i]);
        if (elem2 == NULL) continue;
        obj->slope7c[i] = ComputeSlope020578e8((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }
}
