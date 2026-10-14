#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: _Z27GetField0x3acValue_020100a8P9GameState
ARM int GetField0x3acValue_020100a8(GameState* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3ac);
}
