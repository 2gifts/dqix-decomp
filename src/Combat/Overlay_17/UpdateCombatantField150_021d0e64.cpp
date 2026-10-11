#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

struct ArgA021d0e64 {
    unsigned char pad0[4];
    signed char field4;
    unsigned char field5;
};

// JPN: func_ov017_021d12dc
// USA: func_ov017_021d0e64
ARM void UpdateCombatantField150_021d0e64(void* unused0, ArgA021d0e64* a1, GameState* bs, void* a3) {
#if defined(jpn)
 enum {regionalOffset0=0xa6c};
#else
 enum {regionalOffset0=0xccc};
#endif
    GameObject* c = bs->GetPartyMemberByIndex(a1->field4);
    if (!c) return;
    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    unsigned char* f = (unsigned char*)field150;
    if (f[0x56a] != a1->field5) {
        short v = *(short*)(f + 0x488);
        if (v < 0) {
            *(short*)((char*)c + 2) = -1;
            func_ov017_0218f5a4(a3, a1->field4, 0, 0, 0);
        }
    }
    f[0x56a] = a1->field5;
    *(int*)((char*)bs + 0x5000 + regionalOffset0) |= 2;
}
