#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

// USA: func_020ac4c0
ARM int LoadBattleBlock020ac4c0(void* dst) {
    char* base;
    memset(dst, 0, 0xb0);
#if defined(jpn)
    base = (char*)GameState::GetInstance() + 0x2c4 + 0x7000;
#else
    base = (char*)GameState::GetInstance() + 0x104 + 0x7400;
#endif
    memcpy(dst, base + 0x3c, 0xb0);
    return 1;
}
