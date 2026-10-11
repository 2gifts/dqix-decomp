// JPN: func_ov017_021a16b0
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
ARM void RestorePairTableFromBuffer(int* out);
ARM void WriteGlobalPair020bb92c(int* src);
extern "C" void func_0207de48(void* p, int a, int b);

extern AllocatorUnion data_02114e20;

struct PairEntry021d6830 { int v; int pad; };
extern struct PairEntry021d6830 data_ov017_021d6830[];
extern struct PairEntry021d6830 data_ov017_021d6834[];

struct TripleEntry021d66f8 { int v; int pad0; int pad1; };
extern struct TripleEntry021d66f8 data_ov017_021d66f8[];
extern struct TripleEntry021d66f8 data_ov017_021d66fc[];
extern struct TripleEntry021d66f8 data_ov017_021d6700[];

struct TripleEntry021d6740 { int v; int pad0; int pad1; };
extern struct TripleEntry021d6740 data_ov017_021d6740[];
extern struct TripleEntry021d6740 data_ov017_021d6744[];
extern struct TripleEntry021d6740 data_ov017_021d6748[];

#if defined(jpn)
enum { PairBufferOffset = 0x2868, GlobalPairOffset = 0x28c0, SecondPairBufferOffset = 0x2898, FirstArenaOffset = 0xe4c, SecondArenaOffset = 0xebc, EntryBaseOffset = 0x27c };
#else
enum { PairBufferOffset = 0x2a78, GlobalPairOffset = 0x2ad0, SecondPairBufferOffset = 0x2aa8, FirstArenaOffset = 0xe9c, SecondArenaOffset = 0xf0c, EntryBaseOffset = 0x2cc };
#endif

// USA: func_ov017_021a0c0c  (semantic: InitAllocatorsAndPairTables_021a0c0c)
extern "C" ARM void func_ov017_021a0c0c(char* self) {
    int i;

    int size;
    for (i = 0; (size = data_ov017_021d6834[i].v) != 0; i++) {
        void* p = AllocateAligned4(&data_02114e20, size);
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + data_ov017_021d6830[i].v * 0x14);
        alloc->CreateTypeA(p, size);
    }

    RestorePairTableFromBuffer((int*)(self + PairBufferOffset));
    WriteGlobalPair020bb92c((int*)(self + GlobalPairOffset));

    for (i = 0; data_ov017_021d66fc[i].v != 0; i++) {
        func_0207de48(self + EntryBaseOffset + data_ov017_021d66f8[i].v * 0x70, data_ov017_021d66fc[i].v, data_ov017_021d6700[i].v);
    }

    RestorePairTableFromBuffer((int*)(self + SecondPairBufferOffset));

    for (i = 0; data_ov017_021d6744[i].v != 0; i++) {
        func_0207de48(self + EntryBaseOffset + data_ov017_021d6740[i].v * 0x70, data_ov017_021d6744[i].v, data_ov017_021d6748[i].v);
    }

    func_0207de48(self + FirstArenaOffset, 0x8000, 0x400);
    func_0207de48(self + SecondArenaOffset, 0x4000, 0x400);
}
