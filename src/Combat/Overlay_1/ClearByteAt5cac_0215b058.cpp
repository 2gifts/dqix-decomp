#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov001_0215b058
ARM int ClearByteAt5cac_0215b058(void) {
#if defined(jpn)
    enum { regionalFieldOffset = 0xa4c };
#else
    enum { regionalFieldOffset = 0xcac };
#endif
    ((char*)GameState::GetInstance() + 0x5000)[regionalFieldOffset] = 0;
    return 1;
}
