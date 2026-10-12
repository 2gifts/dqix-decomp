#include <globaldefs.h>

#if defined(jpn)
#define FindMatchingTableIndex02092d18 func_02093638
#endif
#if defined(jpn)
enum { TableOffset = 0x7ca2 };
#else
enum { TableOffset = 0x7f76 };
#endif

#include "GameState/GameState.h"

#if defined(jpn)
extern "C" int func_02093638(int unused, int value);
#endif

// USA: func_02092d18
ARM int FindMatchingTableIndex02092d18(int unused, int value) {
    unsigned char* bs = (unsigned char*)GameState::GetInstance();
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (value == (bs + i)[TableOffset]) {
            return (signed char)i;
        }
    }
    return -1;
}
