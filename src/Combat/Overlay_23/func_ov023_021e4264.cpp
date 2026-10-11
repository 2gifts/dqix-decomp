#if defined(jpn)
enum {regionalOffset0=0x56c};
#else
enum {regionalOffset0=0x634};
#endif
#include <globaldefs.h>

void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2);
extern "C" void func_0205ac40(void* obj, void* entry);

struct Obj021e4264 {
    char pad0[0xc8];
    void* fc8;
    void* fcc;
    char pad1[regionalOffset0 - 0xd0];
    unsigned short f634;
};

struct Entry021e4264 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x26 - 0x23];
    unsigned char f26;
};

// JPN: func_ov023_021e4488
// USA: func_ov023_021e4264
extern "C" ARM void func_ov023_021e4264(Obj021e4264* obj) {
    short lo, hi;
    Entry021e4264* entry = (Entry021e4264*)obj->fcc;
    ComputeShortPair_021e2bdc((char*)obj + 0xd4, 0x11, &lo, &hi);
    if (obj->f634 & 0x100) {
        lo--;
        hi++;
    }
    Entry021e4264* e0 = (Entry021e4264*)((char*)entry + 0x50);
    e0->f14 = lo << 12;
    e0->f18 = hi << 12;
    e0->f22 = 0x7f;
    e0->f26 = 2;
    func_0205ac40(obj->fc8, e0);

    entry = (Entry021e4264*)obj->fcc;
    ComputeShortPair_021e2bdc((char*)obj + 0xd4, 0x12, &lo, &hi);
    if (obj->f634 & 0x200) {
        lo++;
        hi++;
    }
    Entry021e4264* e1 = (Entry021e4264*)((char*)entry + 0x78);
    e1->f14 = lo << 12;
    e1->f18 = hi << 12;
    e1->f22 = 0x7e;
    e1->f26 = 2;
    func_0205ac40(obj->fc8, e1);
}
