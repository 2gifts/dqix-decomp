// JPN: func_ov017_021a1470
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

#if defined(jpn)
enum { Field2a78 = 0x2868, Field2ad0 = 0x28c0, Field2aa8 = 0x2898, Field2cc = 0x27c, Fieldf0c = 0xebc, Fieldbfc = 0xbac, Fieldf34 = 0xee4, Fieldc24 = 0xbd4, Fieldf5c = 0xf0c, Fieldc4c = 0xbfc, Fieldf60 = 0xf10, Fieldc50 = 0xc00, Fieldf64 = 0xf14, Fieldc54 = 0xc04, Fieldf6c = 0xf1c, Fieldc5c = 0xc0c, Fieldf74 = 0xf24, Fieldc64 = 0xc14, Fieldf78 = 0xf28, Fieldc68 = 0xc18 };
#else
enum { Field2a78 = 0x2a78, Field2ad0 = 0x2ad0, Field2aa8 = 0x2aa8, Field2cc = 0x2cc, Fieldf0c = 0xf0c, Fieldbfc = 0xbfc, Fieldf34 = 0xf34, Fieldc24 = 0xc24, Fieldf5c = 0xf5c, Fieldc4c = 0xc4c, Fieldf60 = 0xf60, Fieldc50 = 0xc50, Fieldf64 = 0xf64, Fieldc54 = 0xc54, Fieldf6c = 0xf6c, Fieldc5c = 0xc5c, Fieldf74 = 0xf74, Fieldc64 = 0xc64, Fieldf78 = 0xf78, Fieldc68 = 0xc68 };
#endif

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_0207de48(void* p, int a, int b);
void RestorePairTableFromBuffer(int* out);
void WriteGlobalPair020bb92c(int* src);
extern "C" int func_020bb588(unsigned int size, int a, int b);

extern AllocatorUnion data_02114e20;

struct Entry8_021a09c8 { int a; int pad4; };
struct Entry0xc_021a09c8 { int a; int pad4; int pad8; };
extern Entry8_021a09c8 data_ov017_021d689c[];
extern Entry8_021a09c8 data_ov017_021d68a0[];
extern Entry0xc_021a09c8 data_ov017_021d6758[];
extern Entry0xc_021a09c8 data_ov017_021d6760[];
extern Entry0xc_021a09c8 data_ov017_021d675c[];
extern Entry0xc_021a09c8 data_ov017_021d6850[];
extern Entry0xc_021a09c8 data_ov017_021d6858[];
extern Entry0xc_021a09c8 data_ov017_021d6854[];

struct Block40_021a09c8 { unsigned int w[10]; };
struct Block8_021a09c8 { unsigned int w[2]; };

// USA: func_ov017_021a09c8  (semantic: InitAllocatorsAndTables_021a09c8)
extern "C" ARM void func_ov017_021a09c8(char* self) {
    int size;
    for (int i = 0; (size = data_ov017_021d68a0[i].a) != 0; i++) {
        void* buf = AllocateAligned4(&data_02114e20, size);
        int idx = data_ov017_021d689c[i].a;
        ((SafeAllocator*)((self + 0x38) + idx * 0x14))->CreateTypeA(buf, size);
    }

    RestorePairTableFromBuffer((int*)(self + Field2a78));
    WriteGlobalPair020bb92c((int*)(self + Field2ad0));
    func_020bb588(0x20000, 0, 0);

    {
        int n;
        for (int i = 0; (n = data_ov017_021d675c[i].a) != 0; i++) {
            func_0207de48((self + Field2cc) + data_ov017_021d6758[i].a * 0x70, n, data_ov017_021d6760[i].a);
        }
    }

    RestorePairTableFromBuffer((int*)(self + Field2aa8));

    {
        int n;
        for (int i = 0; (n = data_ov017_021d6854[i].a) != 0; i++) {
            func_0207de48((self + Field2cc) + data_ov017_021d6850[i].a * 0x70, n, data_ov017_021d6858[i].a);
        }
    }

    *(Block40_021a09c8*)(self + Fieldf0c) = *(Block40_021a09c8*)(self + Fieldbfc);
    *(Block40_021a09c8*)(self + Fieldf34) = *(Block40_021a09c8*)(self + Fieldc24);

    *(int*)(self + Fieldf5c) = *(int*)(self + Fieldc4c);
    *(int*)(self + Fieldf60) = *(int*)(self + Fieldc50);
    *(Block8_021a09c8*)(self + Fieldf64) = *(Block8_021a09c8*)(self + Fieldc54);
    *(Block8_021a09c8*)(self + Fieldf6c) = *(Block8_021a09c8*)(self + Fieldc5c);
    *(int*)(self + Fieldf74) = *(int*)(self + Fieldc64);
    *(int*)(self + Fieldf78) = *(int*)(self + Fieldc68);
}
