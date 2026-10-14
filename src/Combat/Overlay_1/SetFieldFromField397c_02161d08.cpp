#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void*, int);
unsigned char GetField0x397cValue_020100b0(GameState* battleStruct);

// USA: func_ov001_02161d08  (semantic: SetFieldFromField397c_02161d08)
extern "C" ARM int func_ov001_02161d08(void* self) {
    GameState* battle = GameState::GetInstance();
    int v = GetField0x397cValue_020100b0(battle);
    func_ov017_021d6134(self, v);
    return 1;
}
