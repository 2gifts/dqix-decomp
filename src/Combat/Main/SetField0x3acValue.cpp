#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_020100a0
ARM void SetField0x3acValue_020100a0(GameState* battleStruct, int value) {
    *(int*)((char*)battleStruct + 0x3ac) = value;
}
