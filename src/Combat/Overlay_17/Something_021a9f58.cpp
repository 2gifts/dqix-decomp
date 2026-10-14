#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetGlobal02109400_02094a00(void);
extern "C" void func_02094ab0(void);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
void SetByteField0x253_020397c0(void* obj);
extern "C" void func_ov017_021a9fa0(int self);

// USA: func_ov017_021a9f58
ARM void Something_021a9f58(int selfParam) {
    GameState* battle = GameState::GetInstance();
    ReinitController02043204((char*)(long)GetGlobalField0x1c020421a0());
    GetGlobal02109400_02094a00();
    func_02094ab0();
    SetMainBrightness((GameResources*)func_ov017_0218b5b0(), 0, 0x14);
    SetByteField0x253_020397c0(battle->GetUnknownGameObject());
    func_ov017_021a9fa0(selfParam);
}
