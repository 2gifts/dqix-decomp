#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct List02160094 {
    char pad0[8];
    unsigned char entryCount;
    unsigned char targetCount;
    char pada;
    unsigned char flags;
    char padc[0x28 - 0xc];
};

struct List021600f8;
struct S_10088;

struct Battle {
    char pad0[0x6d30];
    List02160094 actions[1];
    char pad6d58[0x8e09 - 0x6d58];
    unsigned char actionsDone;
    char pad8e0a[0x8e10 - 0x8e0a];
    unsigned char actionCount;
    char pad8e11[0x8e24 - 0x8e11];
    int workCount;
};

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
void* GetWorkArrayEntry0215e9d8(void* work);
void InitStruct02160030(void* obj);
ActionEntry* GetNodeAtIndex02160094(List02160094* list, int index);
void* GetNodeAtIndex021600f8(List021600f8* list, int index);
int IsFlag10088Set(S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);

// USA: func_ov000_0215b198
extern "C" ARM void func_ov000_0215b198(Battle* battle) {
    int i;
    for (i = battle->actionsDone; i < battle->actionCount; i++) {
        void* work = GetWorkArrayEntry0215e9d8(battle);
        if (work == 0) {
            return;
        }
        InitStruct02160030(work);
        List02160094* action = &battle->actions[i];
        ActionEntry* entry = GetNodeAtIndex02160094(action, 0);
        if (entry == 0) {
            continue;
        }
        if (GetNodeAtIndex021600f8((List021600f8*)action, 0) == 0) {
            continue;
        }
        int id = entry->combatantId;
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(id);
        if (c == 0) {
            continue;
        }
        action->flags |= 4;
        if (IsFlag10088Set((S_10088*)c)) {
            continue;
        }
        if (IsFlag0x18Bit0x2000Set(c)) {
            continue;
        }
        memcpy(work, action, sizeof(List02160094));
        battle->workCount++;
    }
    battle->actionsDone = battle->actionCount;
}
