#include <globaldefs.h>
#include "GameState/GameState.h"

struct PartyInfo {
    unsigned char pad[0xf78];
    signed char order[4];
    unsigned char count;
};

unsigned char * GetFieldAt0x150_02053c6c(unsigned char*);
void CleanInvalidateCacheRange(const void *p, unsigned int size);
extern "C" void LoadToMainObjStandardPalette(const void *src, unsigned int offset, unsigned int size);

// USA: func_ov002_02161a8c
extern "C" ARM void func_ov002_02161a8c() {
    unsigned short colors[2];
    unsigned short *color;
    colors[1]           = 0x7fff;
    colors[0]           = 0x2108;
    GameState *gs       = GameState::GetInstance();
    PartyInfo *party    = (PartyInfo *)GetPtrField0x2a04_02010828(gs);
    unsigned char count = party->count;
    for (unsigned char i = 0; i < count; i++) {
        int idx      = party->order[i];
        color        = &colors[1];
        GameObject *member = gs->GetPartyMemberByIndex(idx);
        if (member == 0) continue;
        unsigned char *f = GetFieldAt0x150_02053c6c((unsigned char*)member);
        if (f == 0) continue;
        unsigned char v = f[0x56a];
        if (v == 1 || v == 15) color = &colors[0];
        int pal = (idx + 9) * 16;
        CleanInvalidateCacheRange(color, 2);
        pal += 13;
        LoadToMainObjStandardPalette(color, pal * 2, 2);
    }
}
