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

struct CombatantId020288e0 {
    char reserved0[0x15c];
    int field15c;
};

GameObject* GetCombatantWithFlag0x200(GameState* battleStruct, int combatantId);
int GetField0x158(void* obj);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void* obj);
void ClearCombatantSlot(GameState* battleStruct, int id);
extern "C" void _Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4(BigRecord020289c4*);

// USA: func_020288e0
extern "C" ARM void func_020288e0(BigRecord020289c4* records)
{
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        BigRecord020289c4* record = &records[i];
        int key = records[i].id;
        if (!record->flagB) continue;
        bool found = false;
        for (int j = 0; j < 4; ++j) {
            GameObject* combatant = GetCombatantWithFlag0x200(state, j);
            if (combatant == NULL) continue;
            if (!GetField0x158(combatant)) {
                if (_ZNK8Object3D10GetField06Ev(combatant) != key) continue;
            } else {
                if (key != ((CombatantId020288e0*)combatant)->field15c) continue;
            }
            found = true;
            break;
        }
        if (found) continue;
        for (int k = 0; k < 12; ++k) {
            ClearCombatantSlot(state, k + (i * 12 + 0x70));
        }
        _Z37InitializeSubObjectsAndFields020289c4P17BigRecord020289c4(record);
    }
}
