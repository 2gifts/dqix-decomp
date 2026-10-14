#include <globaldefs.h>
#include "GameState/GameState.h"

short SumKeyedLookups02086bf4(char* obj, int key);

// USA: func_ov003_02179da8  (semantic: CheckGoldCapTier_02179da8)
extern "C" ARM int func_ov003_02179da8(void* obj, int flag) {
    GameState* bs = GameState::GetInstance();
    void* p = GetPtrField0x2a04_02010828(bs);
    int keyResult = 1;
    if (flag != 0) {
        short key = *(short*)((char*)obj + 0x18);
        keyResult = SumKeyedLookups02086bf4((char*)p, key);
    }
    unsigned short rate = *(unsigned short*)((char*)obj + 0x1a);
    unsigned int total = *(unsigned int*)((char*)p + 0xf6c);
    if (total + rate > 9999999) {
        return 2;
    }
    if (keyResult == 1) {
        return 1;
    }
    return (total + rate * 2 > 9999999) ? 1 : 0;
}
