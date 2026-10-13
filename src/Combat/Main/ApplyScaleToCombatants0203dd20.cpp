#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct Obj02040c2c;
extern "C" void func_02040c2c(Obj02040c2c* entry, void* context, int elapsedTicks, int movementTicks);

struct Entry0203dd20 {
    unsigned int flags;
};

struct Obj0203dd20 {
    char pad0[0xc];
    struct Entry0203dd20* entries[0x20];
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
        struct Entry0203dd20* entry = obj->entries[i];
        if (entry != NULL && !(entry->flags & 0x8000)) {
            func_02040c2c(reinterpret_cast<Obj02040c2c*>(entry), context, b, c);
        }
    }
}
