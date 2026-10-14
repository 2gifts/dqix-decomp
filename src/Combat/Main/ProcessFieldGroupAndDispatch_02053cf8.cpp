#include <globaldefs.h>
#include "GameState/GameState.h"

struct Buf7_02053cf8 { int v[7]; };
extern struct Buf7_02053cf8 data_020e7bfc;

struct Obj02053cf8 {
    char pad0[4];
    short f4;
};

// USA: func_02053cf8  (semantic: ProcessFieldGroupAndDispatch_02053cf8)
extern "C" ARM void func_02053cf8(struct Obj02053cf8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    ((Object3D*)obj)->UseRenderConfigDiffuseColor();
    int base = obj->f4 * 0xc;
    struct Buf7_02053cf8 ids = data_020e7bfc;
    ids.v[0] = base + 0x13;
    ids.v[1] = base + 0x14;
    ids.v[2] = base + 0x15;
    ids.v[3] = base + 0x1b;
    ids.v[4] = base + 0x1c;
    ids.v[5] = base + 0x1d;

    int* p = ids.v;
    while (*p >= 0) {
        GameObject* c = battleStruct->GetGameObjectByIndex(*p);
        if (c != 0) {
            ((Object3D*)c)->UseRenderConfigDiffuseColor();
        }
        p++;
    }
}
