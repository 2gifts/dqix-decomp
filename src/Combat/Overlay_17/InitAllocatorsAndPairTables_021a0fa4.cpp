// JPN: func_ov017_021a1a40
#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void RestorePairTableFromBuffer(int* out);
void WriteGlobalPair020bb92c(int* src);
extern "C" int func_020bb588(unsigned int size, int a, int b);
extern "C" void func_0207de48(void* p, int a, int b);

extern AllocatorUnion data_02114e20;

struct IndexEntry021d67a0 { int index; int pad4; };
struct SizeEntry021d67a4 { int size; int pad4; };
extern IndexEntry021d67a0 data_ov017_021d67a0[];
extern SizeEntry021d67a4 data_ov017_021d67a4[];

struct Triple0xc021a0fa4 { int v; int pad4; int pad8; };
extern Triple0xc021a0fa4 data_ov017_021d66e0[];
extern Triple0xc021a0fa4 data_ov017_021d66e8[];
extern Triple0xc021a0fa4 data_ov017_021d66e4[];
extern Triple0xc021a0fa4 data_ov017_021d67d0[];
extern Triple0xc021a0fa4 data_ov017_021d67d8[];
extern Triple0xc021a0fa4 data_ov017_021d67d4[];

#if defined(jpn)
enum { PairBufferOffset = 0x2868, GlobalPairOffset = 0x28c0, SecondPairBufferOffset = 0x2898, FirstArenaOffset = 0xe4c, SecondArenaOffset = 0xebc, EntryBaseOffset = 0x27c };
#else
enum { PairBufferOffset = 0x2a78, GlobalPairOffset = 0x2ad0, SecondPairBufferOffset = 0x2aa8, FirstArenaOffset = 0xe9c, SecondArenaOffset = 0xf0c, EntryBaseOffset = 0x2cc };
#endif

// USA: func_ov017_021a0fa4  (semantic: InitAllocatorsAndPairTables_021a0fa4)
extern "C" ARM void func_ov017_021a0fa4(char* self) {
    int i;
    int size;
    for (i = 0; (size = data_ov017_021d67a4[i].size) != 0; i++) {
        void* p = AllocateAligned4(&data_02114e20, size);
        int idx = data_ov017_021d67a0[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + idx * 0x14);
        alloc->CreateTypeA(p, size);
    }

    RestorePairTableFromBuffer((int*)(self + PairBufferOffset));
    WriteGlobalPair020bb92c((int*)(self + GlobalPairOffset));
    func_020bb588(0x20000, 0, 0);

    int cond;
    for (i = 0; (cond = data_ov017_021d66e4[i].v) != 0; i++) {
        int a = data_ov017_021d66e0[i].v;
        int b = data_ov017_021d66e8[i].v;
        func_0207de48((self + EntryBaseOffset) + a * 0x70, cond, b);
    }

    RestorePairTableFromBuffer((int*)(self + SecondPairBufferOffset));

    for (i = 0; (cond = data_ov017_021d67d4[i].v) != 0; i++) {
        int a = data_ov017_021d67d0[i].v;
        int b = data_ov017_021d67d8[i].v;
        func_0207de48((self + EntryBaseOffset) + a * 0x70, cond, b);
    }

    func_0207de48(self + FirstArenaOffset, 0x8000, 0x400);
    func_0207de48(self + SecondArenaOffset, 0x4000, 0x400);
}
