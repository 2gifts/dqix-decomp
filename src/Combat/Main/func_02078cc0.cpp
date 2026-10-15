#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" struct Vec3 func_02034104(GameObject* combatant);
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);

struct ShortPair0xba0xbc;
void SetFields0xbaAnd0xbc_02032fd0(ShortPair0xba0xbc* obj, short a, unsigned short b);

struct Entity02078cc0 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad50[0xb0 - 0x50];
    unsigned short fb0;
    unsigned short fb2;
    char padb4[0x166 - 0xb4];
    unsigned short f166;
    char pad168[0x17a - 0x168];
    unsigned char f17a;
};

// USA: func_02078cc0  (semantic: AimAtFlagTargetOrReset_02078cc0)
extern "C" ARM int func_02078cc0(struct Entity02078cc0* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }
    SetByteSavingPrevious((struct Foo02033b58*)self, 0);
    self->fb0 = 0x328;
    self->fb2 = 0;
    struct Vec3 posCopy = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    SetVecYByMode02033834((struct Obj02033834*)self, angle);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    SetFields0xbaAnd0xbc_02032fd0((struct ShortPair0xba0xbc*)self, 0xcc, 0xaf0);
    self->f17a = 0;
    return 1;
}
