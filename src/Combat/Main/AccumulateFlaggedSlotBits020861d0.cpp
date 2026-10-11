#include <globaldefs.h>
#if defined(jpn)
#define data_020e8ad2 data_020e8bec
#endif
#include "GameState/GameState.h"

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);
extern short data_020e8ad2[];

// USA: func_020861d0
ARM int AccumulateFlaggedSlotBits020861d0(unsigned char* actor) {
    short* list;
    GameState* bs = GameState::GetInstance();
    int total = 0;
    unsigned char i = 0;
    list = data_020e8ad2;
    short id;
    while ((id = list[i]) != -1) {
        if (TestBitInArray0x8ec(actor, id)) {
            total += GetSlotBits0201137c((char*)bs, id);
        }
        i = (i + 1) & 0xff;
    }
    return total;
}

// JPN: 0x02086af0
