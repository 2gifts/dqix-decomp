#include <globaldefs.h>
#if defined(jpn)
enum { kFlagsOffset = 0x85b };
#else
enum { kFlagsOffset = 0x8f3 };
#endif

#include "GameState/GameState.h"

int GetSlotBits0201137c(char* base, int id);

struct Actor02085c80 {
    char pad0[kFlagsOffset];
    unsigned char field8f3;
};

// USA: func_02085c80
ARM int AccumulateSlotBits02085c80(struct Actor02085c80* actor) {
    GameState* bs = GameState::GetInstance();
    int total = 0;
    if (actor->field8f3 & 0x2) {
        total += GetSlotBits0201137c((char*)bs, 0x39);
    }
    if (actor->field8f3 & 0x20) {
        total += GetSlotBits0201137c((char*)bs, 0x3d);
    }
    return total;
}
