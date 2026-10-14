#include <globaldefs.h>
#include "GameState/GameState.h"

extern int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
extern "C" void func_ov017_021d6134(void* param, int val);

// USA: func_ov001_021626a4
ARM int NotifyIfField63dcSet_021626a4(void* param) {
    GameState* bs = GameState::GetInstance();
    if (CheckBitsInField0x63dc_02011b50(bs, 1)) {
        int val = CheckBitsInField0x63dc_02011b50(bs, 1);
        func_ov017_021d6134(param, val);
    }
    return 1;
}
