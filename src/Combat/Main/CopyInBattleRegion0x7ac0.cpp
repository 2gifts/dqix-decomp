#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_020ac08c
ARM int CopyInBattleRegion0x7ac0(void* src) {
#if defined(jpn)
    memcpy((char*)GameState::GetInstance() + 0x7880, src, 4);
#else
    memcpy((char*)GameState::GetInstance() + 0x7ac0, src, 4);
#endif
    return 1;
}
