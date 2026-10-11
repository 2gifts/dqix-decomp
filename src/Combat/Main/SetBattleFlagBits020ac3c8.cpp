#include <globaldefs.h>
#if defined(jpn)
enum { kBaseOffset = 0x2c4 };
enum { kArrayOffset = 0x7000 };
#else
enum { kBaseOffset = 0x104 };
enum { kArrayOffset = 0x7400 };
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

// USA: func_020ac3c8
ARM int SetBattleFlagBits020ac3c8(unsigned int* dst, short* indices, int count) {
    char* base;
    int i;
    memset(dst, 0, 0x3c);
    base = (char*)GameState::GetInstance() + kBaseOffset;
    memcpy(dst, base + kArrayOffset, 0x3c);
    for (i = 0; i < count; i++) {
        short bit = indices[i];
        if (bit > 0) {
            dst[bit / 32] |= (1 << (bit % 32));
        }
    }
    memcpy(base + kArrayOffset, dst, 0x3c);
    return 1;
}
