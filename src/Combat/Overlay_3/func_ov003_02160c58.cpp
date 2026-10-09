#include <globaldefs.h>
#include "GameState/GameState.h"

struct PartyData02160c58 {
    char pad0[0xf70];
    unsigned int extraSlots;
    char pad_f74[0x2c8c - 0xf74];
    unsigned char memberCount;
};

// USA: func_ov003_02160c58
extern "C" ARM void func_ov003_02160c58(int id, short* outTotal, short* outRemaining) {
    short total = 12;
    unsigned char used = ((PartyData02160c58*)GetPtrField0x2a04(GameState::GetInstance()))->memberCount;
    total -= 4;
    PartyData02160c58* data = (PartyData02160c58*)GetPtrField0x2a04(GameState::GetInstance());
    if (data->extraSlots > 4) {
        data->extraSlots = 4;
    }
    total += data->extraSlots;
    if (total > 12) {
        total = 12;
    }
    *outTotal = total;
    *outRemaining = total - used;
}
