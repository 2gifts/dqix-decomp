#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
struct Obj02049f50;
void SetField41AndScaleSub02049f50(struct Obj02049f50* obj, int val, int count);

struct GatherObj02163a7c {
#if defined(jpn)
    char pad[0x218];
#else
    char pad[0x29c];
#endif
    int field29c;
};

// USA: func_ov000_02163a7c
ARM void ApplyField41ToGatheredCombatants02163a7c(struct GatherObj02163a7c* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->field29c, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->field29c, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; p++, i++) {
        GameObject* c = bs->GetCombatantByIndex(*p);
        if (c) {
            SetField41AndScaleSub02049f50((struct Obj02049f50*)c, 0x1f, 0);
        }
    }
}
