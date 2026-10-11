// JPN: func_ov017_021cf388
#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset160 = 0x154, RegionOffset16c = 0x160 };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset160 = 0x160, RegionOffset16c = 0x16c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct HeadNode02046b24 { signed char id; };
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);

void* GetPtrField0x2a04(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Obj02033834;
struct Obj02033874;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

extern "C" void __clear(void* buf, int n);

struct Info021ceee0 {
    char pad4[4];
    int vec[3];
    short field10;
    unsigned char field12;
    unsigned char field13;
};

// USA: func_ov017_021ceee0  (semantic: SyncOrAimCombatantByHeadState_021ceee0)
extern "C" ARM void func_ov017_021ceee0(void* unused0, struct Info021ceee0* info, GameState* battle, char* obj) {
    GameObject* held;
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(obj + 0x3000 + RegionOffset6fc);
    held = battle->GetMaybeWanderingMonsterByIndex(info->field12);
    if (ArrayContainsByte((struct ArrayContainsByteStruct*)GetPtrField0x2a04(battle), info->field12)) {
        return;
    }
    if (!held) {
        return;
    }
    if (GetHeadNodeIdOrMinusOne(list) == 0xa) {
        int withinRange = info->field12 <= 3;
        if (!withinRange) {
            return;
        }
        if (!(*(unsigned short*)held & 0x80)) {
            return;
        }
        GameObject* target = GetCombatantWithFlag0x100(battle, info->field12);
        if (!target) {
            return;
        }
        int buf[3];
        __clear(buf, 0xc);
        buf[1] = info->field10;
        _ZN8Vector3iaSERKS_((int*)((char*)target + RegionOffset160), info->vec);
        _ZN8Vector3iaSERKS_((int*)((char*)target + RegionOffset16c), buf);
        return;
    }
    if (GetHeadNodeIdOrMinusOne(list) == 4) {
        return;
    }
    _ZN8Vector3iaSERKS_((int*)((char*)held + 0x44), info->vec);
    if (info->field13 == 0) {
        SetVecYByMode02033834((struct Obj02033834*)held, info->field10);
    } else {
        SetVecYFromValue02033874((struct Obj02033874*)held, info->field10);
    }
}
