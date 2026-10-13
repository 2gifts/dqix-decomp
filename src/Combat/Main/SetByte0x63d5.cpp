#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define SetByte0x63d5 func_02011dbc
extern "C" ARM void func_02011dbc(void* owner);
#endif

ARM void SetByte0x63d5(void* owner) {
    GameState* state = static_cast<GameState*>(owner);
    state->unk_397d[0x63d5 - 0x397d] = 1;
}
