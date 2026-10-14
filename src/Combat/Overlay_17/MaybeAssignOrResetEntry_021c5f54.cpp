#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);

void* GetData02108ea8(void);

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
Entry0207d9bc* FindEntryByHalfword(Entry0207d9bc* arr, unsigned short key);
int CheckEntryBytes0207d978(Entry0207d9bc* arr, unsigned short key);
int HasActiveEntryForId(unsigned char* arr, int id, int offset);

GameObject* FindCombatantByField16a_021a278c(void* unused, int val);

void MaybeResetEntry_021c5e28(int id, int val);

extern "C" void func_0207d7f4(Entry0207d9bc* arr, unsigned short key, int a, unsigned char b, int c, unsigned short d, int e);
extern "C" void func_0207dcf0(int a);

struct Info021c5f54 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fieldA;
};

// USA: func_ov017_021c5f54  (semantic: MaybeAssignOrResetEntry_021c5f54)
extern "C" ARM void func_ov017_021c5f54(int a, Info021c5f54* info, int unused, void* combatant, SearchStruct0202c1a4* search) {
    Entry0207d9bc* arr;
    if (GetSearchStructCurrentArrEntry(search) != 0)
        return;
    arr = (Entry0207d9bc*)GetData02108ea8();
    if (info->field9 == 0 && info->fieldA == 0
        && FindCombatantByField16a_021a278c(combatant, info->field4) == NULL
        && FindEntryByHalfword(arr, info->field4) == NULL) {
        ((void(*)(int, unsigned short))MaybeResetEntry_021c5e28)(a, info->field4);
        return;
    }
    if (CheckEntryBytes0207d978(arr, info->field4))
        return;
    if (HasActiveEntryForId((unsigned char*)arr, info->field4, a))
        return;
    func_0207d7f4(arr, info->field4, a, info->field8, -1, info->field6, 0);
    func_0207dcf0(info->field4);
}
