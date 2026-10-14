#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov003_02160bd0
ARM void* GetElementAtIndex_02160bd0_02160bd0(void* unused, int index) {
    if (index < 0) return NULL;
    void* p = GetPtrField0x2a04_02010828(GameState::GetInstance());
    return (char*)p + 0xf80 + index * 0x23c;
}
