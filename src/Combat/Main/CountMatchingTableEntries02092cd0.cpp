#include <globaldefs.h>

#if defined(jpn)
enum { TableOffset = 0x7ca2 };
#else
enum { TableOffset = 0x7f76 };
#endif

#include "GameState/GameState.h"

// USA: func_02092cd0
ARM int CountMatchingTableEntries02092cd0(int unused, int value) {
    unsigned char* bs = (unsigned char*)GameState::GetInstance();
    unsigned char count = 0;
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (value == (bs + i)[TableOffset]) {
            count++;
        }
    }
    return count;
}
