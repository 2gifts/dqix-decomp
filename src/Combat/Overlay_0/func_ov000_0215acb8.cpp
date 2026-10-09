#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);

struct ActionNode0215acb8 {
    unsigned short action;
    char pad2[0x28 - 0x2];
};

struct ActionEntry0215acb8 {
    char pad0[0x1c];
    short field1c;
    short pad1e;
    unsigned short combatantId;
    unsigned short currHP;
    unsigned short currMP;
    char pad26[0x30 - 0x26];
    int field30;
};

struct TargetNode0215acb8 {
    char pad0[0xe];
    short combatantId;
    char pad10[0x17 - 0x10];
    unsigned char active;
    char pad18[0x24 - 0x18];
};

struct OutStruct0215ccbc {
    char pad0[0x20];
    int field20;
};

struct Battle0215acb8 {
    char pad0[0x7770];
    struct ActionNode0215acb8 actions[0x10];
    struct ActionEntry0215acb8 entries[0x10];
    struct TargetNode0215acb8 targets[0x10];
    struct OutStruct0215ccbc outs[0x10];
    char pad81b0[0x8e0f - 0x81b0];
    unsigned char actionCount;
};

void InitStruct02160030(void* obj);
void ResetStruct02157cdc(void* obj);
void PopulateEntry_0215ccbc(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, int wordC, int wordD, unsigned char byteE);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
void AppendToChainAndIncCount0215ffc4(void* obj, void* node, int idx);

struct Obj02160068;
struct Node02160068;
void AppendNode02160068(struct Obj02160068* obj, struct Node02160068* newNode);
struct Obj021600cc;
struct Node021600cc;
void AppendNode021600cc(struct Obj021600cc* obj, struct Node021600cc* newNode);

// USA: func_ov000_0215acb8
extern "C" ARM void func_ov000_0215acb8(struct Battle0215acb8* battle, int combatantId, short amount, short valB) {
    if (battle->actionCount >= 0x10) {
        return;
    }
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (c == NULL) {
        return;
    }
    if (IsFlag10088Set((struct S_10088*)c)) {
        return;
    }
    if (IsFlag0x18Bit0x2000Set(c)) {
        return;
    }
    struct ActionNode0215acb8* action = &battle->actions[battle->actionCount];
    InitStruct02160030(action);
    struct ActionEntry0215acb8* entry = &battle->entries[battle->actionCount];
    memset(entry, 0, 0x30);
    entry->field1c = -1;
    entry->field30 = 0;
    struct TargetNode0215acb8* target = &battle->targets[battle->actionCount];
    ResetStruct02157cdc(target);
    struct OutStruct0215ccbc* out = &battle->outs[battle->actionCount];
    memset(out, 0, 0x20);
    out->field20 = 0;
    action->action = 0x3af;
    entry->combatantId = combatantId;
    entry->currHP = c->currentStats_->primaryStats.currHP;
    entry->currMP = c->currentStats_->primaryStats.currMP;
    PopulateEntry_0215ccbc((int)battle, out, c, -amount, c->currentStats_->primaryStats.currHP, valB, 0, 8, 0);
    AddEntryAndIncrementCount0215a88c(battle, out, 0x243);
    target->combatantId = combatantId;
    target->active = 1;
    AppendToChainAndIncCount0215ffc4(target, out, 0);
    AppendNode02160068((struct Obj02160068*)action, (struct Node02160068*)entry);
    AppendNode021600cc((struct Obj021600cc*)action, (struct Node021600cc*)target);
    battle->actionCount++;
}
