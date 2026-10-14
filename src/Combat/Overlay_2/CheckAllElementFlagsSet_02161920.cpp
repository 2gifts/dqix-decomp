#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);

// USA: func_ov002_02161920  (semantic: CheckAllElementFlagsSet_02161920)
extern "C" ARM int func_ov002_02161920(void) {
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        GameState* bs = GameState::GetInstance();
        unsigned char* base = (unsigned char*)GetPtrField0x2a04_02010828(bs);
        unsigned char i = 0;
        while (i < base[0xf7c]) {
            unsigned char* p = base + i;
            if (p[0xf78] == 0) {
                return 2;
            }
            i++;
        }
        return 1;
    }
    return 0;
}
