#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov002_021549c8  (semantic: TryClearCombatantFlagBits_021549c8)
extern "C" ARM int func_ov002_021549c8(void* unused, int combatantId, int flagMask, unsigned char* outByte) {
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), combatantId);
    if (!combatant) {
        return 0;
    }
    int* field = *(int**)((char*)combatant + 0x130);
    int word = *field;
    if ((word & flagMask) == 0) goto notset;
    *field = (unsigned short)(word & ~flagMask);
    *outByte = 3;
    goto success;
notset:
    *outByte = 0;
    return 0;
success:
    return 1;
}
