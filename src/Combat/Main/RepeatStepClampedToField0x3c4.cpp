#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02067b28(void* obj);

// USA: func_02067e58
ARM void RepeatStepClampedToField0x3c4_02067e58(void* obj, int count) {
    GameState* battleStruct;
    unsigned int minCount;
    if (count == 0) {
        return;
    }
    battleStruct = GameState::GetInstance();
    minCount = ((GameState*)(battleStruct))->GetTickCount();
    if ((unsigned int)count < minCount) {
        count = minCount;
    }
    while (count > 0) {
        func_02067b28(obj);
        if (count != 0) {
            count--;
        }
    }
}
