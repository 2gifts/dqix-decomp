#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern AllocatorUnion data_02114e20;
void TailForward02012da4(AllocatorUnion* alloc, void* data);

struct ResetStruct0218eef0;
void InitCombatFieldStruct0218eef0(struct ResetStruct0218eef0* s);

struct FieldStruct0218f0c4 {
    unsigned int f00;
    void* f04;
    SafeAllocator* f08;
    unsigned int f0c;
    unsigned int f10;
    void* f14;
    unsigned int f18;
    unsigned char f1c;
    unsigned char pad1d[3];
    void* f20;
    void* f24;
    void* f28;
};

// USA: func_ov015_0218f0c4
extern "C" ARM void func_ov015_0218f0c4(void* p) {
    FieldStruct0218f0c4* s = (FieldStruct0218f0c4*)p;

    if (s->f08 != 0) {
        if (s->f1c == 0 || s->f1c == 1) {
            SafeAllocator* arr = s->f08;
            for (int i = 0; i < 10; i++, arr = (SafeAllocator*)((char*)arr + 0x14)) {
                void* signedAlloc = arr->GetSignedAllocator();
                arr->Destroy();
                TailForward02012da4(&data_02114e20, signedAlloc);
            }
        } else {
            void* signedAlloc = s->f08->GetSignedAllocator();
            s->f08->Destroy();
            TailForward02012da4(&data_02114e20, signedAlloc);
        }
        TailForward02012da4(&data_02114e20, s->f08);
    }

    if (s->f20 != 0) TailForward02012da4(&data_02114e20, s->f20);
    if (s->f14 != 0) TailForward02012da4(&data_02114e20, s->f14);
    if (s->f24 != 0) TailForward02012da4(&data_02114e20, s->f24);
    if (s->f28 != 0) TailForward02012da4(&data_02114e20, s->f28);

    if (s->f04 != 0) {
        *((unsigned char*)s->f04 + 4) = 0;
    }

    InitCombatFieldStruct0218eef0((struct ResetStruct0218eef0*)s);
}
