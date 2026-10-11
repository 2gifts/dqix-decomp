#include <globaldefs.h>

#if defined(jpn)
enum { stateFieldOffset = 0x1b8 };
#else
enum { stateFieldOffset = 0x1c4 };
#endif
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);

// USA: func_020dcc20
ARM int CountFlag0x800MatchesEqualsTarget020dcc20(int targetCount, int flag) {
    GameState* battle = GameState::GetInstance();
    unsigned char count = 0;
    for (signed char i = 0; i < 4; i++) {
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (c != NULL) {
            if (!(flag != 0 && *(int*)((char*)c + stateFieldOffset) != 0)) {
                if (GetFieldAt0x150((unsigned char*)c) != 0) {
                    count = count + 1;
                }
            }
        }
    }
    return count == targetCount;
}
