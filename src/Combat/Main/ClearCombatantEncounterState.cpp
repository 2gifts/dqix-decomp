#include <globaldefs.h>
#if defined(jpn)
#define func_ov003_0217dc40 func_ov003_0217c8e0
#endif
#include "GameState/GameState.h"

void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void ClearFlagBits(unsigned char* obj, int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern "C" void func_ov003_0217dc40(int arg);
extern "C" void func_020dae08(void* obj);

// USA: func_020daeb0
ARM void ClearCombatantEncounterState(void* obj) {
    GameState* battle = GameState::GetInstance();
    void* ov = func_ov017_0218b5b0();
    int field0xc = *(int*)((char*)obj + 0xc);
    if (field0xc != 0) {
        func_ov003_0217dc40(field0xc);
    }
    func_020dae08(obj);
    SetByteField0x253(battle->GetUnknownGameObject());
    int flagResult = GetFieldIfFlag4((char*)battle);
    SetField0x23cTrue((void*)flagResult);
    ClearFlagBits((unsigned char*)flagResult, 2);
    ClearBitsInField4((unsigned int*)ov, 0xc0);
    *((unsigned char*)obj + 1) = 1;
}
