#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_020ac0b4
ARM int CopyOutBattleField0x7ac0_020ac0b4(void* dst) {
#if defined(jpn)
    memcpy(dst, (char*)GameState::GetInstance() + 0x7880, 4);
#else
    memcpy(dst, (char*)GameState::GetInstance() + 0x7ac0, 4);
#endif
    return 1;
}
