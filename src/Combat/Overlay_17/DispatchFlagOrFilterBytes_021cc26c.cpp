#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" void func_020531f0(void* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);

struct Obj02052f44;
int FilterBytesAndInit02052f44(struct Obj02052f44* obj, signed char* src, int len);

struct Src021cc26c {
    unsigned char pad0[4];
    unsigned char id;
    unsigned char len;
    unsigned char pad6[0xa - 0x6];
    unsigned char flag;
};

// JPN: func_ov017_021cc714
// USA: func_ov017_021cc26c
ARM void DispatchFlagOrFilterBytes_021cc26c(int unused0, Src021cc26c* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    int id = src->id;
    int len = src->len;
    GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, id);
    if (combatant == NULL) return;

    if (src->flag != 0) {
        if (CheckSubstructByte0x7cPositive((signed char*)combatant) == 0) return;
        func_020531f0(combatant);
        return;
    }

    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    void* h = func_ov017_021b8478(table);
    if (h != NULL) {
        if (TestBitAt0x34((unsigned char*)h, id & 0xff) != 0) return;
    }
    FilterBytesAndInit02052f44((struct Obj02052f44*)combatant, (signed char*)((char*)src + 6), len);
}
