#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x, y, z; };
struct Vector3i;
extern "C" void __clear(void* ptr, int size);

struct IntField0x68_020377bc { char unk[0x68]; int field; };

struct Obj020a2be8 {
    char pad0[0x10];
    struct Vec3 vec10;
    char pad1[0x21c - 0x1c];
    short field21c;
    char pad2[0x22c - 0x21e];
    struct Vec3 vec22c;
    char pad3[0x245 - 0x238];
    unsigned char field245;
};

// USA: func_020a2be8  (semantic: UpdateCombatantOffsetVec020a2be8)
extern "C" ARM void func_020a2be8(struct Obj020a2be8* obj) {
    GameState* battle = GameState::GetInstance();
    struct Vec3 v;
    __clear(&v, 0xc);
    GameObject* c = battle->GetGameObjectByIndex(obj->field21c);
    if (c != 0) {
        *(Vector3i*)((int*)&v) = *(Vector3i const*)((int*)((char*)c + 0x44));
        int val = ((Object3D*)((struct IntField0x68_020377bc*)c))->GetHeight();
        v.y = v.y + (val >> 1);
    }
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&obj->vec10, (const Vector3fix*)&v, (Vector3fix*)&diff);
    *(Vector3i*)((int*)&obj->vec22c) = *(Vector3i const*)((int*)&diff);
    obj->field245 |= 0x11;
}
