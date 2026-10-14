#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215eb1c(void* p0, short* arr, int count, int flag);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern short data_ov000_02182c44[8];

struct ShortBlob8_0215fc8c { short v[8]; };

struct Inner0215fc8c { char pad[0x10]; unsigned short val; };

// USA: func_ov000_0215fc8c
ARM int FindCombatantWithValue_0215fc8c(void* p0, int targetVal) {
    short localArray[8];
    *(struct ShortBlob8_0215fc8c*)localArray = *(struct ShortBlob8_0215fc8c*)data_ov000_02182c44;
    int count = (short)func_ov000_0215eb1c(p0, localArray, 8, 0);
    int i = 0;
    while (i < count) {
        short id = localArray[i];
        GameState* bs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, id);
        if (c != NULL) {
            struct Inner0215fc8c* inner = *(struct Inner0215fc8c**)((char*)c + 0x144);
            if (inner != NULL) {
                if (inner->val == targetVal) {
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}
