#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

int GetFieldAt0x150_02053c6c(unsigned char* obj);

int AppendXTag_02041a28(char* dst, int x);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov023_021e8e34  (semantic: AppendCombatantTag_021e8e34)
extern "C" ARM void func_ov023_021e8e34(void* obj) {
    if (*(int*)((char*)obj + 0x5f4) == 0) return;
    char* dst = *(char**)((char*)obj + 0x5d8);
    GameState* battleStruct = GameState::GetInstance();
    void* search = func_0202ae18();
    int fieldPtr = 0;
    if (!CheckField0NonZero_0202b7d8((int*)search)) {
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, 0);
        if (combatant) fieldPtr = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    } else {
        int id = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
        if (combatant) fieldPtr = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    }
    if (fieldPtr == 0) return;
    char* str = (char*)fieldPtr + 0x3c;
    int len = strlen(str);
    int total = len * 5 + 6;
    int pad = (total / 8 + 1) * 8 - len * 5;
    pad = pad / 2;
    AppendXTag_02041a28(dst, pad);
    AppendString02042058(dst, str);
}
