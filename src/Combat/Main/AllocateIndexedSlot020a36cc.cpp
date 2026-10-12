#include <globaldefs.h>

#if defined(jpn)
#define AllocateIndexedSlot020a36cc func_020a5444
#endif

#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_020a0cc4(unsigned int);
struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(Struct02012dd0* self);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct FlagStruct020a36cc {
    #if defined(jpn)
    unsigned char pad[0x1e0];
#else
    unsigned char pad[0x490];
#endif
    unsigned char field0x490;
};

#if defined(jpn)
extern "C" int func_020a5444(void** out, unsigned int idx);
#endif

// USA: func_020a36cc
ARM int AllocateIndexedSlot020a36cc(void** out, unsigned int idx) {
    int base = func_ov017_0218b5b0();
    unsigned int max = GetMaxAlloc02012dd0((Struct02012dd0*)&data_02114e20);
    if (max < idx) {
        func_020a0cc4(idx);
        ((FlagStruct020a36cc*)(base + 0x4000))->field0x490 = 1;
    }
    *out = AllocateAligned4(&data_02114e20, idx);
    return 1;
}
