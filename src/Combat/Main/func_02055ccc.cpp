#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct S02055080;
void* GetSubField0xC(struct S02055080* p);

struct Point4_020578e8 {
    int x;
    float y;
    float z;
    float w;
};

struct Wrap020578e8;
extern "C" float _Z20ComputeSlope020578e8P12Wrap020578e8S0_(Wrap020578e8* a, Wrap020578e8* b);

struct Elem02055ccc {
    Point4_020578e8* p;
};

struct Sub02055ccc {
    char pad0[0x10];
    unsigned char f10[3];
    unsigned char f13;
};

struct Obj02055ccc {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* ptr30;
    char pad2[0x70];
    float fieldA4[3];
    float fieldB0;
    float fieldB4;
    float fieldB8;
    unsigned short fieldBC[3];
    unsigned short fieldC2;
};

// USA: func_02055ccc
extern "C" ARM void func_02055ccc(struct Obj02055ccc* self) {
    Sub02055ccc* sub = (Sub02055ccc*)GetSubField0xC((struct S02055080*)self->ptr30);

    for (int i = 0; i < 3; i++) {
        if (sub->f10[i] <= 1)
            continue;
        if (sub->f10[i] <= self->fieldBC[i])
            continue;
        Elem02055ccc* elem = (Elem02055ccc*)((SignedAllocatorList*)((char*)self->ptr30 + 0x80 + i * 12))->GetNthElement(self->fieldBC[i]);
        if (elem == 0)
            continue;
        if ((unsigned int)elem->p->x >= (unsigned int)self->field4)
            continue;
        *(unsigned short*)((char*)self + 0xbc + i * 2) = *(unsigned short*)((char*)self + 0xbc + i * 2) + 1;
        if (self->fieldBC[i] >= sub->f10[i]) {
            self->fieldA4[i] = 0;
            continue;
        }
        Elem02055ccc* elem2 = (Elem02055ccc*)((SignedAllocatorList*)((char*)self->ptr30 + 0x80 + i * 12))->GetNthElement(self->fieldBC[i]);
        if (elem2 == 0)
            continue;
        self->fieldA4[i] = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

    if (sub->f13 <= 1)
        return;
    if (sub->f13 <= self->fieldC2)
        return;
    Elem02055ccc* elem = (Elem02055ccc*)((SignedAllocatorList*)((char*)self->ptr30 + 0xa4))->GetNthElement(self->fieldC2);
    if (elem == 0)
        return;
    if ((unsigned int)elem->p->x >= (unsigned int)self->field4)
        return;
    self->fieldC2 = self->fieldC2 + 1;
    if (self->fieldC2 >= sub->f13) {
        self->fieldB0 = self->fieldB4 = self->fieldB8 = 0;
        return;
    }
    Elem02055ccc* elem2 = (Elem02055ccc*)((SignedAllocatorList*)((char*)self->ptr30 + 0xa4))->GetNthElement(self->fieldC2);
    if (elem2 == 0)
        return;
    self->fieldB0 = (elem2->p->y - elem->p->y) / (float)(elem2->p->x - elem->p->x);
    self->fieldB4 = (elem2->p->z - elem->p->z) / (float)(elem2->p->x - elem->p->x);
    self->fieldB8 = (elem2->p->w - elem->p->w) / (float)(elem2->p->x - elem->p->x);
}
