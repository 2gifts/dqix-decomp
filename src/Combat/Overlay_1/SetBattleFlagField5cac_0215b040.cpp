#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov001_0215b040
ARM int SetBattleFlagField5cac_0215b040() {
#if defined(jpn)
    enum { regionalFieldOffset = 0xa4c };
#else
    enum { regionalFieldOffset = 0xcac };
#endif
    *(unsigned char*)((char*)GameState::GetInstance() + 0x5000 + regionalFieldOffset) = 1;
    return 1;
}
