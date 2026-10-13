#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_02012fe4(void);
extern "C" int func_02018fbc(int seed, EventVec3* v);
struct Entry_02028bd0;
struct Entry_02028bd0* FindEntryByCurrentId02027cb0(void);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct PtrWithU16_021a3338 { unsigned short field0; };
struct EntryField2_021a3338 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_021a3338
ARM void SyncVec3ForFlaggedCombatants_021a3338(void*) {
    GameState* battleStruct = GameState::GetInstance();
    struct PtrWithU16_021a3338* ptr = (struct PtrWithU16_021a3338*)func_02012fe4();
    unsigned short value = ptr->field0;
    struct Entry_02028bd0* entry = FindEntryByCurrentId02027cb0();
    if (entry == NULL) return;

    int i;
    for (i = 0; i < 0xc; i++) {
        int idx = ((struct EntryField2_021a3338*)entry)->field2;
        int base = idx * 0xc + 0x70;
        GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(i + base);
        if (combatant) {
            if (value == _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant)) {
                EventVec3 v = *(EventVec3*)((char*)combatant + 0x44);
                v.b = func_02018fbc((int)ptr, &v);
                _ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)&v);
            }
        }
    }
}
