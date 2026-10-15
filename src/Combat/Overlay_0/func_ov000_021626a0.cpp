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
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    char* field_0x29c;
    unsigned char* field_0x2a0;
    char pad2A4[0xea4 - 0x2a4];
    struct RemapFlagOwner* remapFlags;
};

void* GetSlotPtr02160f20(void* obj);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct BattleCombatant* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
int GetSubstructByte0x56_02049ee8(unsigned char* obj);
void SetRemappedBitAt0xa26_020d76b8(struct RemapFlagOwner* obj, int index);
void ClearFlagBit_020d76d8(unsigned char* base, int bit);
int ClassifyField0x81fe_ov000_0215fc60(char* base);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);

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
    slot = GetSlotPtr02160f20(work);
    if (remap == NULL) {
        return;
    }
    count = DispatchByIndex021820bc(work->field_0x29c, (int)slot, index, (int)ids);
    for (i = 0; i < count; i++) {
        obj = gs->GetGameObjectByIndex(ids[i]);
        if (obj == NULL) {
            continue;
        }
        visible = show;
        if (obj->obj3D_.unknown_0_ & 0x400) {
            combatant = GetCombatantWithFlag0x400_0200fea4(gs, ids[i]);
            if (combatant != NULL) {
                info = combatant->info;
                if (GetSubstructByte0x56_02049ee8((unsigned char*)combatant) == 0 && info->hidden) {
                    visible = 0;
                }
            }
        }
        if (visible) {
            obj->obj3D_.MakeVisible();
            SetRemappedBitAt0xa26_020d76b8(remap, ids[i]);
        } else {
            obj->obj3D_.MakeHidden();
            ClearFlagBit_020d76d8((unsigned char*)remap, ids[i]);
        }
    }
    if (ClassifyField0x81fe_ov000_0215fc60(field29c) == 0) {
        return;
    }
    for (j = 1; j < 4; j++) {
        obj = gs->GetGameObjectByIndex(j);
        if (obj == NULL) {
            continue;
        }
        if (TestBitAt0x34_020a35e0(work->field_0x2a0, j)) {
            obj->obj3D_.MakeHidden();
            ClearFlagBit_020d76d8((unsigned char*)remap, j);
        }
    }
}
