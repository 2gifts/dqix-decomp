#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0();
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(int a, int b);

#if defined(jpn)
#define RunBattleScaleStepAndFinalize func_020d9db0
extern "C" ARM void RunBattleScaleStepAndFinalize(void);
#endif

// USA: func_020d844c
ARM void RunBattleScaleStepAndFinalize(void) {
    GameState* b = GameState::GetInstance();
    int x = GetGlobalField0x1c020421a0();
    unsigned int y = b->GetTickCount();
    Forward0204359c((void*)x, y);
    func_020439b0(x, 0);
}
