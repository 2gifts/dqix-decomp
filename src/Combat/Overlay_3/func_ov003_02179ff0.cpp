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

void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" short _Z26FindMappedMemberId02080468Pvi(void* obj, int id);
extern "C" unsigned char _Z20GetTableByte0207ca94i(int index);
extern "C" short _Z28CountPositiveEntries0207c638Pvj(void* base, unsigned int index);
extern "C" int _Z28FindNthPositiveShort0207c6b8Phji(unsigned char* obj, unsigned int index, int target);
struct S_a0b8c;
extern "C" int _Z26CountNonZeroValues020a0b8cP7S_a0b8c(struct S_a0b8c* p);

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

// JPN: func_ov003_02178e20
// USA: func_ov003_02179ff0
extern "C" ARM void func_ov003_02179ff0(ListMenu_02179ff0* menu) {
    void* memberMap = menu->memberMap;
    unsigned char* list = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance());
    if (menu->mode == 0x77) {
        short tableIndex = menu->tableCursor - _Z26FindMappedMemberId02080468Pvi(memberMap, 0x1d);
        unsigned int table =_Z20GetTableByte0207ca94i(tableIndex);
        int count = _Z28CountPositiveEntries0207c638Pvj(list + 0x1d4, table);
        short row = menu->cursor - _Z26FindMappedMemberId02080468Pvi(memberMap, 0x1e);
        short sel = row + menu->page * 5;
        if (count <= sel) sel = count - 1;
        menu->selectedId = _Z28FindNthPositiveShort0207c6b8Phji(list + 0x1d4, table, sel);
        menu->cursor = sel % 5 + _Z26FindMappedMemberId02080468Pvi(memberMap, 0x1e);
    } else {
        int count = _Z26CountNonZeroValues020a0b8cP7S_a0b8c((struct S_a0b8c*)list);
        short row = menu->cursor - _Z26FindMappedMemberId02080468Pvi(memberMap, 0x16);
        short sel = row + menu->page * 8;
        if (count <= sel) sel = count - 1;
        menu->selectedId = ((short*)(list + 0xc))[sel];
        menu->cursor = sel % 8 + _Z26FindMappedMemberId02080468Pvi(memberMap, 0x16);
    }
}
