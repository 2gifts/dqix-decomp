#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue400_200 = 0x200 };
enum { kRegionValue82_AA = 0xaa };
#else
enum { kRegionValue400_200 = 0x400 };
enum { kRegionValue82_AA = 0x82 };
#endif


void* GetPtrField0x2a04(GameState* battleStruct);

// USA: func_ov003_02161544
// JPN: func_ov003_0216162c
ARM int CountFlaggedCombatants_02161544(void* self) {
    GameState* bs = GameState::GetInstance();
    unsigned char* arr = (unsigned char*)GetPtrField0x2a04(bs);
    unsigned char count = 0;
    unsigned char i = 0;
    while (i < arr[0xf7c]) {
        unsigned char* p = arr + i;
        unsigned char id = p[0xf78];
        if (id != *(short*)((char*)self + kRegionValue400_200 + kRegionValue82_AA)) {
            GameObject* c = bs->GetCombatantByIndex(id);
            if (c != NULL) {
                int* q = *(int**)((char*)c + 0x130);
                if (*(unsigned short*)((char*)q + 4) != 0) {
                    count = count + 1;
                }
            }
        }
        i = i + 1;
    }
    return count;
}
