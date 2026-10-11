#include <globaldefs.h>

#if defined(jpn)
enum { dispatchFieldOffset = 0x8b8 };
#else
enum { dispatchFieldOffset = 0x950 };
#endif
int MatchesAnyTableEntry020dd19c(unsigned int, int);
#include "GameState/GameState.h"

void* GetFieldAt0x150(unsigned char*);

// USA: func_020dd154
ARM int DispatchByField0x950Byte(int combatantId, int b) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == NULL) {
        return 0;
    }
    void* p = GetFieldAt0x150((unsigned char*)combatant);
    if (p == NULL) {
        return 0;
    }
    int val = *(int*)((char*)p + dispatchFieldOffset);
    return MatchesAnyTableEntry020dd19c((unsigned int)(val & 0xff), (int)(b));
}
