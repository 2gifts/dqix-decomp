#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Packed10x3_021cb2f4 {
    unsigned int f0 : 3;
    unsigned int f1 : 3;
    unsigned int f2 : 3;
    unsigned int f3 : 3;
    unsigned int f4 : 3;
    unsigned int f5 : 3;
    unsigned int f6 : 3;
    unsigned int f7 : 3;
    unsigned int f8 : 3;
    unsigned int f9 : 3;
    unsigned int pad : 2;
};

struct Src021cb2f4 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    Packed10x3_021cb2f4 word8;
    Packed10x3_021cb2f4 wordc;
    unsigned short field10;
    unsigned char field12;
};

struct Entry021cb2f4 {
    unsigned char pad0[0x36];
    unsigned short field36;
    unsigned char pad1[0x5c - 0x38];
    unsigned char chars0[0x14];
    unsigned char pad2[0x7f - 0x70];
    unsigned char chars1[0x14];
    unsigned char pad3[0xa4 - 0x93];
};

struct Ret021cb2f4 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x2a - 0xa];
    signed char field2a;
    unsigned char pad2[0x158 - 0x2b];
    Entry021cb2f4 entries[8];
};

// USA: func_ov017_021cb2f4
// JPN: func_ov017_021cb7a4
extern "C" ARM void func_ov017_021cb2f4(int unused0, Src021cb2f4* src, GameState* battleStruct, unsigned char* self) {
#if defined(jpn)
    void* h = *(void**)(self + 0x3000 + 0x508);
#else
    void* h = *(void**)(self + 0x3000 + 0x718);
#endif
    void* work = GetField6b0_021b8470(h);
    if (!work) return;
    Ret021cb2f4* r = *(Ret021cb2f4**)((unsigned char*)work + 0x8000 + 0xe18);
    if (!r) return;
    int val = GetField0x3acValue(battleStruct);
    if (r->field2a == val) return;
    if (r->field8 != src->field4) return;
    int idx = (int)src->field6 - 0xc0;
    if (idx < 0) return;
    if (idx >= 8) return;
    Entry021cb2f4* entry = &r->entries[idx];
    if (src->field12 == 1) {
        entry->chars0[0] = (unsigned char)src->word8.f0;
        entry->chars0[1] = (unsigned char)src->word8.f1;
        entry->chars0[2] = (unsigned char)src->word8.f2;
        entry->chars0[3] = (unsigned char)src->word8.f3;
        entry->chars0[4] = (unsigned char)src->word8.f4;
        entry->chars0[5] = (unsigned char)src->word8.f5;
        entry->chars0[6] = (unsigned char)src->word8.f6;
        entry->chars0[7] = (unsigned char)src->word8.f7;
        entry->chars0[8] = (unsigned char)src->word8.f8;
        entry->chars0[9] = (unsigned char)src->word8.f9;
        entry->chars0[10] = (unsigned char)src->wordc.f0;
        entry->chars0[11] = (unsigned char)src->wordc.f1;
        entry->chars0[12] = (unsigned char)src->wordc.f2;
        entry->chars0[13] = (unsigned char)src->wordc.f3;
        entry->chars0[14] = (unsigned char)src->wordc.f4;
        entry->chars0[15] = (unsigned char)src->wordc.f5;
        entry->chars0[16] = (unsigned char)src->wordc.f6;
        entry->chars0[17] = (unsigned char)src->wordc.f7;
        entry->chars0[18] = (unsigned char)src->wordc.f8;
        entry->chars0[19] = (unsigned char)src->wordc.f9;
        entry->field36 = src->field10;
    } else {
        entry->chars1[0] = (unsigned char)src->word8.f0;
        entry->chars1[1] = (unsigned char)src->word8.f1;
        entry->chars1[2] = (unsigned char)src->word8.f2;
        entry->chars1[3] = (unsigned char)src->word8.f3;
        entry->chars1[4] = (unsigned char)src->word8.f4;
        entry->chars1[5] = (unsigned char)src->word8.f5;
        entry->chars1[6] = (unsigned char)src->word8.f6;
        entry->chars1[7] = (unsigned char)src->word8.f7;
        entry->chars1[8] = (unsigned char)src->word8.f8;
        entry->chars1[9] = (unsigned char)src->word8.f9;
        entry->chars1[10] = (unsigned char)src->wordc.f0;
        entry->chars1[11] = (unsigned char)src->wordc.f1;
        entry->chars1[12] = (unsigned char)src->wordc.f2;
        entry->chars1[13] = (unsigned char)src->wordc.f3;
        entry->chars1[14] = (unsigned char)src->wordc.f4;
        entry->chars1[15] = (unsigned char)src->wordc.f5;
        entry->chars1[16] = (unsigned char)src->wordc.f6;
        entry->chars1[17] = (unsigned char)src->wordc.f7;
        entry->chars1[18] = (unsigned char)src->wordc.f8;
        entry->chars1[19] = (unsigned char)src->wordc.f9;
    }
}
