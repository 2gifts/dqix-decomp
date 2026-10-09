#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* obj, int flagA, int flagB, int flagC);
extern "C" void func_ov000_0216d234(void* forward, void* position, void* dest);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
void CopyBlockToField0xf0(struct Dst0202ecc8* dst, struct Block0202ecc8* src);
void SetFlag0x1At0x168(unsigned char* obj);
void ApplyVec3Tail(void* obj, int* vec);

extern Vector3i data_ov000_02183274;

struct Obj0216da34 {
    char pad0[0x10];
    Vector3i field10;
    char pad1c[0x21c - 0x1c];
    struct Random* random;
    char pad220[0x23c - 0x220];
    int field23c;
};

// USA: func_ov000_0216da34
extern "C" ARM void func_ov000_0216da34(struct Obj0216da34* obj, int idxA, int idxB) {
    GameState* gs = GameState::GetInstance();
    GameObject* a = gs->GetCombatantByIndex(idxA);
    GameObject* b = gs->GetCombatantByIndex(idxB);
    if (a == NULL || b == NULL) {
        return;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Vector3fix posA = a->obj3D_.position_;
    Vector3fix posB = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix center;
    if (idxA != idxB) {
        Vector3fix_Subtract(&posB, &posA, &dir);
        Vector3fix_Normalize(&dir, &dir);
        Vector3fix_Add(&posB, &posA, &center);
        Vector3fixMultiplyScalar(&center, 0x800, &center);
    } else {
        fix32_t angle = a->obj3D_.rotation_.y;
        fix32_t c = fix32cos(angle);
        dir.x = fix32sin(angle);
        dir.y = 0;
        dir.z = c;
        center = posA;
    }
    struct Block0202ecc8 block;
    func_ov000_0216d234(&dir, &center, &block);
    CopyBlockToField0xf0((struct Dst0202ecc8*)obj, &block);
    SetFlag0x1At0x168((unsigned char*)obj);
    Vector3i v = data_ov000_02183274;
    int base;
    struct Random* random = obj->random;
    base = 0;
    if (NextRandomMax(random, 2) == 0) {
        base = 0x3244;
    }
    int angle;
    if (NextRandomMax(random, 2) == 0) {
        angle = fix32ReduceAngle0To2Pi(base + 0x4cc);
    } else {
        angle = fix32ReduceAngle0To2Pi(base - 0x4cc);
    }
    int tail[3];
    tail[0] = angle;
    tail[1] = 0x1000;
    tail[2] = 0x8000;
    obj->field10 = v;
    ApplyVec3Tail(obj, tail);
    obj->field23c = -20;
}
