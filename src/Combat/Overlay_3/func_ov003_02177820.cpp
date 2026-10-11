#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1030 = 0xfac };
enum { kRegion101c = 0xf98 };
enum { kRegion89c = 0x818 };
#else
enum { kRegion1030 = 0x1030 };
enum { kRegion101c = 0x101c };
enum { kRegion89c = 0x89c };
#endif

#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void ClearSublistEntriesFlag1(void* obj, int id);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_020813ec(void* obj, int key);
void* GetPtrField0x2a04(GameState* battleStruct);

// JPN: func_ov003_021767d0
// USA: func_ov003_02177820  (semantic: RecomputeElementTierAndDispatchAll_02177820)
#pragma opt_common_subs off
extern "C" ARM void func_ov003_02177820(char* self) {
    struct Obj2081* elemObj = *(struct Obj2081**)(self + kRegion89c);
    GameState* battle = GameState::GetInstance();
    GetPtrField0x2a04(battle);

    int field = *(int*)(self + kRegion1030);
    int a = 0x11, b = 0x79;
    switch (field) {
    case 2: a = 0x12; b = 0x7c; break;
    case 3: a = 0x13; b = 0x80; break;
    case 4: a = 0x14; b = 0x85; break;
    }

    ClearElementFlag0x20(elemObj, a);
    SetEntryLowNibbleAndElement02080c68(elemObj, a, 0);
    ClearSublistEntriesFlag1(elemObj, a);

    int hp;
    unsigned char i;
    for (i = 0; i < *(int*)(self + kRegion1030); i++) {
        hp = 0;
        GameObject* combatant = battle->GetPartyMemberByIndex(*(int*)(self + kRegion101c + i * 4));
        if (combatant != 0) {
            hp = *(int*)((char*)combatant + 0x134);
        }
        SetEntryFirstField02080f8c((struct Container02080f8c*)elemObj, b, hp);

        int tier = func_020dcc98((signed char)*(int*)(self + kRegion101c + i * 4));
        SetEntryHighNibble0x13((struct Container02080cc0*)elemObj, b, tier);

        b = (short)(b + 1);
    }

    func_020813ec(elemObj, a);
}
