#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct TargetEntry {
    char pad0[0xc];
    short combatantId;
};

struct List02160094 {
    char pad0[0x28];
};

struct List021600f8;
struct S_10088;

struct Combatant {
    char pad0[0x138];
    unsigned char* stats;
    char pad13c[0x181 - 0x13c];
    unsigned char field_0x181;
};

struct Battle {
    char pad0[0x6060];
    List02160094 actions[1];
    char pad6088[0x8e08 - 0x6088];
    unsigned char actionsDone;
    char pad8e09[0x8e0b - 0x8e09];
    unsigned char actionCount;
    char pad8e0c[0x8e24 - 0x8e0c];
    int workCount;
};

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* _Z25GetWorkArrayEntry0215e9d8Pv(void* work);
extern "C" void _Z18InitStruct02160030Pv(void* obj);
extern "C" ActionEntry* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094* list, int index);
extern "C" TargetEntry* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
int IsFlag10088Set(S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
void ClearFlag0x1000AndBytes7eA1(unsigned char* obj);

static inline GameObject* GetFlagged(int id) {
    GameState* gs = GameState::GetInstance();
    return GetCombatantWithFlag0x400(gs, id);
}

static inline GameObject* GetCombatant(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

// USA: func_ov000_0215ab88
extern "C" ARM void func_ov000_0215ab88(Battle* battle) {
    int i;
    void* work;
    List02160094* action;
    ActionEntry* entry;
    TargetEntry* target;
    GameObject* c;
    GameObject* t;
    for (i = battle->actionsDone; i < battle->actionCount; i++) {
        work = _Z25GetWorkArrayEntry0215e9d8Pv(battle);
        if (work == 0) {
            return;
        }
        _Z18InitStruct02160030Pv(work);
        action = &battle->actions[i];
        entry = _Z22GetNodeAtIndex02160094P12List02160094i(action, 0);
        if (entry == 0) {
            continue;
        }
        target = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)action, 0);
        if (target == 0) {
            continue;
        }
        c = GetFlagged(entry->combatantId);
        if (c == 0) {
            continue;
        }
        ((Combatant*)c)->field_0x181 = 0;
        if (IsFlag10088Set((S_10088*)c)) {
            continue;
        }
        if (IsFlag0x18Bit0x2000Set(c)) {
            continue;
        }
        t = GetCombatant(target->combatantId);
        if (t == 0 || IsFlag10088Set((S_10088*)t) || IsFlag0x18Bit0x2000Set(t)) {
            ClearFlag0x1000AndBytes7eA1(((Combatant*)c)->stats);
            continue;
        }
        memcpy(work, action, sizeof(List02160094));
        battle->workCount++;
    }
    battle->actionsDone = battle->actionCount;
}
