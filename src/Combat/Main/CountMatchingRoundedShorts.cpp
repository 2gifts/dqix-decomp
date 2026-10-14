#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index);
signed short GetShortFromArray0xc10_0207c620(unsigned char* obj, unsigned int index);
extern short data_020f29dc[];

// USA: func_020dd300
ARM int CountMatchingRoundedShorts_020dd300(int mask) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* obj = (unsigned char*)GetPtrField0x2a04_02010828(battleStruct);
    signed short* arr = (signed short*)GetPointerFromArray0xbd0_0207c5f8(obj + 0x1d4, 0);
    short count = GetShortFromArray0xc10_0207c620(obj + 0x1d4, 0);
    short result = 0;
    for (short i = 0; i < count; i++) {
        signed short v = arr[i];
        if (v > 0) {
            v -= v % 100;
            for (unsigned char j = 0; j < 12; j++) {
                if (mask & (1 << j)) {
                    if (v == data_020f29dc[j]) {
                        result++;
                        break;
                    }
                }
            }
        }
    }
    return result;
}
