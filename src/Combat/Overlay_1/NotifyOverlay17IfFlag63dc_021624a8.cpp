#include <globaldefs.h>
#include "GameState/GameState.h"

int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
extern "C" void func_ov017_0219c520(void);

// USA: func_ov001_021624a8
ARM int NotifyOverlay17IfFlag63dc_021624a8(void) {
    if (CheckBitsInField0x63dc_02011b50(GameState::GetInstance(), 1)) {
        func_ov017_0219c520();
    }
    return 1;
}
