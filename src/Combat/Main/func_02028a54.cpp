#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct BigRecord020289c4 {
    unsigned short id;
    unsigned short flagsX : 2;
    unsigned short flagB : 1;
    unsigned short otherFlags : 13;
    char reserved4[0xc];
    SafeAllocator* allocator;
    SafeAllocator* secondAllocator;
    char reserved18[0x300];
};

struct Combatant02028a54 {
    GameObject object;
    char reserved13c[0x5c];
};

extern "C" void _Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4(BigRecord020289c4*);
void ClearCombatantSlot(GameState*, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
extern "C" void func_0202ae18();
extern "C" void func_02012fe4();
extern "C" void func_02076a8c(GameObject*);

// USA: func_02028a54
extern "C" ARM int func_02028a54(BigRecord020289c4* records, int id)
{
    GameState* state = GameState::GetInstance();
    func_0202ae18();
    func_ov017_0218b5b0();
    func_02012fe4();
    state->GetGrottoStruct();
    for (int i = 0; i < 4; ++i) {
        if (id == records[i].id) return 0;
    }
    int index = -1;
    for (int i = 0; i < 4; ++i) {
        if (!records[i].flagB) {
            index = i;
            break;
        }
    }
    if (index < 0) return 0;
    BigRecord020289c4* record = &records[index];
    _Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4(record);
    record->flagB = 1;
    record->id = id;
    record->allocator->Reset();
    record->secondAllocator->Reset();
    Combatant02028a54* objects = (Combatant02028a54*)record->allocator->Allocate(0x1320);
    int i = 0;
    if (!objects) {
        int firstSlot = index * 12 + 0x70;
        for (; i < 12; ++i) ClearCombatantSlot(state, i + firstSlot);
        return 0;
    }
    int firstSlot = index * 12;
    firstSlot += 0x70;
    for (; i < 12; ++i) {
        func_02076a8c(&objects[i].object);
        objects[i].object.obj3D_.MakeHidden();
        RegisterCombatantSlot(state, i + firstSlot, &objects[i].object);
    }
    return 1;
}
