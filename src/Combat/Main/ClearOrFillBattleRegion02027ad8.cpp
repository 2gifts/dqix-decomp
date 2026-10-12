#include <globaldefs.h>

#if defined(jpn)
#define ClearOrFillBattleRegion02027ad8 func_02027344
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Region02027ad8 {
    #if defined(jpn)
    char pad[0x18c];
#else
    char pad[0x3cc];
#endif
    unsigned char slots[0x40][0x200];
};

#if defined(jpn)
extern "C" ARM void func_02027344(int unused, int flag);
#endif

// USA: func_02027ad8
ARM void ClearOrFillBattleRegion02027ad8(int unused, int flag) {
    struct Region02027ad8* r = (struct Region02027ad8*)GameState::GetInstance();
    if (flag != 0) {
        memset(r->slots[54], 0xff, sizeof(r->slots[54]));
    } else {
        memset(r->slots[54], 0, sizeof(r->slots[54]));
    }
}
