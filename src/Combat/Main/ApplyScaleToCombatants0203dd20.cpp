#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Combat/CombatantMotion.h"

struct Obj0203dd20 {
    char pad0[0xc];
    Obj02040c2c* entries[0x20];
};

// USA: func_0203dd20
ARM void ApplyScaleToCombatants0203dd20(struct Obj0203dd20* obj) {
    GameState* battleStruct;
    void* context;
    int b;
    unsigned int c;
    int i;
    battleStruct = GameState::GetInstance();
    context = GetField0x3b0Value(battleStruct);
    b = battleStruct->GetEffectiveDeltaTime();
    c = battleStruct->GetTickCount();
    for (i = 0; i < 0x20; i++) {
        Obj02040c2c* entry = obj->entries[i];
        if (entry != NULL && !(entry->flags & 0x8000)) {
            func_02040c2c(entry, context, b, c);
        }
    }
}
