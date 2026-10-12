#include <globaldefs.h>

#if defined(jpn)
#define ResetBattleScaleFieldAndDtor_021a925c func_ov017_021a9a40
extern "C" void ResetBattleScaleFieldAndDtor_021a925c(char* self);
#define EmptyDestructor0205cb60 func_0205deb8
extern "C" void EmptyDestructor0205cb60(void* obj);
#endif
#include "GameState/GameState.h"

extern int GetGlobalField0x1c020421a0();
extern void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);
extern void EmptyDestructor0205cb60(void* obj);

// USA: func_ov017_021a925c
ARM void ResetBattleScaleFieldAndDtor_021a925c(char* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* obj = (void*)GetGlobalField0x1c020421a0();
    int count = battleStruct->GetTickCount();
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
    EmptyDestructor0205cb60(self + 0x2c);
}
