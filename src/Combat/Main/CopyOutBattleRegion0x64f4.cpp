#include <globaldefs.h>
#include "System/Memory.h"
#include "GameState/GameState.h"

// USA: func_020ac760
ARM int CopyOutBattleRegion0x64f4_020ac760(void* dst) {
#if defined(jpn)
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x62b4, dst, 0xad6);
#else
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x64f4, dst, 0xad6);
#endif
    return 1;
}
