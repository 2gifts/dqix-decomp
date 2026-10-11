#include <globaldefs.h>
#if defined(jpn)
enum { kRegion150 = 0x144 };
enum { kRegion950 = 0x8b8 };
#else
enum { kRegion150 = 0x150 };
enum { kRegion950 = 0x950 };
#endif
#include "GameState/GameState.h"

void* GetArrayEntryByIndex_02156034(void* obj);

// JPN: func_ov003_0215759c
// USA: func_ov003_02155f40
ARM int MatchesArrayEntry_02155f40(void* obj, int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetPartyMemberByIndex(combatantId);
    int result;
    if (combatant != NULL) {
        void* inner = *(void**)((char*)combatant + kRegion150);
        int val = *(int*)((char*)inner + kRegion950);
        result = (val == (int)GetArrayEntryByIndex_02156034(obj)) ? 1 : 0;
    } else {
        result = 0;
    }
    return result;
}
