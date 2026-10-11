#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8468(void* p);
void* GetField6b0_021b8470(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);
GameObject* GetCombatantWithFlag0x100(GameState* bs, int id);
int GetFieldAt0x150(unsigned char* obj);

struct Word78Bits_021c8588 {
    unsigned int lo : 30;
    unsigned int flag : 1;
    unsigned int hi : 1;
};

// JPN: func_ov017_021c8a38
// USA: func_ov017_021c8588  (semantic: ApplyEntriesAndSetWorkFlag_021c8588)
extern "C" ARM void func_ov017_021c8588(int a, signed char* b, GameState* bs, char* d) {
#if defined(jpn)
 enum {regionalOffset0=0x3508, regionalOffset1=0x8b4};
#else
 enum {regionalOffset0=0x3718, regionalOffset1=0x94c};
#endif
    void* handle;
    signed char* p0;
    int i;
    void* inner = *(void**)(d + regionalOffset0);
    handle = func_ov017_021b8468(inner);
    if (handle == 0) return;
    if (GetField6b0_021b8470(inner) == 0) return;

    p0 = b + 4;
    for (i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x100(bs, i);
        if (combatant == 0) continue;
        int field150 = GetFieldAt0x150((unsigned char*)combatant);
        if (field150 == 0) continue;
        signed char v0 = p0[i];
        signed char v1 = *(p0 + i + 4);
        if (v0 >= 0) *(int*)((char*)field150 + regionalOffset1) = v0;
        if (v1 < 0) continue;
        ((Word78Bits_021c8588*)((char*)field150 + 0x78))->flag = (unsigned short)v1;
    }

    if (*((unsigned char*)inner + 3) != 0 && handle != 0) {
        SetCombatWorkFlags0x55f4(handle, 0x4000000 << a);
    }
}
