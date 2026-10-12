#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c5 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd5 };
#endif


#if defined(jpn)
#define func_ov025_021e7214 func_ov025_021e76c4
#endif
#include "GameState/GameState.h"

void* GetActiveCombatWork(void);
int GetField0x3b0Value(GameState* battleStruct);
extern "C" void _Z33SetField0x7cClearFields0x1ec0x1eePht(unsigned char* obj, short val);

struct Param021e7214 { char pad[8]; short field8; };

// USA: func_ov025_021e7214  (semantic: SetActiveFlagAndField_021e7214)
extern "C" ARM int func_ov025_021e7214(struct Param021e7214* p) {
    void* w = GetActiveCombatWork();
    if (w != 0) {
        *(unsigned char*)((char*)w + kWorkFlagBase + kWorkFlagOffset) = 1;
    }
    GameState* bs = GameState::GetInstance();
    int f = GetField0x3b0Value(bs);
    _Z33SetField0x7cClearFields0x1ec0x1eePht((unsigned char*)f, p->field8);
    return 1;
}
