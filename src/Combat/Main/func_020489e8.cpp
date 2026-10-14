#include <globaldefs.h>
#include "GameState/GameState.h"

ARM void Forward02048144(void* p);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Bits41_37474 {
    char unk0[0x41];
    unsigned char lo5 : 5;
    unsigned char hi3 : 3;
};

struct Obj02034a30 {
    unsigned short field0;
    unsigned short field2;
    float field4;
};

extern "C" void func_02048f64(void* obj);
extern "C" void func_0204956c(void* obj);

struct Obj0204a054;
void ApplyCountdownOrDispatch0204a054(struct Obj0204a054* obj);

struct Sub0204a054Ext_020489e8 {
    char pad0[0x10];
    int vec[3];
    char pad1[0x20 - 0x1c];
    int flags;
};

struct Obj020489e8 {
    char pad0[0x44];
    int vecSrc[3];
    char pad1[0x54 - 0x50];
    int field0x54;
    char pad2[0x13c - 0x58];
    struct Sub0204a054Ext_020489e8* field13c;
};

// USA: func_020489e8
extern "C" ARM void func_020489e8(struct Obj020489e8* obj) {
    Forward02048144(obj);
    if (obj->field13c == NULL) return;
    if (obj->field13c->flags & 1) {
        _ZN8Vector3iaSERKS_(obj->field13c->vec, obj->vecSrc);
        obj->field13c->vec[1] = obj->field0x54;
    }
    int isNonzero = 0.0f != ((struct Obj02034a30*)((char*)obj->field13c + 0x60))->field4;
    if (isNonzero) {
        GameState* battleStruct = GameState::GetInstance();
        int threshold = battleStruct->GetEffectiveDeltaTime();
        int bits = ((Object3D*)((struct Bits41_37474*)obj))->GetOwnAlpha();
        ((AlphaTween*)(&((struct Obj02034a30*)((char*)obj->field13c + 0x60))->field0))->SetCurrentValue((float)bits);
        float result = ((AlphaTween*)((struct Obj02034a30*)((char*)obj->field13c + 0x60)))->Advance(threshold);
        unsigned char v = (unsigned char)(int)result;
        ((struct Bits41_37474*)obj)->lo5 = v;
    }
    func_02048f64(obj);
    func_0204956c(obj);
    ApplyCountdownOrDispatch0204a054((struct Obj0204a054*)obj);
}
