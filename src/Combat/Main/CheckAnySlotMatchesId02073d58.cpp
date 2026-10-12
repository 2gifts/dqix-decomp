#include <globaldefs.h>

#if defined(jpn)
#define CheckAnySlotMatchesId02073d58 func_02074ee4
enum { EntryListOffset = 0x14 };
#else
enum { EntryListOffset = 0x18 };
#endif
#include "GameState/GameState.h"

extern "C" int _ZNK8Object3D9IsVisibleEv(unsigned char* obj);
struct List_02028430;
struct ListEntry_02028430;
ListEntry_02028430* GetListEntryChecked(List_02028430* list, int index);

struct KindField02073d58 {
    unsigned short kind : 2;
    unsigned short pad : 14;
};

#if defined(jpn)
extern "C" ARM int CheckAnySlotMatchesId02073d58(int a, void* b, int c);
#endif

// USA: func_02073d58
ARM int CheckAnySlotMatchesId02073d58(int a, void* b, int c) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 0xc; i++) {
        int kind = ((struct KindField02073d58*)((char*)b + 2))->kind;
        int tmp = kind * 12 + 0x70;
        int id = i + tmp;
        if (c != -1 && id == c) continue;
        GameObject* combatant = bs->GetMaybeWanderingMonsterByIndex(id);
        if (!combatant) continue;
        if (!_ZNK8Object3D9IsVisibleEv((unsigned char*)combatant)) continue;
        unsigned short field_b8 = *(unsigned short*)((char*)combatant + 0xb8);
        ListEntry_02028430* entry = GetListEntryChecked((List_02028430*)((char*)b + EntryListOffset), field_b8);
        if (!entry) continue;
        if (*(unsigned char*)entry == a) return 1;
    }
    return 0;
}
