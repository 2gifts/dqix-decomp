#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02094ab0(void);

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetGlobal02109400_02094a00(void);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

// USA: func_020d9ab0
ARM void InitBattleAndControllerState_020d9ab0(void* param) {
    GameState* bs = GameState::GetInstance();
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    GetGlobal02109400_02094a00();
    func_02094ab0();
    SetField0x23cTrue_020a27ac((void*)GetFieldIfFlag4_020100f8((char*)bs));
    *((unsigned char*)param + 1) = 1;
}
