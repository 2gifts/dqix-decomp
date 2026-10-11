// JPN: func_ov017_0219a04c
#if defined(jpn)
enum { RegionOffset4447 = 0x4197 };
#else
enum { RegionOffset4447 = 0x4447 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
void EnqueueEventTag154_021d0860(unsigned char a, unsigned char b, unsigned char c);

// USA: func_ov017_0219949c
extern "C" ARM void func_ov017_0219949c(void* ctx, int combatantId, int matchType, unsigned char slotId, signed char threshold) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)func_0202ae18();
    signed char arrEntry = GetSearchStructCurrentArrEntry(search);

    if (matchType != arrEntry && matchType != 4) {
        return;
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    GameObject* target = battle->GetUnknownGameObject();
    unsigned short v1 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant);
    unsigned short v2 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)target);

    if (v1 != v2) {
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }

    if (threshold != *(signed char*)((char*)ctx + RegionOffset4447)) {
        func_ov017_0218b5b0();
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }

    unsigned char arrEntry2 = (unsigned char)GetSearchStructCurrentArrEntry(search);
    if (slotId < arrEntry2) {
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }
    EnqueueEventTag154_021d0860(slotId, 1, 0);
}
