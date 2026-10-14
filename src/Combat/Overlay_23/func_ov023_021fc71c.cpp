#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
void InitWordsQuad_021e60e0(void* obj, unsigned int val);
void ClearShortsAt_021e616c_021e616c(char* obj);
extern "C" int func_ov023_021e5974(int a, int b, int c, int d, int e);

struct FlagByte021fc71c {
    unsigned char bit0 : 1;
    unsigned char restBits : 7;
};

// USA: func_ov023_021fc71c  (semantic: InitOrClearCombatantSlot_021fc71c)
extern "C" ARM void func_ov023_021fc71c(void* obj, int id, int flagArg) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battle, id);
    unsigned char bit0 = ((struct FlagByte021fc71c*)((char*)obj + 0x1864))->bit0;
    int idx = (bit0 + 1) % 2;
    int mul = idx * 0xc20;
    char* base = (char*)obj + 0x20;
    if (flagArg != 0) {
        InitWordsQuad_021e60e0(base + mul, 0x1eb);
    }
    ClearShortsAt_021e616c_021e616c(base + mul);
    int fieldVal = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    func_ov023_021e5974((int)(base + mul), fieldVal, id, 1, 0);
    *(unsigned char*)((int)obj + 0x1864) |= 8;
}
