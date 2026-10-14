#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void ApplyVecFromField0x246_020a2718(char* actor);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" void func_ov004_0216fa48(char* obj);

// USA: func_020e4524
ARM void StartBattleTimerSequence020e4524(char* obj) {
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    ApplyVecFromField0x246_020a2718((char*)GetFieldIfFlag4_020100f8((char*)GameState::GetInstance()));
    SetMainBrightness((GameResources*)func_ov017_0218b5b0(), 0, 0x3c);
    func_ov004_0216fa48(obj);
}
