#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct0215efb8;
ARM void InitStruct0215efb8(Struct0215efb8* s);

struct ResetLayout_0215e6d8;
ARM void ResetStruct_0215e6d8(ResetLayout_0215e6d8* s);

ARM int LoadBattleBlock020ac460(void* dst);

#if defined(jpn)
enum { kAllocDelta = -8, kEarlyDelta = -0x28, kLateDelta = 0x58, kFirstSize = 0x15000, kSecondSize = 0x1c00, kFifthSize = 0x1400, kBlockSize = 0x2a8 };
#else
enum { kAllocDelta = 0, kEarlyDelta = 0, kLateDelta = 0, kFirstSize = 0x14c00, kSecondSize = 0x2400, kFifthSize = 0x1800, kBlockSize = 0x2f8 };
#endif

// USA: func_ov012_02184884  (semantic: InitBattleAllocatorsAndBuffers_02184884)
extern "C" ARM void func_ov012_02184884(char* self, SafeAllocator* alloc) {
    if (alloc == 0) return;

#if !defined(jpn)
    void* p0 = alloc->Allocate(0x28);
    *(void**)(self + 0x0) = p0;
    if (p0 != 0) InitStruct0215efb8((Struct0215efb8*)p0);

    void* p4 = alloc->Allocate(0x10);
    *(void**)(self + 0x4) = p4;
    if (p4 != 0) ResetStruct_0215e6d8((ResetLayout_0215e6d8*)p4);

#endif

    ((SafeAllocator*)(self + 0x20 + kAllocDelta))->CreateTypeA(alloc->Allocate(kFirstSize), kFirstSize);
    ((SafeAllocator*)(self + 0x34 + kAllocDelta))->CreateTypeA(alloc->Allocate(kSecondSize), kSecondSize);
    ((SafeAllocator*)(self + 0x48 + kAllocDelta))->CreateTypeA(alloc->Allocate(0x9400), 0x9400);
    ((SafeAllocator*)(self + 0x5c + kAllocDelta))->CreateTypeA(alloc->Allocate(0x800), 0x800);
    ((SafeAllocator*)(self + 0x70 + kAllocDelta))->CreateTypeA(alloc->Allocate(kFifthSize), kFifthSize);
    ((SafeAllocator*)(self + 0x84 + kAllocDelta))->CreateTypeA(alloc->Allocate(0x5400), 0x5400);
#if !defined(jpn)
    ((SafeAllocator*)(self + 0x98 + kAllocDelta))->CreateTypeA(alloc->Allocate(0x400), 0x400);
#endif

    *(void**)(self + 0x1000 + 0x364 + kEarlyDelta) = alloc->Allocate(kBlockSize);
    *(void**)(self + 0x1000 + 0x35c + kEarlyDelta) = alloc->Allocate(0x54);
    *(void**)(self + 0x1000 + 0x360 + kEarlyDelta) = alloc->Allocate(0x8);
#if !defined(jpn)
    *(void**)(self + 0x1000 + 0x36c) = alloc->Allocate(0x78);
#endif
#if !defined(jpn)
    *(void**)(self + 0x1000 + 0x368) = alloc->Allocate(0x54);
#endif
    *(void**)(self + 0x1000 + 0x3ac + kLateDelta) = alloc->Allocate(0x72);
    *(void**)(self + 0x1000 + 0x3b4 + kLateDelta) = alloc->Allocate(0x3c00);

    *(void**)(self + 0x1000 + 0x3bc + kLateDelta) = alloc->Allocate(0xf2);
    memset(*(void**)(self + 0x1000 + 0x3bc + kLateDelta), 0, 0xf2);

    *(void**)(self + 0x1000 + 0x3c0 + kLateDelta) = alloc->Allocate(0x12);
    memset(*(void**)(self + 0x1000 + 0x3c0 + kLateDelta), 0, 0x12);

    void* p3c8 = alloc->Allocate(0x38c);
    *(void**)(self + 0x1000 + 0x3c8 + kLateDelta) = p3c8;
    memset(p3c8, 0, 0x38c);

    void* p3cc = alloc->Allocate(0x3c);
    *(void**)(self + 0x1000 + 0x3cc + kLateDelta) = p3cc;
    memset(p3cc, 0, 0x3c);

    LoadBattleBlock020ac460(*(void**)(self + 0x1000 + 0x3cc + kLateDelta));

    void* p3d0 = alloc->Allocate(0x400);
    *(void**)(self + 0x1000 + 0x3d0 + kLateDelta) = p3d0;
    memset(p3d0, 0, 0x400);
}
