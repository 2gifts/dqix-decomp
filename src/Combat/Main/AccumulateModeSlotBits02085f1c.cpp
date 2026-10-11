#include <globaldefs.h>

#if defined(jpn)
enum { kOffset8f2 = 0x85a, kOffset8f3 = 0x85b };
#else
enum { kOffset8f2 = 0x8f2, kOffset8f3 = 0x8f3 };
#endif

#include "GameState/GameState.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085f1c
ARM int AccumulateModeSlotBits02085f1c(unsigned char* actor, int mode) {
    GameState* bs;
    int total;
    if (mode < 0) {
        short v = *(short*)(actor + 0x2ac);
        if (v > 0) {
            int x = *(int*)(actor + 0x29c);
            mode = (unsigned int)(x << 23) >> 27;
        } else {
            mode = 0x21;
        }
    }
    bs = GameState::GetInstance();
    total = 0;
    if (mode == 3) {
        if (actor[kOffset8f2] & 0x80) {
            total += GetSlotBits0201137c((char*)bs, 0x37);
        }
        if (actor[kOffset8f3] & 0x8) {
            total += GetSlotBits0201137c((char*)bs, 0x3b);
        }
        if (actor[kOffset8f3] & 0x40) {
            total += GetSlotBits0201137c((char*)bs, 0x3e);
        }
    }
    return total;
}
