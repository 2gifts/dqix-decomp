#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct S02055080;
void* GetField0x4Field0x0Field0x0OrNull(struct S02055080* p);

struct Wrap020578e8;
extern "C" float _Z20ComputeSlope020578e8P12Wrap020578e8S0_(Wrap020578e8* a, Wrap020578e8* b);

struct Obj020557a4 {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* ptr30;
    char pad2[0x18];
    float field4c;
    float field50;
    float field54;
    float field58;
    unsigned short field5c;
    unsigned short field5e;
    unsigned short field60;
    unsigned short field62;
};

// USA: func_020557a4
extern "C" ARM void func_020557a4(struct Obj020557a4* obj) {
    void* subPtr = GetField0x4Field0x0Field0x0OrNull((struct S02055080*)obj->ptr30);

    {
        if (*(unsigned char*)((char*)subPtr + 0x10) <= 1)
            goto b2;
        if (*(unsigned char*)((char*)subPtr + 0x10) <= obj->field5c)
            goto b2;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0xec))->GetNthElement(obj->field5c);
        if (elem == NULL)
            goto b2;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b2;
        obj->field5c = obj->field5c + 1;
        if (obj->field5c >= *(unsigned char*)((char*)subPtr + 0x10)) {
            obj->field4c = 0;
            goto b2;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0xec))->GetNthElement(obj->field5c);
        if (elem2 == NULL)
            goto b2;
        obj->field4c = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

b2:
    {
        if (*(unsigned char*)((char*)subPtr + 0x11) <= 1)
            goto b3;
        if (*(unsigned char*)((char*)subPtr + 0x11) <= obj->field5e)
            goto b3;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0xf8))->GetNthElement(obj->field5e);
        if (elem == NULL)
            goto b3;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b3;
        obj->field5e = obj->field5e + 1;
        if (obj->field5e >= *(unsigned char*)((char*)subPtr + 0x11)) {
            obj->field50 = 0;
            goto b3;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0xf8))->GetNthElement(obj->field5e);
        if (elem2 == NULL)
            goto b3;
        obj->field50 = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

b3:
    {
        if (*(unsigned char*)((char*)subPtr + 0x12) <= 1)
            goto b4;
        if (*(unsigned char*)((char*)subPtr + 0x12) <= obj->field60)
            goto b4;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x104))->GetNthElement(obj->field60);
        if (elem == NULL)
            goto b4;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b4;
        obj->field60 = obj->field60 + 1;
        if (obj->field60 >= *(unsigned char*)((char*)subPtr + 0x12)) {
            obj->field54 = 0;
            goto b4;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x104))->GetNthElement(obj->field60);
        if (elem2 == NULL)
            goto b4;
        obj->field54 = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

b4:
    {
        if (*(unsigned char*)((char*)subPtr + 0x13) <= 1)
            goto done;
        if (*(unsigned char*)((char*)subPtr + 0x13) <= obj->field62)
            goto done;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x110))->GetNthElement(obj->field62);
        if (elem == NULL)
            goto done;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto done;
        obj->field62 = obj->field62 + 1;
        if (obj->field62 >= *(unsigned char*)((char*)subPtr + 0x13)) {
            obj->field58 = 0;
            goto done;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->ptr30 + 0x110))->GetNthElement(obj->field62);
        if (elem2 == NULL)
            goto done;
        obj->field58 = _Z20ComputeSlope020578e8P12Wrap020578e8S0_((Wrap020578e8*)elem, (Wrap020578e8*)elem2);
    }

done:
    ;
}