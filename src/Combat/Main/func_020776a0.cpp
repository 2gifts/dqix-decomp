#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" struct Vec3 func_020341e0(void* obj);
extern "C" struct Vec3 func_02034104(void* obj);

struct Obj02033834;
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int newVal);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

struct Entity020776a0 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad44[0xb0 - 0x50];
    unsigned short fb0;
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x166 - 0xb6];
    unsigned short f166;
    char pad168[0x17a - 0x168];
    unsigned char f17a;
    char pad17b[0x17d - 0x17b];
    unsigned char f17d;
};

// USA: func_020776a0
extern "C" ARM int func_020776a0(struct Entity020776a0* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }

    self->f17d |= 0x40;
#if defined(jpn)
    struct Vec3 posCopy = func_02034104(combatant);
#else
    struct Vec3 posCopy = func_020341e0(combatant);
#endif
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, angle);

    self->fb0 = 0x97;
    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);

    GameObject* protagonist = battleStruct->GetProtagonist();
    unsigned short a = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)protagonist);
    unsigned short b = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self);
    if (a == b) {
        _ZN8Object3D11DisableFlagEi((unsigned char*)self, 0x80);
    }
    self->f17a = 0;
    return 1;
}
