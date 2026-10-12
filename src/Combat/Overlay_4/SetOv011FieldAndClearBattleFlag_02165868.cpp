#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02165868 func_ov004_021660f8
#endif

#if defined(jpn)
enum { battleFlagOffset = 0x1ee };
#else
enum { battleFlagOffset = 0x46e };
#endif

#include "GameState/GameState.h"

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02165868  (semantic: SetOv011FieldAndClearBattleFlag_02165868)
extern "C" ARM int func_ov004_02165868(void* obj) {
    func_ov011_021848a0(obj, 0x6c);
    GameState* battle = GameState::GetInstance();
    *((unsigned char*)battle + 0x6000 + battleFlagOffset) = 0;
    return 0;
}
