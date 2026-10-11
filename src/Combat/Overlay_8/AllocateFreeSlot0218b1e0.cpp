#if defined(jpn)
#define R(j,u) (j)
#define func_0205c96c func_0205dcd4
#define func_ov013_02186cac func_ov013_02187fc0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Bits0218b1e0 { unsigned short low : 14; unsigned short flag : 1; unsigned short hi : 1; };

// USA: func_ov008_0218b1e0
ARM void AllocateFreeSlot0218b1e0(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)bs + R(0x3bc + 0x6c00, 0x1fc + 0x7000);
    unsigned char* p = base + 4;
    for (int i = 0; i < 0x10; p += 0x2c, i++) {
        struct Bits0218b1e0* b = (struct Bits0218b1e0*)(p + 0x12);
        if (!b->flag) {
            memcpy(p, (char*)obj + R(0xdec, 0xdf0), 0x2c);
            base[0]++;
            return;
        }
    }
}
