#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_02039730
ARM int GetCombatSignedByteAt0x2c8d02039730(void* unused, int index) {
    char* p = (char*)GetPtrField0x2a04_02010828((GameState*)(GameState::GetInstance())) + index;
    return p[0x2c8d];
}
