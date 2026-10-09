#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S_10088;
struct OutStruct0215ccbc;

struct ActionNode0215af54 {
    unsigned short actionId;
    char pad2[0xb - 0x2];
    unsigned char flags;
    char padC[0x28 - 0xc];
};

struct ActorNode0215af54 {
    char pad0[0x1c];
    short field1C;
    char pad1E[0x20 - 0x1e];
    short combatantId;
    unsigned short hp;
    unsigned short mp;
    char pad26[0x30 - 0x26];
    int field30;
};

struct TargetNode0215af54 {
    char pad0[0xe];
    short combatantId;
    char pad10[0x17 - 0x10];
    unsigned char field17;
    char pad18[0x24 - 0x18];
};

struct EffectNode0215af54 {
    char pad0[0x20];
    int field20;
};

struct Battle0215af54 {
    char pad0[0x6d30];
    struct ActionNode0215af54 actions[16];
    struct ActorNode0215af54 actors[16];
    struct TargetNode0215af54 targets[16];
    struct EffectNode0215af54 effects[16];
    char pad7770[0x8e10 - 0x7770];
    unsigned char actionCount;
    unsigned char actorCount;
    unsigned char targetCount;
    unsigned char effectCount;
};

int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
void InitStruct02160030(void* obj);
void ResetStruct02157cdc(void* obj);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
void PopulateEntry_0215ccbc(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, int wordC, int wordD, unsigned char byteE);
void AppendToChainAndIncCount0215ffc4(void* obj, void* node, int idx);
struct Obj02160068;
struct Node02160068;
struct Obj021600cc;
struct Node021600cc;
void AppendNode02160068(struct Obj02160068* obj, struct Node02160068* newNode);
void AppendNode021600cc(struct Obj021600cc* obj, struct Node021600cc* newNode);

static inline int IsPartyIndex(int index) {
    return index >= 0 && index <= 3;
}

static inline short CurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short CurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// USA: func_ov000_0215af54
extern "C" ARM void func_ov000_0215af54(struct Battle0215af54* battle, int index, int mode) {
    struct ActionNode0215af54* action;
    struct ActorNode0215af54* actor;
    struct TargetNode0215af54* target;
    struct EffectNode0215af54* effect;
    if (battle->actionCount >= 16 || battle->actorCount >= 16 || battle->targetCount >= 16 || battle->effectCount >= 16) {
        return;
    }
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(index);
    if (c == NULL) {
        return;
    }
    if (IsFlag10088Set((struct S_10088*)c)) {
        return;
    }
    if (IsFlag0x18Bit0x2000Set(c)) {
        return;
    }

    action = &battle->actions[battle->actionCount];
    InitStruct02160030(action);
    actor = &battle->actors[battle->actorCount];
    memset(actor, 0, 0x30);
    actor->field1C = -1;
    actor->field30 = 0;
    target = &battle->targets[battle->targetCount];
    ResetStruct02157cdc(target);
    effect = &battle->effects[battle->effectCount];
    memset(effect, 0, 0x20);
    effect->field20 = 0;

    if (mode == 0) {
        if (IsPartyIndex(index)) {
            action->actionId = 0x39c;
        } else {
            action->actionId = 0x39d;
        }
        AddEntryAndIncrementCount0215a88c(battle, effect, 0x35);
    } else {
        action->actionId = 0x39a;
        AddEntryAndIncrementCount0215a88c(battle, effect, 0x213);
    }
    action->flags |= 4;

    actor->combatantId = index;
    actor->hp = c->currentStats_->primaryStats.currHP;
    actor->mp = c->currentStats_->primaryStats.currMP;
    PopulateEntry_0215ccbc((int)battle, (struct OutStruct0215ccbc*)effect, c, 0, CurrHP(c), CurrMP(c), 0, 0, 0);
    target->combatantId = index;
    target->field17 = 1;
    AppendToChainAndIncCount0215ffc4(target, effect, 0);
    AppendNode02160068((struct Obj02160068*)action, (struct Node02160068*)actor);
    AppendNode021600cc((struct Obj021600cc*)action, (struct Node021600cc*)target);

    battle->actionCount++;
    battle->actorCount++;
    battle->targetCount++;
    battle->effectCount++;
}
