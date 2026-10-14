#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" struct Vec3 func_02034104(GameObject* combatant);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct S02037418;

struct U16Field0x6_020375f8;

extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c9400(int a, int b, int c, struct Vec3 v, struct Vec3 w, int d);

struct Entity02078754 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x3e];
    struct Vec3 f44;
    struct Vec3 f50;
    char pad5c[0x56];
    short fb2;
    char padb4[0x166 - 0xb4];
    unsigned short f166;
    char pad168[0x12];
    unsigned char f17a;
};

// USA: func_02078754
extern "C" ARM int func_02078754(struct Entity02078754* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetMaybeWanderingMonsterByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }

    struct Vec3 posCopy = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    SetVecYByMode02033834((struct Obj02033834*)self, angle);

    self->fb2 = 0;
    SetByteIfChanged02033b68((struct Obj02033b68*)self, 0);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    ((Object3D*)((struct S02037418*)self))->SetInheritedAlpha(0x1f);
    self->f17a = 0;

    void* g = func_0202ae18();
    if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06();
        int f2val = self->f2;
        struct Vec3* p44 = &self->f44;
        struct Vec3* p50 = &self->f50;
        int rem = (self->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            func_ov017_021c9400(c1, rem, f2val, *p44, *p50, -1);
        }
    }
    return 1;
}
