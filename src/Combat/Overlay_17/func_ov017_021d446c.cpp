#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase_02027ca4(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2 : 2;
};

struct Src021d446c {
    unsigned short field0;
    unsigned char pad2;
    unsigned char field3 : 4;
};

struct Out021d446c {
    int field0;
    Entry_02028bd0* field4;
    GameObject* field8;
};

// USA: func_ov017_021d446c
extern "C" ARM int func_ov017_021d446c(Src021d446c* p0, Out021d446c* out, int p2) {
    GameState* bs = GameState::GetInstance();
    void* tbl = func_02012fe4();
    struct Entry_02028bd0* entryBase = GetEntryTableBase_02027ca4();

    if (p0->field0 != *(unsigned short*)tbl && p2 != 1) {
        return 0;
    }

    struct Entry_02028bd0* entry = FindInlineEntryById(entryBase, p0->field0);
    out->field4 = entry;
    if (entry == 0) return 0;

    int idx = 112 + entry->field2 * 12 + p0->field3;
    out->field0 = idx;
    GameObject* combatant = bs->GetMaybeFieldMonsterByIndex(idx);
    out->field8 = combatant;
    if (combatant == 0) return 0;

    int state = *(int*)((char*)combatant + 0x130);
    if (state == 8) return 0;
    if (state == 9) return 0;
    return 1;
}
