#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void _Z23SetLinkIfType3_021d6148P12Node021d6148j(void* node, float v);

struct Triple { int x[3]; };

// USA: func_ov001_0215da14  (semantic: SetLinksFromField3b0_0215da14)
extern "C" ARM int func_ov001_0215da14(char* obj) {
    int result;
    GameState* battle = GameState::GetInstance();
    void* field = GetField0x3b0Value_020100bc(battle);
    if (field == NULL) {
        result = 0;
    } else {
        struct Triple local = *(struct Triple*)((char*)field + 4);
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj, (float)local.x[0] / 4096.0f);
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj + 8, (float)local.x[1] / 4096.0f);
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj + 0x10, (float)local.x[2] / 4096.0f);
        result = 1;
    }
    return result;
}
