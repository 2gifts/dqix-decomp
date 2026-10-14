#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);

// USA: func_020dc4d0
ARM void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount) {
    GameState* battle = GameState::GetInstance();
    signed char buf[8];
    signed char n = CopyOutRegion0x571d_020114ec((char*)battle, buf);
    signed char count = 0;
    for (signed char i = 0; i < n; i++) {
        if (battle->GetPartyMemberByIndex(buf[i]) != NULL) {
            out[count] = buf[i];
            count = count + 1;
        }
    }
    *outCount = count;
}
