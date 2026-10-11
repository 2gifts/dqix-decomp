#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

// USA: func_020ac460
ARM int LoadBattleBlock020ac460(void* dst) {
    memset(dst, 0, 0x3c);
#if defined(jpn)
    memcpy(dst, (char*)GameState::GetInstance() + 0x2c4 + 0x7000, 0x3c);
#else
    memcpy(dst, (char*)GameState::GetInstance() + 0x104 + 0x7400, 0x3c);
#endif
    return 1;
}
