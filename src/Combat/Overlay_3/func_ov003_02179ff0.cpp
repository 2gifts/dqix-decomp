#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
enum { kRegion8a0 = 0x81c };
enum { kRegion100c = 0xf88 };
enum { kRegion1016 = 0xf92 };
enum { kRegion103a = 0xfb6 };
#else
enum { kRegion89c = 0x89c };
enum { kRegion8a0 = 0x8a0 };
enum { kRegion100c = 0x100c };
enum { kRegion1016 = 0x1016 };
enum { kRegion103a = 0x103a };
#endif
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
short FindMappedMemberId02080468(void* obj, int id);
unsigned char GetTableByte0207ca94(int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
int FindNthPositiveShort0207c6b8(unsigned char* obj, unsigned int index, int target);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

struct ListMenu_02179ff0 {
    unsigned char pad0[kRegion89c];
    void* memberMap;
    unsigned char pad8a0[kRegion100c - kRegion8a0];
    short mode;
    short cursor;
    short field_0x1010;
    short tableCursor;
    short page;
    unsigned char pad1016[kRegion103a - kRegion1016];
    short selectedId;
};

// USA: func_ov003_02179ff0
extern "C" ARM void func_ov003_02179ff0(ListMenu_02179ff0* menu) {
    void* memberMap = menu->memberMap;
    unsigned char* list = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    if (menu->mode == 0x77) {
        short tableIndex = menu->tableCursor - FindMappedMemberId02080468(memberMap, 0x1d);
        unsigned int table =GetTableByte0207ca94(tableIndex);
        int count = CountPositiveEntries0207c638(list + 0x1d4, table);
        short row = menu->cursor - FindMappedMemberId02080468(memberMap, 0x1e);
        short sel = row + menu->page * 5;
        if (count <= sel) sel = count - 1;
        menu->selectedId = FindNthPositiveShort0207c6b8(list + 0x1d4, table, sel);
        menu->cursor = sel % 5 + FindMappedMemberId02080468(memberMap, 0x1e);
    } else {
        int count = CountNonZeroValues020a0b8c((struct S_a0b8c*)list);
        short row = menu->cursor - FindMappedMemberId02080468(memberMap, 0x16);
        short sel = row + menu->page * 8;
        if (count <= sel) sel = count - 1;
        menu->selectedId = ((short*)(list + 0xc))[sel];
        menu->cursor = sel % 8 + FindMappedMemberId02080468(memberMap, 0x16);
    }
}
