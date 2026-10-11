// JPN: func_ov017_021a10e0
#if defined(jpn)
enum { RegionOffset278 = 0x68, RegionOffsetad0 = 0x8c0, RegionOffset2cc = 0x27c, RegionOffset2a8 = 0x98, RegionOffset29c = 0x24c, RegionOffset30c = 0x2bc };
#else
enum { RegionOffset278 = 0x278, RegionOffsetad0 = 0xad0, RegionOffset2cc = 0x2cc, RegionOffset2a8 = 0x2a8, RegionOffset29c = 0x29c, RegionOffset30c = 0x30c };
#endif

#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void RestorePairTableFromBuffer(int* out);
extern "C" void _Z23WriteGlobalPair020bb92cPi(int* src);
extern "C" void func_0207de48(void* p, int a, int b);

extern AllocatorUnion data_02114e20;

struct IndexEntry021d66c8 { int index; int pad4; };
struct SizeEntry021d66cc { int size; int pad4; };
extern IndexEntry021d66c8 data_ov017_021d66c8[];
extern SizeEntry021d66cc data_ov017_021d66cc[];

struct Triple0xc021a0630 { int v; int pad4; int pad8; };
extern Triple0xc021a0630 data_ov017_021d6818[];
extern Triple0xc021a0630 data_ov017_021d6820[];
extern Triple0xc021a0630 data_ov017_021d681c[];
extern Triple0xc021a0630 data_ov017_021d6800[];
extern Triple0xc021a0630 data_ov017_021d6808[];
extern Triple0xc021a0630 data_ov017_021d6804[];

// USA: func_ov017_021a0630
extern "C" ARM void func_ov017_021a0630(char* self) {
    int i;
    int size;
    for (i = 0; (size = data_ov017_021d66cc[i].size) != 0; i++) {
        void* p = AllocateAligned4(&data_02114e20, size);
        int idx = data_ov017_021d66c8[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + idx * 0x14);
        alloc->CreateTypeA(p, size);
    }

    RestorePairTableFromBuffer((int*)(self + RegionOffset278 + 0x2800));
    _Z23WriteGlobalPair020bb92cPi((int*)(self + RegionOffsetad0 + 0x2000));

    int cond;
    for (i = 0; (cond = data_ov017_021d681c[i].v) != 0; i++) {
        int a = data_ov017_021d6818[i].v;
        int b = data_ov017_021d6820[i].v;
        func_0207de48((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    RestorePairTableFromBuffer((int*)(self + RegionOffset2a8 + 0x2800));

    for (i = 0; (cond = data_ov017_021d6804[i].v) != 0; i++) {
        int a = data_ov017_021d6800[i].v;
        int b = data_ov017_021d6808[i].v;
        func_0207de48((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    func_0207de48(self + RegionOffset29c + 0xc00, 0x8000, 0x400);
    func_0207de48(self + RegionOffset30c + 0xc00, 0x4000, 0x400);
}
