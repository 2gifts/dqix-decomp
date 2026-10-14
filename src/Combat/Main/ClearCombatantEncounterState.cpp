#include <globaldefs.h>
#if defined(jpn)
#define func_ov003_0217dc40 func_ov003_0217c8e0
#endif
#include "GameState/GameState.h"

void SetByteField0x253_020397c0(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

extern "C" void func_ov003_0217dc40(int arg);
extern "C" void func_020dae08(void* obj);

// USA: func_020daeb0
ARM void ClearCombatantEncounterState_020daeb0(void* obj) {
    GameState* battle = GameState::GetInstance();
    void* ov = func_ov017_0218b5b0();
    int field0xc = *(int*)((char*)obj + 0xc);
    if (field0xc != 0) {
        func_ov003_0217dc40(field0xc);
    }
    func_020dae08(obj);
    SetByteField0x253_020397c0(battle->GetUnknownGameObject());
    int flagResult = GetFieldIfFlag4_020100f8((char*)battle);
    SetField0x23cTrue_020a27ac((void*)flagResult);
    ClearFlagBits_020a28b0((unsigned char*)flagResult, 2);
    ClearBitsInField4_0203b4e8((unsigned int*)ov, 0xc0);
    *((unsigned char*)obj + 1) = 1;
}
