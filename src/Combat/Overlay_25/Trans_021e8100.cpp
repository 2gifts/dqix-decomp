#include <globaldefs.h>
#include "GameState/GameState.h"

struct Param021e8100 {
    char pad[0x8];
    unsigned short duration;
    short strength;
};

extern "C" unsigned char* _Z18GetField0x3b0ValueP9GameState(GameState* gs);
extern "C" void _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(unsigned char* obj, int a, int b);

// USA: func_ov025_021e8100  (semantic: Trans_021e8100)
extern "C" ARM int func_ov025_021e8100(Param021e8100* p) {
    unsigned char* camera = _Z18GetField0x3b0ValueP9GameState(GameState::GetInstance());
    if (camera != 0) {
        _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(camera, p->strength, p->duration);
    }
    return 1;
}
