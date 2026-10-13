#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short slotGroup : 2;
};

struct SpawnParams {
    char pad_0[0x38];
    unsigned short field_38;
    unsigned int field_3c;
};

struct ShadowInfo {
    char pad_0[0x12];
    short scale;
};

struct FieldMonster : GameObject {
    char pad_13c[0x180 - 0x13c];
    ShadowInfo* shadowInfo_;
};

struct DistanceSlot {
    int distance;
    unsigned char selected;
    DistanceSlot() : distance(0x0270f000), selected(0) {}
};

Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);
extern "C" SpawnParams* func_02012fe4();
unsigned int GetBitsInField4(unsigned int*, unsigned int);
extern "C" int _Z37TickActorFlagStateAndDispatch02076becPhPv(unsigned char*, void*);
struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(BitField0203402c*);
extern "C" void _Z23SyncBattleState0208f87cPviii(const Vector3fix*, int, int, int, int);

// USA: func_ov017_021a1d98
extern "C" ARM void func_ov017_021a1d98(unsigned int* flags, int id) {
    GameState* state = GameState::GetInstance();
    Entry_02028bd0* entry = FindInlineEntryById(GetEntryTableBase(), id);
    if (!entry) return;
    SpawnParams* params = func_02012fe4();
    unsigned short field38 = params->field_38;
    unsigned int field3c = params->field_3c;
    int arg = 1;
    if (GetBitsInField4(flags, 0x1000)) arg = 0;
    int partyCount = 0;
    for (int i = 0; i < 4; i++) {
        GameObject* member = state->GetPartyMemberByIndex(i);
        if (member && id == member->obj3D_.GetField06()) partyCount++;
    }
    int remaining = 7 - partyCount;
    Vector3fix origin = state->GetUnknownGameObject()->obj3D_.position_;
    DistanceSlot slots[12];
    for (int j = 0; j < 12; j++) {
        FieldMonster* monster = (FieldMonster*)state->GetMaybeFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()) {
            Vector3fix position = monster->obj3D_.position_;
            slots[j].distance = Vector3fix_Distance(&origin, &position);
        }
    }
    int bestDistance, k, best;
    for (k = 0; k < remaining; k++) {
        best = -1;
        bestDistance = 0x0270f000;
        for (int j = 0; j < 12; j++) {
            if (!slots[j].selected && slots[j].distance <= bestDistance) {
                bestDistance = slots[j].distance;
                best = j;
            }
        }
        if (best != -1) slots[best].selected = 1;
    }
    for (int j = 0; j < 12; j++) {
        if (!slots[j].selected) continue;
        FieldMonster* monster = (FieldMonster*)state->GetMaybeFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()
            && _Z37TickActorFlagStateAndDispatch02076becPhPv((unsigned char*)monster, (void*)arg)
            && !CheckField0xc4Low15BitsNonZero((BitField0203402c*)monster)) {
            int alpha = monster->obj3D_.GetCombinedAlpha();
            int value = (int)((float)field3c / 31.0f * (float)alpha);
            int shadowScale = monster->shadowInfo_ ? monster->shadowInfo_->scale : 0x1000;
            fix32_t size = FIX32_MULTIPLY(shadowScale, monster->obj3D_.GetScale().x * 15);
            const Vector3fix& shadow = monster->obj3D_.MaybeGetShadowSource();
            _Z23SyncBattleState0208f87cPviii(&shadow, field38, size, value, 8);
        }
    }
}
