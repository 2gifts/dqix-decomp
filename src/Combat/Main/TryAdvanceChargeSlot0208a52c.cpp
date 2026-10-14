#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int oldVal, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

// USA: func_0208a52c
ARM int TryAdvanceChargeSlot0208a52c(int* p0, int id, int* outPtr, int p3) {
    GameState* bs;
    GameObject* combatant;
    char* arr148;
    struct ModifiableCombatStats* stats;
    unsigned char* p38;
    unsigned char old;
    unsigned char i;

    bs = GameState::GetInstance();
    combatant = GetCombatantWithFlag0x400_0200fea4(bs, id);
    arr148 = *(char**)((char*)combatant + 0x148);
    stats = combatant->currentStats_;
    p38 = (unsigned char*)((char*)stats + 0x38);

    for (i = 0; i < 6; i++) {
        old = *p38;
        *p38 = old + 1;
        *p38 = *p38 % 6;
        if (func_0208a03c(p0, old, id, outPtr, p3) != 0) {
            return *(unsigned short*)(arr148 + old * 2 + 0x18);
        }
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
    return 2;
}
