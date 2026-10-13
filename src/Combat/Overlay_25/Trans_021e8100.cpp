#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

extern "C" unsigned int _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e8100  (semantic: Trans_021e8100)
extern "C" ARM unsigned int func_ov025_021e8100(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = r0;
    GameState* state = GameState::GetInstance();
    void* context = GetField0x3b0Value(state);
    if (context != 0) {
        _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii((unsigned int)context, *(short*)((char*)r4 + 0xa), *(unsigned short*)((char*)r4 + 0x8));
    }
    return 1;
}
