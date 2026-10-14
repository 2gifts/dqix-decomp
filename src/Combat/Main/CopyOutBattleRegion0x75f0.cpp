#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_020abf38
ARM int CopyOutBattleRegion0x75f0_020abf38(void* dst) {
    memcpy(dst, (char*)GameState::GetInstance() + 0x75f0, 0x4d0);
    return 1;
}
