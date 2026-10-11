#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Layout02189284 {
    char pad[0x1f4];
    void* f1f4;
    void* f1f8;
    void* f1fc;
    SafeAllocator allocs[6];
};

// USA: func_ov008_02189284
ARM void SetupAllocators_02189284(Layout02189284* obj, SafeAllocator* alloc) {
    obj->allocs[0].CreateTypeA(alloc->Allocate(0xa000), 0xa000);
    obj->allocs[1].CreateTypeA(alloc->Allocate(R(0x800, 0xc00)), R(0x800, 0xc00));
    obj->allocs[2].CreateTypeA(alloc->Allocate(0x5c00), 0x5c00);
    obj->allocs[3].CreateTypeA(alloc->Allocate(0x800), 0x800);
    obj->allocs[4].CreateTypeA(alloc->Allocate(R(0x1c00, 0x2400)), R(0x1c00, 0x2400));
    obj->allocs[5].CreateTypeA(alloc->Allocate(0x5400), 0x5400);
    obj->f1f8 = alloc->Allocate(0x140);
    obj->f1f4 = alloc->Allocate(0x54);
    obj->f1fc = alloc->Allocate(0x8);
}
