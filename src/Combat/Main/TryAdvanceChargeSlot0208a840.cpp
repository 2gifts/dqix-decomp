#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int oldVal, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

// USA: func_0208a840
ARM int TryAdvanceChargeSlot0208a840(int* p0, int id, int* outPtr, int p3) {
    GameState* bs;
    GameObject* combatant;
    char* arr148;
    unsigned char* slot;
    unsigned char old;
    unsigned char i;

    bs = GameState::GetInstance();
    combatant = GetCombatantWithFlag0x400_0200fea4(bs, id);
    arr148 = *(char**)((char*)combatant + 0x148);
    slot = (unsigned char*)((char*)(*p0) + 0x81c0 + *((unsigned char*)combatant + 0x17c) * 0x18);

    for (i = 0; i < 6; i++) {
        old = *slot;
        *slot = old + 1;
        *slot = *slot % 6;
        if (func_0208a03c(p0, old, id, outPtr, p3) != 0) {
            return *(unsigned short*)(arr148 + old * 2 + 0x18);
        }
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
    return 2;
}
