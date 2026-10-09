#include <globaldefs.h>
#include "GameState/GameState.h"

struct Param021e56e8 {
    char pad0[8];
    unsigned char index;
    unsigned char mode;
    char padA[2];
    int scale;
};

extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
extern "C" void _Z22SetThreeWords_021e4448Piiii(int* obj, int a, int b, int c);
void* GetActiveCombatWork(void);
extern "C" void* func_ov000_02160f14(void* work);
int GetField0x78(void* obj);

extern Vector3fix data_ov025_021eef24;

// USA: func_ov025_021e56e8
extern "C" ARM int func_ov025_021e56e8(struct Param021e56e8* p, int b, int unused, void* c) {
    GameState* gs = GameState::GetInstance();
    int ids[8];
    int count = _Z23DispatchByIndex021820bcPviii(c, b, p->index, (int)ids);
    Vector3fix scale = data_ov025_021eef24;
    if (p->mode == 0) {
        _Z22SetThreeWords_021e4448Piiii((int*)&scale, 0x10a, 0x10a, 0x10a);
    } else if (p->mode == 2) {
        void* field = func_ov000_02160f14(GetActiveCombatWork());
        float y0 = 0.065f;
        float y1 = 0.08f;
        float x0 = 6.5f;
        float x1 = 7.0f;
        float zoom = GetField0x78(field) / 4096.0f;
        float s = zoom * ((y1 - y0) / (x1 - x0)) + (x1 * y0 - x0 * y1) / (x1 - x0);
        if (s < 0.065f) {
            s = 0.065f;
        }
        int v = 4096.0f * s;
        _Z22SetThreeWords_021e4448Piiii((int*)&scale, v, v, v);
    } else if (p->mode == 3) {
        _Z22SetThreeWords_021e4448Piiii((int*)&scale, p->scale, p->scale, p->scale);
    }
    for (int i = 0; i < count; i++) {
        GameObject* obj = gs->GetGameObjectByIndex(ids[0]);
        if (obj != NULL) {
            obj->obj3D_.SetScale(&scale);
        }
    }
    return 1;
}
