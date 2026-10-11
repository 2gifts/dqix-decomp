#include <globaldefs.h>
#if defined(jpn)
enum { kPaletteFlagOffset = 0xa6c };
#else
enum { kPaletteFlagOffset = 0xccc };
#endif
#include "GameState/GameState.h"
#include "System/Cache.h"

extern int GetFieldAt0x150(unsigned char* obj);
extern void* GetData02109dcc(void);

extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" int LoadToSubObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToSubBGStandardPalette(int src, int dstOffset, unsigned int size);

// USA: func_020dc70c
ARM void UpdateObjPaletteEntry020dc70c(int id, int p1, int p2, int p3, unsigned short p4, unsigned short p5, unsigned int count) {
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetPartyMemberByIndex(id);
    if (c == NULL)
        return;
    int monster = GetFieldAt0x150((unsigned char*)c);
    if (monster == 0)
        return;
    unsigned char idx = *(unsigned char*)(monster + 0x56a);
    unsigned int off = (p4 << 4) + p5;
    unsigned int end = count + (off << 1);
    if (end > 0x200)
        return;
    unsigned int size = off << 1;
    int base = (int)GetData02109dcc();
    int src = base + (idx << 5) + (p1 << 1);
    CleanInvalidateCacheRange((void*)src, count);
    if (p2 == 0) {
        if (p3 != 0)
            LoadToMainObjStandardPalette(src, size, count);
        else
            LoadToMainBGStandardPalette(src, size, count);
    } else {
        if (p3 != 0)
            LoadToSubObjStandardPalette(src, size, count);
        else
            LoadToSubBGStandardPalette(src, size, count);
    }
    *(int*)((unsigned char*)GameState::GetInstance() + 0x5000 + kPaletteFlagOffset) &= ~2;
}
