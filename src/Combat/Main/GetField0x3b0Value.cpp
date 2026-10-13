#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

// USA: func_020100bc
ARM void* GetField0x3b0Value(GameState* battleStruct) {
    return battleStruct->unknown_3b0_;
}
