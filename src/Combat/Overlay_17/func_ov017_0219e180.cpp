#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2 : 2;
    unsigned short : 14;
};
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" GameObject* _Z30FindCombatantByField2_021a2738Pvi(void* unused, int value);

// USA: func_ov017_0219e180
extern "C" ARM void func_ov017_0219e180(void* param, int id) {
    GameState* bs = GameState::GetInstance();
    struct Entry_02028bd0* table = GetEntryTableBase();
    void* search = func_0202ae18();
    if (CheckField0NonZero((int*)search) != 0) {
        if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) {
            return;
        }
    }
    struct Entry_02028bd0* entry = FindInlineEntryById(table, id);
    if (entry == NULL) {
        return;
    }
    int group = entry->field2;
    for (int i = 0; i < 0xc; i++) {
        GameObject* monster = bs->GetMaybeFieldMonsterByIndex(group * 0xc + 0x70 + i);
        if (monster == NULL) {
            continue;
        }
        GameObject* found = _Z30FindCombatantByField2_021a2738Pvi(param, *(short*)((char*)monster + 2));
        if (found == NULL) {
            continue;
        }
        found->obj3D_.ShallowCloneModelAndAnimationsTo(&monster->obj3D_);
    }
}
