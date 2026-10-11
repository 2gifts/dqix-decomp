#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_020ac494
ARM int CopyInBattleField0x7540(void* src) {
#if defined(jpn)
    int* region = (int*)((char*)GameState::GetInstance() + 0x2c4);
#else
    int* region = (int*)((char*)GameState::GetInstance() + 0x104);
#endif
#if defined(jpn)
    memcpy((char*)(region + 0x1c00) + 0x3c, src, 0xb0);
#else
    memcpy((char*)(region + 0x1d00) + 0x3c, src, 0xb0);
#endif
    return 1;
}
