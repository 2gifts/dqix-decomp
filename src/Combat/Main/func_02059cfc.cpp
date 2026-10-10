#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);

extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* obj);

struct BitFlags02037170;
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(struct BitFlags02037170* obj);

void InitStruct02059cc8(unsigned char* obj);
void ClearCombatantSlot(GameState* battleStruct, int id);

struct ListNode02057854;
int CheckListStableAndField8LtField402057854(struct ListNode02057854* node);

int ForwardField4To02057334(int* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern "C" unsigned char* _Z17GetPointerAt0x32cP20PointerField32c_ffc0(GameState* obj);
extern "C" unsigned char* _Z17GetPointerAt0x330P20PointerField330_ffd0(GameState* obj);

extern int data_02108760;

struct CombatantFlags02059cfc {
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
};

struct Combatant02059cfc {
    char pad0[0x4];
    struct ListNode02057854* listNode;
    char pad8[0x11];
    unsigned char field19;
    char pad1a[0xa];
    int field24;
    int field28;
    char pad2c[0x18];
    struct Vec3 pos;
    char pad50[0x5c];
    int field_ac;
    short timerB0;
    char padb2[0x4];
    short timerB6;
    int field_b8;
    int field_bc;
    struct Vec3 vecC0;
    struct CombatantFlags02059cfc flags;
};

// USA: func_02059cfc
extern "C" ARM void func_02059cfc(unsigned char* p, int dt, int id) {
    struct Combatant02059cfc* c = (struct Combatant02059cfc*)p;
    GameState* bs = GameState::GetInstance();

    if (c->timerB0 > 0) {
        c->timerB0 -= dt;
        return;
    }

    if (c->field_ac == 0) {
        if (bs->GetGameObjectByIndex(id) == 0) {
            return;
        }

        if (c->field_b8 > 0) {
            int f28 = c->field28;
            int fbc = c->field_bc;
            if (f28 <= fbc) {
                int f24 = c->field24;
                if (fbc < f24) {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, c->field_b8, 0);
                }
            }
        }

        struct Vec3 pos = c->pos;

        int r5 = 0;
        if (c->flags.bit4) {
            unsigned char* q = _Z17GetPointerAt0x32cP20PointerField32c_ffc0(bs);
            if (q != 0) {
                r5 = *(int*)(q + 0x130);
            }
        } else if (c->flags.bit5) {
            unsigned char* q = _Z17GetPointerAt0x330P20PointerField330_ffd0(bs);
            if (q != 0) {
                r5 = *(int*)(q + 0x130);
            }
        }

        if (c->flags.bit4 || c->flags.bit5) {
            if ((r5 & 1) && pos.x > 0) {
                pos.x -= 0x120000;
            } else if ((r5 & 2) && pos.x < 0) {
                pos.x += 0x120000;
            }
            if ((r5 & 4) && pos.z > 0) {
                pos.z -= 0xe0000;
            } else if ((r5 & 8) && pos.z < 0) {
                pos.z += 0xe0000;
            }
        }

        struct Vec3 vel;
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((struct Vec3Fixed02030e2c*)&c->vecC0, dt << 12, (struct Vec3Fixed02030e2c*)&vel);
        Vector3fix_Add((const Vector3fix*)&pos, (const Vector3fix*)&vel, (Vector3fix*)&pos);
        CopyVec3ToField0x44((struct Target02059f38*)c, (struct Vec3_02059f38*)&pos);

        _ZN8Object3D14AdvanceEffectsEv(c);

        if (c->field19 & 1) {
            if (_ZNK8Object3D19HasAnimationStoppedEv((struct BitFlags02037170*)c)) {
                ClearCombatantSlot(bs, id);
                InitStruct02059cc8(p);
            }
        }

        if (c->timerB6 > 0) {
            c->timerB6 -= dt;
            if (c->timerB6 <= 0) {
                ClearCombatantSlot(bs, id);
                InitStruct02059cc8(p);
            }
        }
    } else {
        if (bs->GetGameObjectByIndex(id) == 0) {
            return;
        }
        if (CheckListStableAndField8LtField402057854(c->listNode) == 1) {
            ClearCombatantSlot(bs, id);
            InitStruct02059cc8(p);
        } else {
            ForwardField4To02057334((int*)p);
        }
    }
}
