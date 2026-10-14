#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
void ClearSubstructByte0x56_02049f3c(unsigned char* obj);
void* GetActiveCombatWork_ov000_02160130(void);
void ClearBitIfValueFound02167434(unsigned char* obj, int value);

struct Obj021e697c {
    char pad[8];
    unsigned char field8;
};

// USA: func_ov025_021e697c
ARM int ClearFoundBitsForList_021e697c(struct Obj021e697c* obj, int p1, int unusedArg, void* p3) {
    int local[8];
    GameState* bs = GameState::GetInstance();
    int count = DispatchByIndex021820bc(p3, p1, obj->field8, (int)&local[0]);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(local[i]);
        if (c != NULL) {
            ClearSubstructByte0x56_02049f3c((unsigned char*)c);
            {
                void* work = GetActiveCombatWork_ov000_02160130();
                int val = ((Object3D*)((unsigned char*)c))->GetTexturePaletteOffset();
                ClearBitIfValueFound02167434((unsigned char*)work, val);
            }
        }
    }
    return 1;
}
