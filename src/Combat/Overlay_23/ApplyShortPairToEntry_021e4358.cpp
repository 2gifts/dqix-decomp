#include <globaldefs.h>

void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void func_0205ac40(void* obj, void* entry);

struct Obj021e4358 {
    char pad0[0xc8];
    void* fc8;
    void* fcc;
    #if defined(jpn)
    char pad1[0x4e4 - 0xd0];
#else
    char pad1[0x4e8 - 0xd0];
#endif
    int f4e8;
    #if defined(jpn)
    char pad2[0x56c - 0x4e8];
#else
    char pad2[0x634 - 0x4ec];
#endif
    unsigned short f634;
};

struct Entry021e4358 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x26 - 0x23];
    unsigned char f26;
};

// USA: func_ov023_021e4358  (semantic: ApplyShortPairToEntry_021e4358)
extern "C" ARM void func_ov023_021e4358(Obj021e4358* obj) {
    if (obj->f4e8 == 1) return;
    short lo, hi;
    void* entry = obj->fcc;
    ComputeShortPair_021e2bdc((char*)obj + 0xd4, 0x20, &lo, &hi);
    if (obj->f634 & 0x400) {
        lo++;
        hi++;
        obj->f634 &= ~0x400;
    }
    Entry021e4358* e = (Entry021e4358*)entry;
    e->f14 = lo << 12;
    e->f18 = hi << 12;
    e->f22 = 0x7b;
    e->f26 = 2;
    func_0205ac40(obj->fc8, entry);
}
