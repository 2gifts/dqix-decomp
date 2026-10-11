#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetActiveCombatWork(void);
unsigned char GetByte_021dcc64_021dcc64(void* obj);
int GetField0x3b0Value(GameState* battleStruct);
void CallFunc020a0d6cAtField0x194AndClearFlag2(char* obj, int a, int b, int c, int d);

struct Param021e7248 {
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
};

// JPN: func_ov025_021e76f8
// USA: func_ov025_021e7248
extern "C" ARM int func_ov025_021e7248(struct Param021e7248* p) {
#if defined(jpn)
 enum {regionalOffset0=0x7000, regionalOffset1=0x1c5};
#else
 enum {regionalOffset0=0x6000, regionalOffset1=0xfd5};
#endif
    void* w = GetActiveCombatWork();
    if (w != 0) {
        *(unsigned char*)((char*)w + regionalOffset0 + regionalOffset1) = 1;
        if (GetByte_021dcc64_021dcc64(w) != 0) {
            return 1;
        }
    }
    GameState* bs = GameState::GetInstance();
    int field = GetField0x3b0Value(bs);
    CallFunc020a0d6cAtField0x194AndClearFlag2((char*)field, (int)((char*)p + 8), p->f14, p->f18, p->f1c);
    return 1;
}
