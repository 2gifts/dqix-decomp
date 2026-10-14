#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Memory.h"

// USA: func_020ac734
ARM int CopyToBattleRegion0x64f4_020ac734(void* arg) {
    GameState* bs = GameState::GetInstance();
#if defined(jpn)
    VectorizedInvertedMemcpy(arg, (char*)bs + 0x62b4, 0xad6);
#else
    VectorizedInvertedMemcpy(arg, (char*)bs + 0x64f4, 0xad6);
#endif
    return 1;
}
