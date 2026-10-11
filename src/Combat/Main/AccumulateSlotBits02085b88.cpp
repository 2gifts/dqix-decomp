#include <globaldefs.h>
#if defined(jpn)
enum { kFlagOffset = 0x858 };
#else
enum { kFlagOffset = 0x8f0 };
#endif

#include "GameState/GameState.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085b88
ARM int AccumulateSlotBits02085b88(unsigned char* actor) {
    GameState* bs;
    int total;
    if (*(short*)(actor + 0x2cc) <= 0) {
        return 0;
    }
    bs = GameState::GetInstance();
    total = 0;
    if (actor[kFlagOffset] & 4) {
        total += GetSlotBits0201137c((char*)bs, 0x22);
    }
    if (actor[kFlagOffset] & 0x10) {
        total += GetSlotBits0201137c((char*)bs, 0x24);
    }
    if (actor[kFlagOffset] & 0x40) {
        total += GetSlotBits0201137c((char*)bs, 0x26);
    }
    return total;
}
