#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_ov003_02169938
ARM int AddCappedFieldF6c_02169938(int unused, int amount) {
    GameState* bs = GameState::GetInstance();
    void* p = GetPtrField0x2a04(bs);
    int val = *(int*)((char*)p + 0xf6c);
    if (val < -amount) {
        return 0;
    }
    val += amount;
    *(int*)((char*)p + 0xf6c) = val;
    if ((unsigned int)val > 0x98967f) {
        *(int*)((char*)p + 0xf6c) = 0x98967f;
    }
    return 1;
}
