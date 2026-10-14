#include <globaldefs.h>
#include "GameState/GameState.h"

extern void* GetPtrField0x2a04_02010828(GameState* battleStruct);

// USA: func_0207d2c4  (semantic: ClampAddFieldF6c)
extern "C" ARM int func_0207d2c4(int unused, int amount) {
    if (amount < 0) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    char* p = (char*)GetPtrField0x2a04_02010828(bs);
    unsigned int cap = 0x98967f;
    if (cap - amount >= *(unsigned int*)(p + 0xf6c)) {
        *(unsigned int*)(p + 0xf6c) += amount;
    } else {
        *(unsigned int*)(p + 0xf6c) = cap;
    }
    return 1;
}
