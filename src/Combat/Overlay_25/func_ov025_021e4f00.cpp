#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct S0204a5d4;
int GetFlags(int obj);
extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
void SetField0x260(struct S0204a5d4* p, int v);
extern "C" void _Z22SetFlagOrState0216d530Pvi(void* obj, int val);

struct Param021e4f00 {
    char pad[8];
    unsigned char targetIndex;
};

// USA: func_ov025_021e4f00
extern "C" ARM int func_ov025_021e4f00(struct Param021e4f00* p, int b, int unused, void* d) {
    int targetIds[8];
    int cameraIds[8];
    void* obj = GetField0x3b0Value(GameState::GetInstance());
    if (obj != 0) {
        if (GetFlags((int)obj) & 0x10) {
            if (_Z23DispatchByIndex021820bcPviii(d, b, p->targetIndex, (int)targetIds) != 1) {
                SetField0x260((struct S0204a5d4*)obj, -1);
                return 1;
            }
            SetField0x260((struct S0204a5d4*)obj, targetIds[0]);
        } else if (GetFlags((int)obj) & 8) {
            if (_Z23DispatchByIndex021820bcPviii(d, b, p->targetIndex, (int)cameraIds) != 1) {
                _Z22SetFlagOrState0216d530Pvi(obj, -1);
                return 1;
            }
            _Z22SetFlagOrState0216d530Pvi(obj, cameraIds[0]);
        }
    }
    return 1;
}
