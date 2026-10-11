#include <globaldefs.h>
#if defined(jpn)
#define data_020e8bec data_020e8d06
#endif
#include "GameState/GameState.h"

extern short data_020e8bec[];

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);

// USA: func_020862a8
ARM int AccumulateSlotBitsFromTable020862a8(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    int total = 0;
    unsigned char i;
    short idx;
    for (i = 0; (idx = data_020e8bec[i]) != -1; i++) {
        if (TestBitInArray0x8ec(obj, idx)) {
            total += GetSlotBits0201137c((char*)bs, idx);
        }
    }
    return total;
}

// JPN: 0x02086bc8
