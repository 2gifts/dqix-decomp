#include <globaldefs.h>
#include "GameState/GameState.h"

struct Param021e8100 {
    char pad[0x8];
    unsigned short duration;
    short strength;
};

unsigned char* GetField0x3b0Value_020100bc(GameState* gs);
void StoreFields0x1e4And0x1e8IfNonZero_0202ea10(unsigned char* obj, int a, int b);

// USA: func_ov025_021e8100  (semantic: Trans_021e8100)
extern "C" ARM int func_ov025_021e8100(Param021e8100* p) {
    unsigned char* camera = GetField0x3b0Value_020100bc(GameState::GetInstance());
    if (camera != 0) {
        StoreFields0x1e4And0x1e8IfNonZero_0202ea10(camera, p->strength, p->duration);
    }
    return 1;
}
