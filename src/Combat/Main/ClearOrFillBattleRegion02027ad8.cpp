#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { RangeOffset = 0x4c };
#else
enum { RangeOffset = 0xc };
#endif

// USA: func_02027ad8
ARM void ClearOrFillBattleRegion02027ad8(int unused, int flag) {
    GameState* state = GameState::GetInstance();

    if (flag != 0) {
        memset(state->unk_6fc0 + RangeOffset, 0xff, 0x200);
    } else {
        memset(state->unk_6fc0 + RangeOffset, 0, 0x200);
    }
}
