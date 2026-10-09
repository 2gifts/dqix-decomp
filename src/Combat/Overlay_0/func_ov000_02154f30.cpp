#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
GameObject* GetCombatantWithFlag0x400(GameState* gameState, int combatantId);

struct BaseStats02154f30 {
    char pad0[0x3c];
    unsigned int skip0 : 30;
    unsigned int flag30 : 1;
    unsigned int skip31 : 1;
};

struct Stats02154f30 {
    char pad0[0x2e];
    short targetId;
    char pad30[0x32 - 0x30];
    short preferredId;
    short secondaryId;
};

struct Ai02154f30 {
    char pad0[0x10];
    unsigned int skip0 : 26;
    unsigned int weighted : 1;
    unsigned int skip27 : 5;
};

struct Combatant02154f30 {
    char pad0[0x134];
    struct BaseStats02154f30* baseStats;
    struct Stats02154f30* stats;
    char pad13c[0x148 - 0x13c];
    struct Ai02154f30* ai;
};

struct Weights02154f30 {
    int v[4];
};

struct Ids02154f30 {
    short v[8];
};

int IsFlag0x18Bit0x1000Set(GameObject* combatant);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
int IsFlag0x14Bit0x8000000Set(GameObject* combatant);

extern struct Weights02154f30 data_ov000_02182ca4;
extern struct Ids02154f30 data_ov000_02182c94;

// USA: func_ov000_02154f30
extern "C" ARM short func_ov000_02154f30(struct Random* rng, int id, int count, short* ids) {
    struct Combatant02154f30* self = (struct Combatant02154f30*)GetCombatantWithFlag0x400(GameState::GetInstance(), id);
    struct Ai02154f30* ai = self->ai;
    struct Weights02154f30 weights = data_ov000_02182ca4;
    int total = 0;
    if (IsFlag0x18Bit0x1000Set((GameObject*)self)) {
        short targetId = self->stats->targetId;
        GameState* gs = GameState::GetInstance();
        GameObject* target = gs->GetCombatantByIndex(targetId);
        if (target != NULL && !IsFlag10088Set((struct S_10088*)target) && !IsFlag0x18Bit0x2000Set(target)) {
            return self->stats->targetId;
        }
    }
    struct Ids02154f30 list = data_ov000_02182c94;
    unsigned char n = 0;
    for (int i = 0; i < count; i++) {
        short cid = ids[i];
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(cid);
        if (c == NULL || IsFlag10088Set((struct S_10088*)c) || IsFlag0x18Bit0x2000Set(c)) {
            continue;
        }
        weights.v[n] = (unsigned short)((struct Combatant02154f30*)c)->baseStats->flag30 == 0 ? 2 : 1;
        if (ai->weighted == 1) {
            struct Stats02154f30* stats = self->stats;
            short cur = ids[i];
            if (cur == stats->preferredId) {
                weights.v[n] += 2;
            }
            if (cur == stats->secondaryId) {
                weights.v[n] += 1;
            }
        }
        total += weights.v[n];
        list.v[n] = ids[i];
        if (IsFlag0x14Bit0x8000000Set(c)) {
            weights.v[n] >>= 1;
        }
        n++;
    }
    if (n == 0) {
        return -1;
    }
    int r = NextRandomMax(rng, total) + 1;
    for (int j = 0; j < n; j++) {
        if (weights.v[j] >= r) {
            return list.v[j];
        }
        r -= weights.v[j];
    }
    return list.v[NextRandomMax(rng, n)];
}
