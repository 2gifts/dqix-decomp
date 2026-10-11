#include <globaldefs.h>

struct PartyInfo {
    unsigned char pad[0xf78];
    signed char order[4];
    unsigned char count;
};

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" PartyInfo *_Z17GetPtrField0x2a04P9GameState(void *gs);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
extern "C" unsigned char *_Z15GetFieldAt0x150Ph(void *member);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *p, unsigned int size);
extern "C" void LoadToMainObjStandardPalette(const void *src, unsigned int offset, unsigned int size);

// USA: func_ov002_02161a8c
extern "C" ARM void func_ov002_02161a8c() {
    unsigned short colors[2];
    unsigned short *color;
    colors[1]           = 0x7fff;
    colors[0]           = 0x2108;
    void *gs            = _ZN9GameState11GetInstanceEv();
    PartyInfo *party    = _Z17GetPtrField0x2a04P9GameState(gs);
    unsigned char count = party->count;
    for (unsigned char i = 0; i < count; i++) {
        int idx      = party->order[i];
        color        = &colors[1];
        void *member = _ZN9GameState21GetPartyMemberByIndexEi(gs, idx);
        if (member == 0) continue;
        unsigned char *f = _Z15GetFieldAt0x150Ph(member);
        if (f == 0) continue;
        unsigned char v = f[0x56a];
        if (v == 1 || v == 15) color = &colors[0];
        int pal = (idx + 9) * 16;
        _Z25CleanInvalidateCacheRangePKvj(color, 2);
        pal += 13;
        LoadToMainObjStandardPalette(color, pal * 2, 2);
    }
}
