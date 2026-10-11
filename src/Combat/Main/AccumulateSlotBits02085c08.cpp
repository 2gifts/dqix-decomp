#include <globaldefs.h>
#if defined(jpn)
enum { kFlagAOffset = 0x865 };
enum { kFlagBOffset = 0x85d };
#else
enum { kFlagAOffset = 0x8fd };
enum { kFlagBOffset = 0x8f5 };
#endif

#include "GameState/GameState.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085c08
ARM int AccumulateSlotBits02085c08(unsigned char* actor) {
    short v = *(short*)(actor + 0x2ac);
    int sel = 0x21;
    GameState* bs;
    int total;
    if (v > 0) {
        int w = *(int*)(actor + 0x29c);
        sel = (unsigned int)(w << 23) >> 27;
    }
    bs = GameState::GetInstance();
    total = 0;
    if (sel != 5) {
        if (sel == 0x21) {
            if (actor[kFlagAOffset] & 1) {
                total += GetSlotBits0201137c((char*)bs, 0x88);
            }
        }
    } else {
        if (actor[kFlagBOffset] & 1) {
            total += GetSlotBits0201137c((char*)bs, 0x48);
        }
    }
    return total;
}
