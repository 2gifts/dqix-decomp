#include <globaldefs.h>
#include "System/Memory.h"
#include "GameState/GameState.h"

// USA: func_020ac78c
ARM int CopyOutBattleField0x64f4_020ac78c(void* dst) {
#if defined(jpn)
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x62b4, dst, 1);
#else
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x64f4, dst, 1);
#endif
    return 1;
}
