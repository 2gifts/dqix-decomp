#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct TargetObj02088418;

struct ActionState0215704c {
    char pad0[0x22];
    unsigned short field22_0 : 12;
    unsigned short targetMode : 2;
    char pad24[0x28 - 0x24];
    short targetId;
    char pad2A[0x4a - 0x2a];
    unsigned char field4A;
    char pad4B[0x4e - 0x4b];
    unsigned char field4E;
    char pad4F[0x53 - 0x4f];
    unsigned char rate;
};

struct Combatant0215704c {
    char pad0[0x138];
    struct ActionState0215704c* action;
};

struct TargetIds0215704c {
    short ids[4];
};

struct TargetChoice0215704c {
    unsigned char weight;
    unsigned char enabled;
    unsigned char mode;
    unsigned char valid;
};

struct TargetChoices0215704c {
    struct TargetChoice0215704c choices[3];
};

extern struct TargetIds0215704c data_ov000_02182a64;
extern struct TargetChoices0215704c data_ov000_02182aa0;

extern "C" int func_ov000_0215e9fc(struct Random* battle, short* buf, int max, int start);
extern "C" int func_ov000_02155f9c(struct Random* battle, int combatantId, int checkSubFlag);
extern "C" float func_ov000_0215641c(struct Random* battle, int id);
int NextRandomMax(struct Random* random, int maximum);
int IsValidTargetCombatant(struct TargetObj02088418* c, int index, int actionId);
extern "C" int _Z32CheckField0x14FlagsClear0208824cPh(unsigned char* obj);
int CheckField0x14FlagsClear(unsigned char* obj);

static inline int IsPartyIndex(int index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0215704c
extern "C" ARM int func_ov000_0215704c(struct Random* battle, int index) {
    int count;
    GameState* gs;
    if (IsPartyIndex(index)) {
        return 0;
    }
    struct TargetIds0215704c targets = data_ov000_02182a64;
    count = func_ov000_0215e9fc(battle, targets.ids, 4, 1);
    struct Combatant0215704c* self = (struct Combatant0215704c*)GameState::GetInstance()->GetCombatantByIndex(index);
    if (self == NULL) {
        return 0;
    }
    if (func_ov000_02155f9c(battle, index, 0)) {
        return 0;
    }
    if (self->action->rate == 0) {
        return 0;
    }
    gs = GameState::GetInstance();
    for (int i = 0; i < count; i++) {
        if (GetCombatantWithFlag0x100(gs, targets.ids[i]) == NULL) {
            continue;
        }
        float chance = func_ov000_0215641c(battle, targets.ids[i]);
        chance *= self->action->rate / 100.0f;
        if (chance > NextRandomMax(battle, 100)) {
            struct TargetChoices0215704c table = data_ov000_02182aa0;
            table.choices[0].valid = IsValidTargetCombatant((struct TargetObj02088418*)self->action, 10, 0);
            table.choices[1].enabled = self->action->field4E;
            table.choices[1].valid = _Z32CheckField0x14FlagsClear0208824cPh((unsigned char*)self->action);
            table.choices[2].enabled = self->action->field4A;
            table.choices[2].valid = CheckField0x14FlagsClear((unsigned char*)self->action);
            int roll = NextRandomMax(battle, 100);
            for (int j = 0; j < 3; j++) {
                if (table.choices[j].weight > roll) {
                    if (table.choices[j].enabled && table.choices[j].valid) {
                        self->action->targetMode = table.choices[j].mode;
                        self->action->targetId = targets.ids[i];
                        return 1;
                    }
                }
                roll -= table.choices[j].weight;
            }
        }
    }
    return 0;
}
