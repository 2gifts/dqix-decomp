#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" struct Vec3 func_02034104(GameObject* combatant);
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct Entity02078688 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad1[0x62];
    short fb2;
    char pad2[0xb2];
    unsigned short f166;
    char pad3[0x12];
    unsigned char f17a;
};

// USA: func_02078688  (semantic: AimAtFlagTargetAndReset02078688)
extern "C" ARM int func_02078688(struct Entity02078688* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetMaybeWanderingMonsterByIndex(self->f166);
    if (combatant != 0) {
        struct Vec3 posCopy = func_02034104(combatant);
        struct Vec3 delta;
        Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        int angle = fix32_Atan2(delta.x, delta.z);
        SetVecYByMode02033834((struct Obj02033834*)self, angle);
    }

    self->fb2 = 0;
    SetByteIfChanged02033b68((struct Obj02033b68*)self, 2);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    self->f17a = 0;
    return 1;
}
