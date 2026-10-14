#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c5 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd5 };
#endif

#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

void* GetActiveCombatWork_ov000_02160130(void);
extern "C" void _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht(unsigned char* obj, short val);

struct Param021e7214 { char pad[8]; short field8; };

// USA: func_ov025_021e7214  (semantic: SetActiveFlagAndField_021e7214)
extern "C" ARM int func_ov025_021e7214(struct Param021e7214* p) {
    void* w = GetActiveCombatWork_ov000_02160130();
    if (w != 0) {
        *(unsigned char*)((char*)w + kWorkFlagBase + kWorkFlagOffset) = 1;
    }
    GameState* bs = GameState::GetInstance();
    unsigned char* f = (unsigned char*)GetField0x3b0Value_020100bc(bs);
    _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht(f, p->field8);
    return 1;
}
