#include <globaldefs.h>
#include "GameState/GameState.h"

int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void ClearFieldKeepBit0x10_02011af0(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

// USA: func_ov004_02168884  (semantic: ClearFlagAndSetArrayBit_02168884)
extern "C" ARM int func_ov004_02168884(void) {
    GameState* battle = GameState::GetInstance();
    CheckBitsInField0x63dc_02011b50(battle, 1);
    ClearFieldKeepBit0x10_02011af0(battle);
    void* p = func_0205ec34();
    SetOrClearBitInArray_0206df6c(p, (unsigned char*)p + 0x8c, 3, 0);
    return 0;
}
