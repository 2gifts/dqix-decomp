#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

extern "C" void func_ov000_0216d370(void* obj, int flagA, int flagB, int flagC);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
void CopyBlockToField0xf0(struct Dst0202ecc8* dst, struct Block0202ecc8* src);
void ApplyVec3Tail(void* obj, int* vec);

extern "C" void func_ov000_0216d234(void* forward, void* position, void* dest);

extern Vector3i data_ov000_0218328c;

struct Obj0216de00 {
    char pad0[0x10];
    Vector3i field10;
};

// USA: func_ov000_0216de00
extern "C" ARM void func_ov000_0216de00(struct Obj0216de00* obj, int idxA, int idxB) {
    GameState* gs = GameState::GetInstance();
    GameObject* a = gs->GetGameObjectByIndex(idxA);
    GameObject* b = gs->GetGameObjectByIndex(idxB);
    if (a == NULL || b == NULL) {
        return;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Vector3fix posA = a->obj3D_.position_;
    Vector3fix posB = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix_Subtract(&posA, &posB, &dir);
    Vector3fix_Normalize(&dir, &dir);
    struct Block0202ecc8 block;
    func_ov000_0216d234(&dir, &posB, &block);
    CopyBlockToField0xf0((struct Dst0202ecc8*)obj, &block);
    Vector3i v = data_ov000_0218328c;
    int tail[3];
    tail[0] = 0x3244;
    tail[1] = 0;
    tail[2] = 0x1000;
    obj->field10 = v;
    ApplyVec3Tail(obj, tail);
}
