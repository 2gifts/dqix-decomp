#include <globaldefs.h>
#include "GameState/GameState.h"

ARM int GetGlobal02109400_02094a00(void);
extern "C" ARM void func_02094ab0(void* obj);
ARM int GetGlobalField0x1c020421a0();
ARM void ReinitController02043204(char* obj);
ARM void ClearSubstructBytes_0200fb40(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020936b0
ARM void ResetBattlePhaseController020936b0(void* obj) {
    unsigned char* self = (unsigned char*)obj;
    func_02094ab0((void*)GetGlobal02109400_02094a00());
    self[0x37] &= ~4;
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    *(short*)(self + 0x30) = -1;
    self[0x34] = 4;
    self[0x35] = 0;
    ClearSubstructBytes_0200fb40(GameState::GetInstance());
}
