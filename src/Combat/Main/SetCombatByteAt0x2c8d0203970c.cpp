#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0203970c
ARM void SetCombatByteAt0x2c8d0203970c(void* unused, int index, int value) {
    char* p = (char*)GetPtrField0x2a04_02010828((GameState*)(GameState::GetInstance())) + index;
    p[0x2c8d] = (char)value;
}
