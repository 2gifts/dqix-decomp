#include <globaldefs.h>
#include "GameState/GameState.h"

extern int GetGlobalField0x1c020421a0();
extern void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);

// USA: func_ov017_021bf360
ARM void ResetBattleScaleField_021bf360(void*) {
    GameState* battleStruct = GameState::GetInstance();
    void* obj = (void*)GetGlobalField0x1c020421a0();
    int count = battleStruct->GetTickCount();
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
}
