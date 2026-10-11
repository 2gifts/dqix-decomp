#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

// USA: func_020ac0dc
ARM int ClearBattleRegion0x7ac4() {
    GameState* bs = GameState::GetInstance();
#if defined(jpn)
    memset((char*)bs + 0x7884, 0, 0x3ae);
#else
    memset((char*)bs + 0x7ac4, 0, 0x3ae);
#endif
    return 1;
}
