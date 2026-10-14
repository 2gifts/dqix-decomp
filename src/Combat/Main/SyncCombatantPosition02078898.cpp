#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct S02037418;

extern "C" struct Vec3 func_02034104(void* combatant);
extern "C" int fix32_Atan2(int x, int z);

extern char data_02108760;

struct Entity02078898 {
    char pad0[0x6];
    unsigned short field6;
    char pad1[0x44 - 0x8];
    struct Vec3 vecField44;
    char pad2[0xb2 - 0x50];
    unsigned short fieldB2;
    char pad3[0x166 - 0xb4];
    unsigned short combatantIdField;
    char pad4[0x17c - 0x168];
    unsigned char field17c;
};

#if defined(jpn)
enum { PositionContextOffset = 0x524 };
#else
enum { PositionContextOffset = 0x734 };
#endif

// USA: func_02078898
ARM int SyncCombatantPosition02078898(struct Entity02078898* p) {
    GameState* bs = GameState::GetInstance();
    unsigned short id = p->combatantIdField;
    GameObject* combatant = bs->GetMaybeWanderingMonsterByIndex(id);
    if (combatant == 0) return 0;

    void* ov = func_ov017_0218b5b0();
    char* g = (char*)ov + 0x3000;
    void* g734 = *(void**)(g + PositionContextOffset);

    GameObject* other = bs->GetProtagonist();
    unsigned short a = ((Object3D*)((struct U16Field0x6_020375f8*)other))->GetField06();
    unsigned short b = ((Object3D*)((struct U16Field0x6_020375f8*)p))->GetField06();
    if (a == b && *((unsigned char*)g734 + 3) == 0) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 6, 0);
    }

    struct Vec3 pos = func_02034104(combatant);
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&pos, (const Vector3fix*)&p->vecField44, (Vector3fix*)&diff);
    Vector3fix_Normalize((const Vector3fix*)&diff, (Vector3fix*)&diff);
    int angle = fix32_Atan2(diff.x, diff.z);
    SetVecYByMode02033834((struct Obj02033834*)p, angle);

    p->fieldB2 = 0;
    SetByteIfChanged02033b68((struct Obj02033b68*)p, 0);
    ((Object3D*)((unsigned char*)p))->DisableFlag(0x80);
    ((Object3D*)((struct S02037418*)p))->SetInheritedAlpha(0x1f);
    p->field17c = 0;
    return 1;
}
