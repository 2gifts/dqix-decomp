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
#if defined(jpn)
    char reserved18[0x2fc];
#else
    char reserved18[0x300];
#endif
};

struct CombatantId020288e0 {
#if defined(jpn)
    char reserved0[0x150];
#else
    char reserved0[0x15c];
#endif
    int field15c;
};

GameObject* GetCombatantWithFlag0x200_0200fee0(GameState* battleStruct, int combatantId);
int GetField0x158_02053ed0(void* obj);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
void InitializeSubObjectsAndFields020289c4(BigRecord020289c4*);

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
            GameObject* combatant = GetCombatantWithFlag0x200_0200fee0(state, j);
            if (combatant == NULL) continue;
            if (!GetField0x158_02053ed0(combatant)) {
                if (((Object3D*)combatant)->GetField06() != key) continue;
            } else {
                if (key != ((CombatantId020288e0*)combatant)->field15c) continue;
            }
            found = true;
            break;
        }
        if (found) continue;
        for (int k = 0; k < 12; ++k) {
            ClearCombatantSlot_0200fd48(state, k + (i * 12 + 0x70));
        }
        InitializeSubObjectsAndFields020289c4(record);
    }
}
