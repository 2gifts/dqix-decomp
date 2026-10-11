#include <globaldefs.h>
#if defined(jpn)
enum { kFieldOffset = 0x1b4 };
#else
enum { kFieldOffset = 0x1c0 };
#endif
#include "GameState/GameState.h"

extern "C" void _ZN7Model3D14RemoveTexturesEv(void*);
extern "C" void _ZN7Model3D22ApplyTexturesFromModelEPS_(void*, void*);

struct Obj02054028 {
    char pad0[4];
    short f4;
    char pad6[kFieldOffset - 6];
    unsigned short f1c0;
};

// USA: func_02054028
extern "C" ARM void func_02054028(struct Obj02054028* obj, int n) {
    obj->f1c0 = n;
    GameState* bs = GameState::GetInstance();
    short m = obj->f4;
    int base = m * 0xc;
    int ids[5];
    ids[0] = m;
    ids[1] = base + 0x13;
    ids[2] = base + 0x14;
    ids[3] = base + 0x15;
    ids[4] = base + 0x1b;
    if (obj->f1c0 != 0) {
        for (int i = 0; i < 5; i++) {
            GameObject* c = bs->GetGameObjectByIndex(ids[i]);
            if (c != 0 && c->obj3D_.pModel_ != 0) {
                _ZN7Model3D14RemoveTexturesEv(c->obj3D_.pModel_);
            }
        }
    } else {
        GameObject* src[5] = {0};
        src[0] = bs->GetGameObjectByIndex(m * 0xc + 0x17);
        src[1] = bs->GetGameObjectByIndex(m * 0xc + 0x19);
        src[3] = bs->GetGameObjectByIndex(m * 0xc + 0x16);
        for (int i = 0; i < 5; i++) {
            GameObject* c = bs->GetGameObjectByIndex(ids[i]);
            if (c != 0 && c->obj3D_.pModel_ != 0) {
                Model3D* p = c->obj3D_.pModel_;
                GameObject* s = src[i];
                if (s != 0 && s->obj3D_.pModel_ != 0) {
                    _ZN7Model3D22ApplyTexturesFromModelEPS_(p, s->obj3D_.pModel_);
                }
                _ZN7Model3D22ApplyTexturesFromModelEPS_(p, p);
            }
        }
    }
}