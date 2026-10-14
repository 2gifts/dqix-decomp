#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);

struct BitFlags02037170;

void InitStruct02059cc8(unsigned char* obj);

struct ListNode02057854;
int CheckListStableAndField8LtField402057854(struct ListNode02057854* node);

int ForwardField4To02057334(int* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern int data_02108760;

// USA: func_0205a020
ARM void AdvanceActorCooldownsAndPosition0205a020(unsigned char* p, int dt) {
    GameState::GetInstance();

    short* timerB0 = (short*)(p + 0xb0);
    if (*timerB0 > 0) {
        *timerB0 -= dt;
        return;
    }

    if (*(int*)(p + 0xac) == 0) {
        if (*(int*)(p + 0xb8) > 0) {
            int f28 = *(int*)(p + 0x28);
            int fbc = *(int*)(p + 0xbc);
            if (f28 <= fbc) {
                int f24 = *(int*)(p + 0x24);
                if (fbc < f24) {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, *(int*)(p + 0xb8), 0);
                }
            }
        }

        struct PosHolder0205a020 { char pad[0x44]; struct Vec3 pos; };
        struct Vec3 pos = ((struct PosHolder0205a020*)p)->pos;

        struct Vec3 vel;
        Vector3fixMultiplyScalar((Vector3i const*)(p + 0xc0), dt << 12, (Vector3i*)&vel);
        Vector3fix_Add((const Vector3fix*)&pos, (const Vector3fix*)&vel, (Vector3fix*)&pos);
        CopyVec3ToField0x44((struct Target02059f38*)p, (struct Vec3_02059f38*)&pos);

        ((Object3D*)p)->AdvanceEffects();

        if (p[0x19] & 1) {
            if (((Object3D*)((struct BitFlags02037170*)p))->HasAnimationStopped()) {
                InitStruct02059cc8(p);
            }
        }

        short* timerB6 = (short*)(p + 0xb6);
        if (*timerB6 > 0) {
            *timerB6 -= dt;
            if (*timerB6 <= 0) {
                InitStruct02059cc8(p);
            }
        }
    } else {
        if (CheckListStableAndField8LtField402057854(*(struct ListNode02057854**)(p + 0x4)) == 1) {
            InitStruct02059cc8(p);
        } else {
            ForwardField4To02057334((int*)p);
        }
    }
}
