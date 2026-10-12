#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c5 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd5 };
#endif


#if defined(jpn)
#define func_ov025_021e5a2c func_ov025_021e5f1c
#endif
#include "GameState/GameState.h"

void* GetActiveCombatWork(void);
int GetField0x3b0Value(GameState* battleStruct);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov025_021e5a2c
extern "C" ARM int func_ov025_021e5a2c(void* obj) {
    GameState* bs = GameState::GetInstance();
    int f = GetField0x3b0Value(bs);
    if (f != 0) {
        _ZN8Vector3iaSERKS_((int*)(f + 4), (int*)((char*)obj + 8));
    }
    void* w = GetActiveCombatWork();
    if (w) {
        *(unsigned char*)((char*)w + kWorkFlagBase + kWorkFlagOffset) = 1;
    }
    return 1;
}
