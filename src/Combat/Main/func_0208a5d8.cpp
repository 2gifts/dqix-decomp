#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int oldVal, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

// USA: func_0208a5d8
extern "C" ARM int func_0208a5d8(int* p0, int id, int* outPtr, int p3) {
    unsigned char i;
    GameState* bs;
    GameObject* combatant;
    struct ModifiableCombatStats* stats;
    unsigned char* p38;
    char* arr148;
    struct Random* random;
    unsigned char bit;
    unsigned char inv;
    unsigned char base;
    unsigned char slotA;
    unsigned char slotB;

    bs = GameState::GetInstance();
    combatant = GetCombatantWithFlag0x400_0200fea4(bs, id);
    arr148 = *(char**)((char*)combatant + 0x148);
    stats = combatant->currentStats_;
    p38 = (unsigned char*)((char*)stats + 0x38);
    *p38 = *p38 % 3u;
    i = 0;
    random = (struct Random*)*p0;

    while (i < 3) {
        bit = NextRandom(random) & 1;
        inv = bit ^ 1;
        base = *p38 * 2;
        slotA = base + bit;
        slotB = base + inv;
        *p38 = *p38 + 1;
        *p38 = *p38 % 3u;
        if (func_0208a03c(p0, slotA, id, outPtr, p3) != 0) {
            return *(unsigned short*)(arr148 + slotA * 2 + 0x18);
        }
        if (func_0208a03c(p0, slotB, id, outPtr, p3) != 0) {
            return *(unsigned short*)(arr148 + slotB * 2 + 0x18);
        }
        i = i + 1;
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
    return 2;
}
