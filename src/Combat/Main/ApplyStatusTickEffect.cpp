#include <globaldefs.h>
#if defined(jpn)
enum { kFlagOffset = 0x1c2 };
#else
enum { kFlagOffset = 0x1ce };
#endif

#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct Struct020372b8;
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);

struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);

struct Obj02039df4 {
    char pad0[4];
    short combatantId;
    char pad6[0xc2 - 6];
    unsigned char lo0xc2 : 5;
    unsigned char flagBit0xc2 : 1;
    unsigned char hi0xc2 : 2;
    char padc3[kFlagOffset - 0xc3];
    unsigned char flags1ce;
};

// USA: func_02039df4
ARM void ApplyStatusTickEffect(struct Obj02039df4* obj) {
    int q;
    GameObject* combatant;

    if (obj->flagBit0xc2) return;
    combatant = GetCombatantWithFlag0x1000(GameState::GetInstance(), obj->combatantId);
    if (combatant == NULL) return;
    q = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)obj) / 100;
    if (q != 0x2b && q != 0x2d && q != 0x40 && q != 0x29) return;
    obj->flags1ce |= 4;
    _ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)obj, 0, 0);
    _ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)obj, 0);
}
