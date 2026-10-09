#include <globaldefs.h>
#include "GameState/GameState.h"

struct RemapFlagOwner;

struct CombatantInfo {
    char pad0[0x10];
    unsigned int pad10_0 : 27;
    unsigned int hidden : 1;
    unsigned int pad10_28 : 4;
};

struct BattleCombatant {
    char pad0[0x148];
    struct CombatantInfo* info;
};

struct BattleWork {
    char pad0[0x29c];
    char* field_0x29c;
    unsigned char* field_0x2a0;
    char pad2A4[0xea4 - 0x2a4];
    struct RemapFlagOwner* remapFlags;
};

extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
struct BattleCombatant* GetCombatantWithFlag0x400(GameState* gameState, int combatantId);
int GetSubstructByte0x56(unsigned char* obj);
void SetRemappedBitAt0xa26(struct RemapFlagOwner* obj, int index);
void ClearFlagBit(unsigned char* base, int bit);
int ClassifyField0x81fe(char* base);
int TestBitAt0x34(unsigned char* obj, unsigned int index);

// USA: func_ov000_021626a0
extern "C" ARM void func_ov000_021626a0(BattleWork* work, int index, int show) {
    int ids[16];
    GameState* gs;
    char* field29c;
    int i;
    int j;
    int count;
    GameObject* obj;
    int visible;
    struct RemapFlagOwner* remap;
    void* slot;
    struct BattleCombatant* combatant;
    struct CombatantInfo* info;

    gs = GameState::GetInstance();
    field29c = work->field_0x29c;
    remap = work->remapFlags;
    slot = _Z18GetSlotPtr02160f20Pv(work);
    if (remap == NULL) {
        return;
    }
    count = _Z23DispatchByIndex021820bcPviii(work->field_0x29c, (int)slot, index, (int)ids);
    for (i = 0; i < count; i++) {
        obj = gs->GetGameObjectByIndex(ids[i]);
        if (obj == NULL) {
            continue;
        }
        visible = show;
        if (obj->obj3D_.unknown_0_ & 0x400) {
            combatant = GetCombatantWithFlag0x400(gs, ids[i]);
            if (combatant != NULL) {
                info = combatant->info;
                if (GetSubstructByte0x56((unsigned char*)combatant) == 0 && info->hidden) {
                    visible = 0;
                }
            }
        }
        if (visible) {
            obj->obj3D_.MakeVisible();
            SetRemappedBitAt0xa26(remap, ids[i]);
        } else {
            obj->obj3D_.MakeHidden();
            ClearFlagBit((unsigned char*)remap, ids[i]);
        }
    }
    if (ClassifyField0x81fe(field29c) == 0) {
        return;
    }
    for (j = 1; j < 4; j++) {
        obj = gs->GetGameObjectByIndex(j);
        if (obj == NULL) {
            continue;
        }
        if (TestBitAt0x34(work->field_0x2a0, (unsigned char)j)) {
            obj->obj3D_.MakeHidden();
            ClearFlagBit((unsigned char*)remap, j);
        }
    }
}
