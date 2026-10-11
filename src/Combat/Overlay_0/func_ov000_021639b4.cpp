#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" void func_ov017_021917f0(int id, int flag);

struct Obj021639b4 {
#if defined(jpn)
    char pad[0x218];
#else
    char pad[0x29c];
#endif
    int field29c;
};

// USA: func_ov000_021639b4
extern "C" ARM void func_ov000_021639b4(struct Obj021639b4* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[4];
    int n = func_ov000_0215e9fc(obj->field29c, buf, 4, 0);
    for (int i = 0; i < n; i++) {
        GameObject* c = bs->GetGameObjectByIndex(buf[i] * 12 + 0x1c);
        if (c && *(signed short*)((char*)c + 2) >= 0) {
            _ZN8Object3D11MakeVisibleEv((unsigned char*)c);
        }
        c = bs->GetGameObjectByIndex(buf[i] * 12 + 0x1d);
        if (c && *(signed short*)((char*)c + 2) >= 0) {
            _ZN8Object3D11MakeVisibleEv((unsigned char*)c);
        }
        func_ov017_021917f0(buf[i], 1);
    }
}
