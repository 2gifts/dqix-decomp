#include <globaldefs.h>
#if defined(jpn)
#define data_020e8a9e data_020e8bc4
#endif
#include "GameState/GameState.h"

extern short data_020e8a9e[];

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);

// USA: func_02086314
ARM int AccumulateSlotBitsFromTable02086314(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    int total = 0;
    unsigned char i;
    short idx;
    for (i = 0; (idx = data_020e8a9e[i]) != -1; i++) {
        if (TestBitInArray0x8ec(obj, idx)) {
            total += GetSlotBits0201137c((char*)bs, idx);
        }
    }
    return total;
}

// JPN: 0x02086c34
