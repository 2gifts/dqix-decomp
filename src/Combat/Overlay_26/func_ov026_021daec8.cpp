#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Obj02049b54;
struct Obj02033874;
struct S_10088;

struct BattleState {
    char pad0[0x8e20];
    int turns;
};

struct BattleView {
    char pad0[0x240];
    Vector3fix center;
};

struct Triple02049b54 {
    Vector3fix v;
};

int GetWord0x0(int* obj);
GameObject* GetCombatantWithFlag0x400(GameState* gs, int id);
extern "C" Triple02049b54 _Z20GetSubTriple02049b54P11Obj02049b54(Obj02049b54* obj);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874* obj, int angle);
void SetSubstructField0x8ClearFlag0x2(unsigned char* obj, int* rot);
int IsFlag10088Set(S_10088* obj);

extern "C" {
void __clear(void* dst, int size);
int func_ov000_0215eb1c(BattleState*, short*, int, int);
void func_0203232c(int*, int);
}

// USA: func_ov026_021daec8
extern "C" ARM void func_ov026_021daec8(BattleState* battle, BattleView* view, int animate) {
    short ids[8];
    GameState* gs = GameState::GetInstance();
    GetWord0x0((int*)gs);

    int count = func_ov000_0215eb1c(battle, ids, 8, 0);
    int n = 0;
    Vector3fix center = view->center;
    int order[8];
    int centerZ = center.z;

    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantWithFlag0x400(gs, ids[i]);
        if (member != NULL) {
            Vector3fix target;
            __clear(&target, sizeof(target));
            target.z = centerZ;

            Vector3fix pos = _Z20GetSubTriple02049b54P11Obj02049b54((Obj02049b54*)member).v;
            pos.y = 0;

            Vector3fix dir;
            Vector3fix_Subtract(&target, &pos, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            fix32_t angle = fix32_Atan2(dir.x, dir.z);
            _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)member, angle);

            Vector3fix rot;
            __clear(&rot, sizeof(rot));
            rot.y = angle;
            SetSubstructField0x8ClearFlag0x2((unsigned char*)member, &rot.x);

            order[n++] = ids[i];
        }
    }

    if (animate && battle->turns > 0) {
        func_0203232c(order, n);
        for (int i = 0; i < n; i++) {
            GameObject* member = GetCombatantWithFlag0x400(gs, order[i]);
            if (member != NULL && !member->obj3D_.IsTransitioningAnimations() && !IsFlag10088Set((S_10088*)member)) {
                member->obj3D_.SetNormalizedAnimationTime(0x1000 / n * i);
                member->obj3D_.AdvanceAnimations();
            }
        }
    }
}
