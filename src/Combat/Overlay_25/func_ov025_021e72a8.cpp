#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c5 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd5 };
#endif

#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

void* GetActiveCombatWork_ov000_02160130(void);
int CallFunc020a0d6cAtField0x16c_0202ed7c(char* obj, int a, int b, int c, int d);

struct Param021e72a8 {
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
};

// USA: func_ov025_021e72a8
extern "C" ARM int func_ov025_021e72a8(struct Param021e72a8* p) {
    void* w = GetActiveCombatWork_ov000_02160130();
    if (w != 0) {
        *(unsigned char*)((char*)w + kWorkFlagBase + kWorkFlagOffset) = 1;
    }
    GameState* bs = GameState::GetInstance();
    char* field = (char*)GetField0x3b0Value_020100bc(bs);
    CallFunc020a0d6cAtField0x16c_0202ed7c(field, (int)((char*)p + 8), p->f14, p->f18, p->f1c);
    return 1;
}
