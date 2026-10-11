#include <globaldefs.h>
#if defined(jpn)
enum { kBaseOffset = 0xca };
enum { kFlagsOffset = 0x900 };
#else
enum { kBaseOffset = 0x96 };
enum { kFlagsOffset = 0xa00 };
#endif

#include "GameState/GameState.h"


// USA: func_02026b7c
ARM void MarkActiveCombatantSlots02026b7c(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    int i;
    obj += kBaseOffset;
    for (i = 0; i < 4; i++) {
        if (bs->GetGameObjectByIndex(i)) {
            obj[kFlagsOffset] |= (1 << i);
        }
    }
}
