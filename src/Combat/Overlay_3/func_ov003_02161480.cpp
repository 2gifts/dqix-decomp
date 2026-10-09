#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3acValue(GameState* battleStruct);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char* obj);

struct PartyRoster02161480 {
    char pad0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

// USA: func_ov003_02161480
extern "C" ARM void func_ov003_02161480(void) {
    GameState* bs = GameState::GetInstance();
    struct PartyRoster02161480* roster = (struct PartyRoster02161480*)GetPtrField0x2a04(bs);
    unsigned char activeId = GetField0x3acValue(bs);
    for (unsigned char i = 0; i < roster->memberCount; i++) {
        if (activeId != roster->memberIds[i]) {
            GameObject* c = bs->GetPartyMemberByIndex(roster->memberIds[i]);
            if (c != NULL) {
                _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)c);
            }
        }
    }
}
