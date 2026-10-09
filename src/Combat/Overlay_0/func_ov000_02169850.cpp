#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionSummary { unsigned short action; unsigned char target; unsigned char group; unsigned char flags; };
struct S02053dc0;
ActionSummary* GetField0x19cOrNull(S02053dc0*);
struct PartyAction {
    char pad0[0x1d];
    unsigned char group;
    char pad1e[0x10];
    signed char target;
    char pad2f[0x1d];
    int owner;
    char pad50[0x3f8];
};
struct CombatActions {
    char pad0[0x2a0];
    unsigned char* state;
    char pad2a4[0x34bc];
    char targeting[0x958];
    PartyAction actions[4];
    char pad51d8[0x778];
    unsigned char mode;
};
struct SelectedAction {
    unsigned char field0;
    unsigned char type;
    char pad2[4];
    short key;
    unsigned short value;
};
struct ActionEntry { char pad0[0x16]; unsigned short value; };
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void func_ov000_02162c14(CombatActions*, int, SelectedAction*);
extern "C" ActionEntry* func_ov000_02171d90(PartyAction*, int);
int GetClampedArrayField0xd1c(char*, int);
int GetClampedArrayField0xd3c(char*, int);
void SetSubstructByte0x4c(unsigned char*, unsigned char);
static inline int IsPartyMember(int index) { return index >= 0 && index <= 3; }

// USA: func_ov000_02169850
extern "C" ARM void func_ov000_02169850(CombatActions* self) {
    GameState* game = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (!TestBitAt0x34(self->state, (unsigned char)i)) continue;
        GameObject* combatant = GetCombatantWithFlag0x100(game, i);
        if (!combatant) continue;
        ActionSummary* summary = GetField0x19cOrNull((S02053dc0*)combatant);
        if (!summary) continue;
        int value;
        PartyAction* action;
        if (IsPartyMember(i)) {
            for (int j = 0; j < 4; ++j) {
                if (i == self->actions[j].owner) {
                    action = &self->actions[j];
                    goto found;
                }
            }
        }
        action = 0;
    found:
        if (!action) continue;
        SelectedAction selected;
        func_ov000_02162c14(self, i, &selected);
        value = 1;
        if (selected.type == 0) {}
        else if (selected.type == 1) value = selected.value;
        else if (selected.type == 2) value = 3;
        else if (selected.type == 3) value = selected.value;
        else if (selected.type == 4) {
            ActionEntry* entry = func_ov000_02171d90(action, selected.key);
            if (entry) value = entry->value;
        } else if (selected.type == 5) value = selected.value;
        else if (selected.type == 6) {
            if (self->mode == 3 || self->mode == 4) {
                value = 0;
                summary->flags |= 1;
            } else value = 0x1f6;
        }
        summary->action = value;
        int target = action->target;
        unsigned char group = action->group;
        if (IsPartyMember(target)) {
            summary->group = 0;
            summary->target = target;
        } else if (group >= 8) {
            summary->group = 0;
            summary->target = 0;
        } else {
            summary->group = GetClampedArrayField0xd1c(self->targeting, group);
            summary->target = GetClampedArrayField0xd3c(self->targeting, group);
        }
        SetSubstructByte0x4c((unsigned char*)combatant, summary->target);
    }
}
