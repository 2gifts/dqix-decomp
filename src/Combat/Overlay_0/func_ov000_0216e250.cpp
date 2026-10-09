#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

extern "C" void __clear(void* dst, int size);
extern "C" void func_ov000_0216d370(void* obj, int flagA, int flagB, int flagC);
extern "C" void Vector3fix_Add(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);

struct Triple0216e250 {
    int x, y, z;
};
struct Obj02049b54;
extern "C" struct Triple0216e250 _Z20GetSubTriple02049b54P11Obj02049b54(struct Obj02049b54* obj);
void ApplyVec3Tail(void* obj, int* vec);

extern int data_ov000_0218323c[];
extern int data_ov000_02183244[];
extern int data_ov000_0218324c[];
extern int data_ov000_02183254[];

struct Obj0216e250 {
    char pad0[0x10];
    Vector3i position;
    char pad1c[0x21c - 0x1c];
    struct Random* random;
    char pad220[0x238 - 0x220];
    int field238;
};

// USA: func_ov000_0216e250
extern "C" ARM void func_ov000_0216e250(struct Obj0216e250* obj, int* ids, int count) {
    if (count <= 0) return;

    func_ov000_0216d370(obj, 1, 1, 1);
    GameState* gs = GameState::GetInstance();
    Vector3i center;
    __clear(&center, sizeof(center));
    for (int i = 0; i < count; i++) {
        GameObject* c = gs->GetCombatantByIndex(ids[i]);
        if (c != NULL) {
            struct Triple0216e250 pos = _Z20GetSubTriple02049b54P11Obj02049b54((struct Obj02049b54*)c);
            Vector3fix_Add(&center, (Vector3fix*)&pos, &center);
        }
    }
    Vector3fixMultiplyScalar(&center, (int)(4096.0f * (1.0f / (float)count)), &center);
    center.y += 0x18cc;

    int flag = 0;
    if (gs->GetCombatantByIndex(ids[0])->obj3D_.unknown_0_ & 0x400) flag = 1;
    int a;
    int b;
    if (flag == 0) {
        int k = NextRandomMax(obj->random, 2);
        a = data_ov000_02183244[k];
        b = data_ov000_0218324c[k];
    } else {
        int k = NextRandomMax(obj->random, 2);
        a = data_ov000_02183254[k];
        b = data_ov000_0218323c[k];
    }
    int vec[3];
    vec[0] = a;
    vec[1] = 0;
    vec[2] = 0x9000;
    obj->position = center;
    ApplyVec3Tail(obj, vec);
    obj->field238 = b;
}
