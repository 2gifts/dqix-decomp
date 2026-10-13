#include <globaldefs.h>

#if defined(jpn)
#define CheckAnySlotMatchesId02073d58 func_02074ee4
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif
#include "GameState/GameState.h"

struct List_02028430;
struct ListEntry_02028430;
ListEntry_02028430* GetListEntryChecked(List_02028430* list, int index);

struct KindField02073d58 {
    unsigned short kind : 2;
    unsigned short pad : 14;
};

#if defined(jpn)
extern "C" ARM int CheckAnySlotMatchesId02073d58(int entryId, void* spawnGroup, int excludedMonsterId);
#endif

// USA: func_02073d58
ARM int CheckAnySlotMatchesId02073d58(int entryId, void* spawnGroup, int excludedMonsterId) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 0xc; i++) {
        int kind = ((struct KindField02073d58*)((char*)spawnGroup + 2))->kind;
        int groupFirstMonster = kind * 12 + 0x70;
        int id = i + groupFirstMonster;
        if (excludedMonsterId != -1 && id == excludedMonsterId) continue;
        GameObject* combatant = bs->GetMaybeWanderingMonsterByIndex(id);
        if (!combatant) continue;
        if (!combatant->obj3D_.IsVisible()) continue;
        unsigned short field_b8 = *reinterpret_cast<unsigned short*>(&combatant->unk_ac[0xb8 - 0xac]);
        ListEntry_02028430* entry = GetListEntryChecked((List_02028430*)((char*)spawnGroup + EntryListOffset), field_b8);
        if (!entry) continue;
        if (*(unsigned char*)entry == entryId) return 1;
    }
    return 0;
}
